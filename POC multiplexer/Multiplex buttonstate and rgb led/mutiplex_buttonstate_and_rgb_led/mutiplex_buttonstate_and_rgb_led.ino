#include "MUX74HC4067.h"
MUX74HC4067 mux(7, 8, 9, 10, 11);

int state = HIGH;
int state1 = HIGH;
int state2 = HIGH;
int state3 = HIGH;

int redPin = 4;
int greenPin = 5;
int bluePin = 6;
int redPin1 = 50;
int greenPin1 = 51;
int bluePin1 = 52;
int redPin2 = 49;
int greenPin2 = 48;
int bluePin2 = 47;
int redPin3 = 46;
int greenPin3 = 45;
int bluePin3 = 44;

void setup()
{
  Serial.begin(9600);  // Initializes serial port
  while ( !Serial ) ;
  
  mux.signalPin(3, INPUT, DIGITAL);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(bluePin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(bluePin2, OUTPUT);
  pinMode(redPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(bluePin3, OUTPUT); 
}

void loop()
{
  byte data;

  for (byte i = 0; i < 4; ++i) // < X, X = amount of channels
  {
    data = mux.read(i);

    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if ( data == HIGH ) Serial.println("not pressed");
    else if (i == 0 && state == HIGH) {
      Serial.println("pressed ");
      state = LOW;
      setColor(255, 0, 0); // blue
      Serial.print("button ");
      Serial.print(0);
      Serial.println(" = on");
    }
    else if (i == 0 && state == LOW) {
      Serial.println("pressed ");
      state = HIGH;
      setColor(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(0);
      Serial.println(" = off");
        }
    else if (i == 1 && state1 == HIGH){
      Serial.println("pressed ");
      state1 = LOW;
      setColor1(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(1);
      Serial.println(" = on");
    }
    else if (i == 1 && state1 == LOW){
      Serial.println("pressed ");
      state1 = HIGH;
      setColor1(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(1);
      Serial.println(" = off");
    }
    else if (i == 2 && state2 == HIGH){
      Serial.println("pressed ");
      state2 = LOW;
      setColor2(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(2);
      Serial.println(" = on");
    }
    else if (i == 2 && state2 == LOW){
      Serial.println("pressed ");
      state2 = HIGH;
      setColor2(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(2);
      Serial.println(" = off");
    }
    else if (i == 3 && state3 == HIGH){
      Serial.println("pressed ");
      state3 = LOW;
      setColor3(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(3);
      Serial.println(" = on");
    }
    else if (i == 3 && state3 == LOW){
      Serial.println("pressed ");
      state3 = HIGH;
      setColor3(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(3);
      Serial.println(" = off");
    }
        
}
delay(125);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
void setColor1(int red, int green, int blue)
{
  digitalWrite(redPin1, red);
  digitalWrite(greenPin1, green);
  digitalWrite(bluePin1, blue);  
}

void setColor2(int red, int green, int blue)
{
  digitalWrite(redPin2, red);
  digitalWrite(greenPin2, green);
  digitalWrite(bluePin2, blue);
}

void setColor3(int red, int green, int blue)
{
  digitalWrite(redPin3, red);
  digitalWrite(greenPin3, green);
  digitalWrite(bluePin3, blue);
}
