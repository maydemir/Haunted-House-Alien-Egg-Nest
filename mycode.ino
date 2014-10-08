/*
  Calibration
 
 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.
 
 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything 
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.
 
 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground
 
 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Calibration
 
 This example code is in the public domain.
 
 */

// These constants won't change:
const int sensorPin = A0;    // pin that the sensor is attached to
const int ledPin = 12;        // pin that the LED is attached to

// variables:
int sensorValue = 0;         // the sensor value
//int sensorMin = 1023;        // minimum sensor value
//int sensorMax = 0;           // maximum sensor value
boolean lightBlink = false;//Should we blink?
boolean lightOn = true;//If we're blinking, should we be on or off?
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards

void setup() {

// the loop function runs over and over again forever

  //digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(500);              // wait for a second
  //digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  //delay(500);              // wait for a second
  pinMode(12, OUTPUT);
  //digitalWrite(12, HIGH);
  
  Serial.begin(9600);

  // calibrate during the first five seconds 
  /*while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }
     

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
     
  }*/
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
   myservo.write(0);              // tell servo to go to position in 0 to 90 
   

  // signal the end of the calibration period
  //digitalWrite(12, HIGH);
}

void loop() {
  // read the sensor:
  sensorValue = analogRead(sensorPin);
  

  Serial.println(sensorValue);
  
  if (sensorValue > 400){
    lightBlink = true;//If light is high, start blinking
    myservo.write(90); }  //tell servo to go to position in 0 to 90
    
    if ( sensorValue < 420){
    //digitalWrite(12, LOW);
     myservo.write(0);  } //tell servo to go to position in 90 to 0
     
     
     if (lightBlink) {//If we should be blinking, start blinking
       if(lightOn) { //If lights should be on
         digitalWrite(12, HIGH);//Turn on
         lightOn = false;//Next time through the loop, turn light off
       }else{
         digitalWrite(12, LOW);//Turn off
         lightOn = true;//Next time through the loop, turn light on
       }
       
     }else {
       digitalWrite(12, LOW);//Turn off lights
     }
     
     delay(60);//Increase to slow down blinking
}
    
    
   
