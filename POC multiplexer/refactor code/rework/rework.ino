#include "MUX74HC4067.h"
MUX74HC4067 mux(7, 8, 9, 10, 11);

// HIGH (1) or LOW(0) setting for each channel on the multiplexer, number of elements depends on the amount of channels you want to use.
// current amount: 8
int state[] = {
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1}; 

// multidimensional array of all the differende leds[x][], and their 
int led[][3] = {
  {4, 5, 6},
  {50, 51, 52},
  {49, 48, 47},
  {46, 45, 44},
  {43, 42, 41},
  {40, 39, 38},
  {37, 36, 35},
  {34, 33, 32},
};

void setup()
{
  Serial.begin(9600);  // Initializes serial port
  while ( !Serial ) ;
  
  mux.signalPin(3, INPUT, DIGITAL);

// set each array element's to OUTPUT
  //main array of led[X][]
  for ( int i = 0; i < sizeof(led) / sizeof(led[i]); i++ ){
    //sub array of led[][X]
    for ( int j = 0; j < sizeof(led[i]) / sizeof(int); j++ ) {
      pinMode(led[i][j], OUTPUT);
      }
   }
}

void loop()
{
  byte data;

  for (byte i = 0; i < 8; ++i) // < X, X = amount of channels
  {    
    data = mux.read(i);

    //for loop to count the length of the array. For proper handling we devide it by the sizeof(int) which is 2.
    //Otherwise you get your array in double the size because of the double digits within INT.
    for(int j = 0; j < sizeof(state) / sizeof(int); j++)
    {
      Serial.print(state[j]);
    }
    Serial.println();
    
    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if ( data == HIGH ) Serial.println("not pressed");
    else if (state[i] == HIGH) {
      Serial.println("pressed ");
      state[i] = LOW;
      setColor(255, 0, 0, led[i]); // red
      Serial.print("button ");
      Serial.print(i);
      Serial.println(" = on");
      // send array to Node.js
    }
    else if (state[i] == LOW) {
      Serial.println("pressed ");
      state[i] = HIGH;
      setColor(0, 0, 0, led[i]); // off
      Serial.print("button ");
      Serial.print(i);
      Serial.println(" = off");
      // send array to Node.js
      }
}
}

void setColor(int red, int green, int blue, int led[])
{
  digitalWrite(led[0], red);
  digitalWrite(led[1], green);
  digitalWrite(led[2], blue);  
}
