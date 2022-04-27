/*
  Glowing Sailor Hat for Deaf Sailors
*/
 
#include <Adafruit_NeoPixel.h>
 
#define LED_PIN    7
 
#define LED_COUNT 60
 
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
 
 
///////////////START NEW
 
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 8;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
 
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 
void setup() {
  Serial.begin(9600);
  Serial.println("serial is working");
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(30); // Set BRIGHTNESS to about 1/5 (max = 255)
 
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}
 
int globalButtonStateHigh = false;
 
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
 
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH && !globalButtonStateHigh) {
    globalButtonStateHigh = true;
    // turn LED on:
    //digitalWrite(ledPin, HIGH);
    Serial.println("HIGH!");
    colorWipe(strip.Color(  0,   0, 255), 50); // Blue
    delay(2000);
  } else if (buttonState != HIGH && globalButtonStateHigh) {
    globalButtonStateHigh = false;
    // turn LED off:
    //digitalWrite(ledPin, LOW);
    Serial.println("LOW!");
    colorWipe(strip.Color(  0, 255,   0), 50); // Green
  }
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);      
    strip.show();                         
    delay(wait);                           
  }
}