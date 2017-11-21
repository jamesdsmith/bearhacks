int res;

void setup()
{
  // put your setup code here, to run once:
  //initialize A0 as an input pin
  pinMode(A0, INPUT);
  //initialize the serial connection
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:

  //Delay before taking in a reading, taking in readings too quickly can result in inaccuracies in readings
  delay(1);

  //Read in the voltage from pin A0. This value is passed through a ten bit analog to digital converter
  //The converted voltage is on a scale of 0-1023, corresponding to a range of 0 - 3.3 V
  //The microphone's output is centered at ~1.6 V, meaning a constant reading of about 500 will correspond to no sound at the microphone
  //Sound intensity is represented by larger deviations in voltage from the baseline voltage (whether high or low)
  //As an example, a convertedVoltage of either 1023 or 0 would indicate that the microphone is reading in as loud a sound as it can process

  //Note: This reading will change over time, and as sound is a wave, it will not necessarily always output
  //0 or 1023 when the sound level is maxed out (inbetween values may appear)
  convertedVoltage = analogRead(A0);

  //convert back to volts
  volts = (convertedVoltage * 3.3) / 1024;


  //print to serial monitor so you can see it
  serial.println(volts);
}
