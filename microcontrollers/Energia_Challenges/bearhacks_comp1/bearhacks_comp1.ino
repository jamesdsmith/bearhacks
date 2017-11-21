/*******************************************************
*                 Comp 1: Blinking an LED              *
*     We will be using digital write to blink an LED   *
********************************************************/

/***********Define your global variables here***********/

//Sets the LED pin to pin 19 on the MSP
//This variable will be the LED pin
int LED_PIN = P2_0;

//This variable sets the time between blinks
//Change this value to make the LED blink faster or slower
int time_delay = 1000;          


void setup()
{
  // Lets do your setup code:
  // Set the LED pin to be in OUTPUT mode
  // You should use the function pinMode([PIN], [mode]) tp do this
  // Note that the LED pin is already defined for you in a variable
  
  // Your code here:
  
}

void loop()
{
  // Now we will do the loop code: 
  // This function automatically loops infinitely for you. This means that the code here will run repeatedly.
  // We would like to blink the LED. In order to do that you must turn the pin value to low which will turn the LED on. 
  // You should use the function digitalWrite([PIN], [value]) to do this.
  // Then we would like to pause for some number of milliseconds, this number is defined in your time_delay variable above. 
  // To pause the program, use the delay([time]) function.
  // We would now like to now turn the pin value to high which will turn the LED off. 
  // You should use the function digitalWrite([PIN], [value]) to do this.
  // Finally, we want to pause again for a time_delay amount of time. 
  
  // Your code here:
  
  
  
}
