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

int buttonPressed[32];


int red;

int current = HIGH;      // the current state of the output pin
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
unsigned long time = 0;           // the last time the output pin was toggled
unsigned long debounce = 200UL;   // the debounce time, increase if the output flickers


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

   for (int i = 0; i <= 31; i++){
  buttonPressed[i] = 0;
}
}

void loop()
{
  byte data;

  for (byte i = 0; i < 8; ++i) // < X, X = amount of channels
  {    
    data = mux.read(i);
    
    if ( data == LOW ) {
      // measuring of each individual button press (Holding down the button prevents spamming)
      if(!buttonPressed[i]){
        //invert the states (LOW to HIGH and visaversa)
        state[i] = !state[i];
        if(state[i] == LOW){
          red = 255;
        } else {
          red = 0;
        }
        setColor(red, 0, 0, led[i]); // red
  
        //for loop to count the length of the array. For proper handling we devide it by the sizeof(int) which is 2.
        //Otherwise you get your array in double the size because of the double digits within INT.
        for(int j = 0; j < sizeof(state) / sizeof(int); j++) {
          Serial.print(state[j]);
        }
          buttonPressed[i] = 1;
      } 
    } else {
          if(data == HIGH) {
            buttonPressed[i] = 0;
          }
      }
  }
}

void setColor(int red, int green, int blue, int led[])
{
  digitalWrite(led[0], red);
  digitalWrite(led[1], green);
  digitalWrite(led[2], blue);  
}

void buttonState()
{
  reading = digitalRead(3);

  // if the input just went from LOW and HIGH and has been released...
  if (reading == HIGH && previous == LOW && millis() - time > debounce)
  {
    if (current == HIGH)
      current = LOW;
    else
      current = HIGH;

    time = millis();
  }
  previous = reading;
}
