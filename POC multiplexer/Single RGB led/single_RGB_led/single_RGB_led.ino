/**
 * This example demonstrates how to read digital signals
 * It assumes there are push buttons with pullup resistors
 * connected to the 16 channels of the 74HC4067 mux/demux
 * 
 * For more about the interface of the library go to
 * https://github.com/pAIgn10/MUX74HC4067
 */

#include "MUX74HC4067.h"

// Creates a MUX74HC4067 instance
// 1st argument is the Arduino PIN to which the EN pin connects
// 2nd-5th arguments are the Arduino PINs to which the S0-S3 pins connect
MUX74HC4067 mux(7, 8, 9, 10, 11);

    int redPin = 4;
    int greenPin = 5;
    int bluePin = 6;


void setup()
{
  Serial.begin(9600);  // Initializes serial port
    // Waits for serial port to connect. Needed for Leonardo only
    while ( !Serial ) ;
  
  // Configures how the SIG pin will be interfaced
  // e.g. The SIG pin connects to PIN 3 on the Arduino,
  //      and PIN 3 is a digital input
  mux.signalPin(3, INPUT, DIGITAL);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT); 
}

// Reads the 16 channels and reports on the serial monitor
// if the corresponding push button is pressed
void loop()
{
  byte data;

  for (byte i = 0; i < 4; ++i) // < X, X = amount of channels
  {
    // Reads from channel i and returns HIGH or LOW
    data = mux.read(i);

    Serial.print("Push button at channel ");
    Serial.print(i);
    Serial.print(" is ");
    if ( data == HIGH ) Serial.println("not pressed");
    else Serial.println("pressed");
    
    if (i == 0 && data == LOW)  // red
    {
      setColor(255, 0, 0);
      Serial.print("red");
    }
    if (i == 1 && data == LOW) setColor(0, 255, 0);  // green
    if (i == 2 && data == LOW) setColor(0, 0, 255);  // blue
    if (i == 3 && data == LOW) setColor(80, 0, 80);  // purple
    
  }
  Serial.println();
  
  delay(1500);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
