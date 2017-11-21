int LEDidx[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int LEDidy[8] = {0, 0, 0, 0, 0, 0, 0, 0};
// x values will be grounded (low)
// y values will be supplying current (high)

void setup()
{
  // put your setup code here, to run once:
  // DO NOT CHANGE
  for (int x = 23; x < 39; x++) {
    pinMode(x, OUTPUT);
  }
  LEDidx[0] = 34;
  LEDidx[1] = 28;
  LEDidx[2] = 27;
  LEDidx[3] = 37;
  LEDidx[4] = 25;
  LEDidx[5] = 36;
  LEDidx[6] = 32;
  LEDidx[7] = 31;
  
  LEDidy[0] = 26;
  LEDidy[1] = 29;
  LEDidy[2] = 24;
  LEDidy[3] = 30;
  LEDidy[4] = 35;
  LEDidy[5] = 23;
  LEDidy[6] = 33;
  LEDidy[7] = 38;
}

void light(int x, int y) { 
  // LIGHTS INDIVIDUAL LED
  digitalWrite(LEDidx[x], LOW);
  digitalWrite(LEDidy[y], HIGH);
}

void off() {
  // TURNS OFF ALL LEDS
  for (int y = 0; y < 8; y++) {
    digitalWrite(LEDidx[y], HIGH);
    digitalWrite(LEDidy[y], LOW);
  }
}

void select(int x[], int y[], int t, int ARRSIZE) {
  // input the coordinates of the pixels you want to light and 
  // a delay time in ms, and the number of points you're inputting
  // top left is 0, 0
  // increasing x will move from right to left
  // increasing y will move from top to bottom
  // example input: select([0, 0, 7, 7], [0, 7, 0, 7], 5)
  // this should light up the four corners
  // x and y must be equal length arrays
  if (sizeof(x) == sizeof(y)) {
    for (int i = 0; i < ARRSIZE; i++) {
      light(x[i], y[i]);
      delay(t);
      off();
    }
  }
  
}


void loop()
{
  // put your main code here, to run repeatedly:
  // UNCOMMENT BLOCKS INDIVIDUALLY TO SEE SOME DEMOS
  // UNCOMMENT BY REMOVING THE /* AND */ BEFORE AND AFTER THE BLOCK
  /* 
  // BLOCK ONE - LIGHT MOVES ACROSS MATRIX, ROW BY ROW
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      light(x, y);
      delay(100);
      off();
    }
  } 
  // END OF BLOCK ONE
  */ 
  /* 
  // BLOCK TWO - SOME RANDOM POINTS ARE LIT
  int x[] = {0, 4, 1, 2, 5};
  int y[] = {0, 1, 3, 6, 7};
  select(x, y, 1, 5);
  // END OF BLOCK TWO
  */
  /* 
  // BLOCK THREE - A BOX IS LIT
  int zeros[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int sevens[] = {7, 7, 7, 7, 7, 7, 7, 7};
  int across[] = {0, 1, 2, 3, 4, 5, 6, 7};
  select(zeros, across, 0.3, 8);
  select(sevens, across, 0.3, 8);
  select(across, zeros, 0.3, 8);
  select(across, sevens, 0.3, 8);
  // END OF BLOCK THREE
  */ 
  /* 
  // BLOCK FOUR - DIAGONALS ARE LIT
  for (int i = 0; i < 8; i++) {
    light(i, i);
    delay(1);
    off();
  }
  // END OF BLOCK FOUR
  */

}
