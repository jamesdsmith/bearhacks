/*****************************************************************
*                 Lab 4: Using the buzzer                        *
*           We will be changing the frequency of a               *
*            square wave to make the buzzer buzz                  *
*****************************************************************/

//This variable will be the BUZZER Pin 
int BUZZER_PIN = 12;

void setup()
{
  //Lets do some setup code:
  //Set the BUZZER pin to be in output mode
  //Use the function pinMode([PIN]). Note that the pin is 
  //already declared for you in a variable
  
  //Your code here:
  
}

void loop()
{
  /*In order to make the buzzer buzz, we need to write a square wave to the
  output. However this time we will need to change the frequency of the square
  wave in order to change the tone generated. In order to do this we will use
  the tone() function. The function generates a square wave at a certain 
  frequency. Now we need to keep to keep track of the current frequency.
  Each iteration of the loop, we will set the buzzer to a certain frequency and
  wait for a few hundred milliseconds. Finally this loop will be repeated by the
  loop function while the MSP is on. */
  //First lets create an integer variable called curr_freq and initialize it 
  //with the value of 440. 
  //A variable is declared using the following format: 
  //int [variable name] = [Initial value]
  
  //Your code here:
  
  
  //This sets up a for loop
  for (curr_freq = 440; curr_freq <= 880; curr_freq+=40) {
    
    //Now let's write the Tone to the MSP using the function tone
    //tone([PIN],[FREQUENCY])
    
    //Your code here:
    
    
    //Now we will pause for a bit
    //Use the function delay([Time]). Note that time is in milliseconds
    
    //Your code here:
    

    //Finally, we need to call noTone() so we can call the next tone
    //noTone([PIN])

    //Your code here:

    
  }
}
