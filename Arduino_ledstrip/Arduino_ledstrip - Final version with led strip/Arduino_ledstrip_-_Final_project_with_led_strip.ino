#include "MUX74HC4067.h"
#include <FastLED.h>
MUX74HC4067 mux(7, 8, 9, 10, 11);

#define LED_PIN 23
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

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

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  mux.signalPin(3, INPUT, DIGITAL);

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
        //setColor(red, 0, 0, led[i]); // red
        leds[i] = CRGB(red, 0, 0);
        FastLED.show();
  
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
