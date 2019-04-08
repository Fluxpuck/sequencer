#include "MUX74HC4067.h"
MUX74HC4067 mux(7, 8, 9, 10, 11);

int state = HIGH;
int reading;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

void setup()
{
  Serial.begin(9600);  // Initializes serial port
    while ( !Serial ) ;
  
  mux.signalPin(3, INPUT, DIGITAL);
}

void loop()
{
  byte data;

  for (byte i = 0; i < 1; ++i) // < X, X = amount of channels
  {
    data = mux.read(i);

    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if ( data == HIGH ) Serial.println("not pressed");
    else Serial.println("pressed ");

    reading = data;
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading == HIGH && previous == LOW && millis() - time > debounce) {
    if (state == HIGH) {
      state = LOW;
      Serial.print("button ");
      Serial.print(i);
      Serial.println(" = on");
    }
    else {
      state = HIGH;
      Serial.print("button ");
      Serial.print(i);
      Serial.println(" = off");
    }

    time = millis();    
  }
  previous = reading;
}
    
  
  delay(1500);
}
