#include "MUX74HC4067.h"
MUX74HC4067 mux(7, 8, 9, 10, 11);

int state = HIGH;
int state1 = HIGH;
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

  for (byte i = 0; i < 2; ++i) // < X, X = amount of channels
  {
    data = mux.read(i);

    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if ( data == HIGH ) Serial.println("not pressed");
    else if (i == 0 && state == HIGH) {
      Serial.println("pressed ");
      state = LOW;
      Serial.print("button ");
      Serial.print(0);
      Serial.println(" = on");
    }
    else if (i == 0 && state == LOW) {
      Serial.println("pressed ");
      state = HIGH;
      Serial.print("button ");
      Serial.print(0);
      Serial.println(" = off");
        }
    else if (i == 1 && state1 == HIGH){
      Serial.println("pressed ");
      state1 = LOW;
      Serial.print("button ");
      Serial.print(1);
      Serial.println(" = on");
    }
    else if (i == 1 && state1 == LOW){
      Serial.println("pressed ");
      state1 = HIGH;
      Serial.print("button ");
      Serial.print(1);
      Serial.println(" = off");
    }
        
}
    
  
  delay(1500);
}
