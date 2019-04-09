#include "MUX74HC4067.h"
MUX74HC4067 mux(7, 8, 9, 10, 11);


int state[] = {1, 1, 1, 1, 1, 1, 1, 1}; // HIGH (1) or LOW(0) setting for each channel on the multiplexer, depends on the amount of channels you want to use.

// All the input pins you using for the RGB leds
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
int redPin4 = 43;
int greenPin4 = 42;
int bluePin4 = 41;
int redPin5 = 40;
int greenPin5 = 39;
int bluePin5 = 38;
int redPin6 = 37;
int greenPin6 = 36;
int bluePin6 = 35;
int redPin7 = 34;
int greenPin7 = 33;
int bluePin7 = 32;

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
  pinMode(redPin4, OUTPUT);
  pinMode(greenPin4, OUTPUT);
  pinMode(bluePin4, OUTPUT); 
  pinMode(redPin5, OUTPUT);
  pinMode(greenPin5, OUTPUT);
  pinMode(bluePin5, OUTPUT); 
  pinMode(redPin6, OUTPUT);
  pinMode(greenPin6, OUTPUT);
  pinMode(bluePin6, OUTPUT); 
  pinMode(redPin7, OUTPUT);
  pinMode(greenPin7, OUTPUT);
  pinMode(bluePin7, OUTPUT); 
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
    else if (i == 0 && state[0] == HIGH) {
      Serial.println("pressed ");
      state[0] = LOW;
      setColor(255, 0, 0); // blue
      Serial.print("button ");
      Serial.print(0);
      Serial.println(" = on");
    }
    else if (i == 0 && state[0] == LOW) {
      Serial.println("pressed ");
      state[0] = HIGH;
      setColor(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(0);
      Serial.println(" = off");
        }
    else if (i == 1 && state[1] == HIGH){
      Serial.println("pressed ");
      state[1] = LOW;
      setColor1(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(1);
      Serial.println(" = on");
    }
    else if (i == 1 && state[1] == LOW){
      Serial.println("pressed ");
      state[1] = HIGH;
      setColor1(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(1);
      Serial.println(" = off");
    }
    else if (i == 2 && state[2] == HIGH){
      Serial.println("pressed ");
      state[2] = LOW;
      setColor2(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(2);
      Serial.println(" = on");
    }
    else if (i == 2 && state[2] == LOW){
      Serial.println("pressed ");
      state[2] = HIGH;
      setColor2(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(2);
      Serial.println(" = off");
    }
    else if (i == 3 && state[3] == HIGH){
      Serial.println("pressed ");
      state[3] = LOW;
      setColor3(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(3);
      Serial.println(" = on");
    }
    else if (i == 3 && state[3] == LOW){
      Serial.println("pressed ");
      state[3] = HIGH;
      setColor3(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(3);
      Serial.println(" = off");
    }
    else if (i == 4 && state[4] == HIGH){
      Serial.println("pressed ");
      state[4] = LOW;
      setColor4(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(4);
      Serial.println(" = on");
    }
    else if (i == 4 && state[4] == LOW){
      Serial.println("pressed ");
      state[4] = HIGH;
      setColor4(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(4);
      Serial.println(" = off");
    }
    else if (i == 5 && state[5] == HIGH){
      Serial.println("pressed ");
      state[5] = LOW;
      setColor5(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(5);
      Serial.println(" = on");
    }
    else if (i == 5 && state[5] == LOW){
      Serial.println("pressed ");
      state[5] = HIGH;
      setColor5(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(5);
      Serial.println(" = off");
    }
    else if (i == 6 && state[6] == HIGH){
      Serial.println("pressed ");
      state[6] = LOW;
      setColor6(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(6);
      Serial.println(" = on");
    }
    else if (i == 6 && state[6] == LOW){
      Serial.println("pressed ");
      state[6] = HIGH;
      setColor6(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(6);
      Serial.println(" = off");
    }
    else if (i == 7 && state[7] == HIGH){
      Serial.println("pressed ");
      state[7] = LOW;
      setColor7(255, 0, 0); // red
      Serial.print("button ");
      Serial.print(7);
      Serial.println(" = on");
    }
    else if (i == 7 && state[7] == LOW){
      Serial.println("pressed ");
      state[7] = HIGH;
      setColor7(0, 0, 0); // off
      Serial.print("button ");
      Serial.print(7);
      Serial.println(" = off");
    }
        
}
delay(1500);
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
void setColor4(int red, int green, int blue)
{
  digitalWrite(redPin4, red);
  digitalWrite(greenPin4, green);
  digitalWrite(bluePin4, blue);
}
void setColor5(int red, int green, int blue)
{
  digitalWrite(redPin5, red);
  digitalWrite(greenPin5, green);
  digitalWrite(bluePin5, blue);
}
void setColor6(int red, int green, int blue)
{
  digitalWrite(redPin6, red);
  digitalWrite(greenPin6, green);
  digitalWrite(bluePin6, blue);
}
void setColor7(int red, int green, int blue)
{
  digitalWrite(redPin7, red);
  digitalWrite(greenPin7, green);
  digitalWrite(bluePin7, blue);
}
