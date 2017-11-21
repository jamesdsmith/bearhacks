/*                BEARHACKS LIGHT FOLLOWING CAR                 *
 *   This base code is meant to operate the light following car *
 *      defined in the PDF                                      *
 *   The car calibrates to room light at the beginning of the   *
 *      program. This process takes about 1 second. During this *
 *      time, place the car in even lighting!!!!                */

// We define constants for the pins in the PDF layout.
#define L_MOTOR P1_3
#define R_MOTOR P2_0
#define R_ENCODER P1_2
#define L_ENCODER P2_5

/* The photoresistors are not in the spec for pins so we will define them here. *
 * Keep in mind that these pins must have the ability to read Analog signals.   *
 * These appear blue in the pin map provided on the http://energia.nu website.  */
#define L_LIGHT P6_0
#define R_LIGHT P6_1

// Redefine this value to adjust for how bright the light source needs to be to 
//    activate the car!
const static int LIGHT_THRESHOLD = 50;
// Base motor speed (Do not put this over 127).
const static int BASE_SPEED = 75;
// This is the speed of the motors as we rotate in place.
const static int SPIN_SPEED = 50;

// We define global tick counts for our encoders.
int left_tick = 0;
int right_tick = 0;

// We define this for the ambient light level in the room.
int ambient_left = 0;
int ambient_right = 0;
int ambient_ave;

/* The code in setup runs only once */
void setup() {
  // We configure the motor pins as outputs.
  pinMode(L_MOTOR, OUTPUT);
  pinMode(R_MOTOR, OUTPUT);

  // All the rest of our pins are inputs to our system!
  pinMode(L_ENCODER, INPUT);
  pinMode(R_ENCODER, INPUT);
  pinMode(L_LIGHT, INPUT);
  pinMode(R_LIGHT, INPUT);

  // Take 10 samples for each light sensor.
  for (int i = 0; i < 10; i++) {
    delay(100);
    ambient_left += analogRead(L_LIGHT);
    ambient_right += analogRead(R_LIGHT);
  }

  // Average the values.
  ambient_left  /= 10;
  ambient_right /= 10;
  ambient_ave = (ambient_left + ambient_right) / 2;

  // For debugging purposes, we will enable Serial output.
  Serial.begin(9600);

  // We configure the encoder pins as interrupt based inputs.
  attachInterrupt(L_ENCODER, _L_ENC_ISR, CHANGE);
  attachInterrupt(R_ENCODER, _R_ENC_ISR, CHANGE);
}

/* The code in loop runs indefinitely though it is paused when an interrupt triggers */
void loop() {
  drive();
  Serial.println("Left Ticks: " + left_tick);
  Serial.println("Right Ticks: " + right_tick);
}

void drive() {
  // We first read in the current light values from each of the sensors and offset by ambient.
  int left_light = analogRead(L_LIGHT) - ambient_left;
  int right_light = analogRead(R_LIGHT) - ambient_right;

  /* Next, we take the difference. If this number is positive that means that we need *
   * to drive left as the light is brighter there!                                    */
  int diff_light = left_light - right_light;
  if (abs(diff_light) > LIGHT_THRESHOLD)
  {
    // This function is defined here https://www.arduino.cc/reference/en/language/functions/math/map/
    int mapped_diff_to_speed = map(diff_light, -1024 + ambient_ave, 1024 - ambient_ave, -BASE_SPEED, BASE_SPEED);
    analogWrite(L_MOTOR, BASE_SPEED - mapped_diff_to_speed);
    analogWrite(R_MOTOR, BASE_SPEED + mapped_diff_to_speed);
  }
  // If we don't find a light, just spin with one wheel so the car rotates until 
  //    it finds the light source.
  else
  {
    analogWrite(L_MOTOR, SPIN_SPEED);
  }
}

// Interrupt for left encoder.
void _L_ENC_ISR() {
  left_tick++;
}

// Interrupt for right encoder.
void _R_ENC_ISR() {
  right_tick++;
}
