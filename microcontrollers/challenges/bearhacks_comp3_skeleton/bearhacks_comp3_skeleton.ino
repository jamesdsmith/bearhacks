/*****************************************************************
*                 Lab 5: Music Player                            *
*      Now we will play music based on the photoresistor input       *
*****************************************************************/

//This variable will be the BUZZER Pin 
int BUZZER_PIN = P2_3;

//This variable will be the photo-resistor input
int PHOTO_RES_PIN = P6_6;

void setup()
{
  //Lets do some setup code:
  //Set the BUZZER pin to be in output mode
  //Set the PHOTO_RES_PIN pin to be in input mode
  //Use the function pinMode([PIN]). Note that the pin is 
  //already declared for you in a variable
  
  //Your code here:
  

  Serial.begin(9600);
}

void loop()
{
  /*Here we will combine the input from the earlier labs to make a music player. 
  We will read the input of the solar cell. Base want to programd on this input, we will play a 
  tone on the BUZZER*/
  //First lets create an integer variable called curr_freq and initialize it 
  //with the value of 440. 
  //A variable is declared using the following format: 
  //int [variable name] = [Initial value]
  
  //Your code here:
  
  
  //Now let's create a variable to read the input from the photocell. Lets call
  //this variable light_in and set it to zero.

  //Your code here:
  
  
  //Now read the input from the photocell and put it in light_in

  //Your code here:


  //analogRead() returns a number between 0 and 1023. We need to scale this number to
  //half that range, then add it to the base frequency of 440Hz. Set curr_freq to 
  //this value

  //Your code here:


  //Finally let's write this tone to the output and delay for a few hundred milliseconds

  //Your code here:


}
