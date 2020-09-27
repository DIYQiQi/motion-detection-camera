// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int LED = 14;    // led
int sensor_pin = 8; // PIN P2.0
int mode_pin = 10;	// PIN P2.2
int prev_state = 0;

void setup() 
{ 
  pinMode(sensor_pin, INPUT);
  pinMode(mode_pin, INPUT);
  pinMode(LED, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9(P2.1) to the servo object 
  myservo.write(0);
} 

void loop() 
{ 

  int curr_state = digitalRead(sensor_pin);
  if (curr_state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  
  int mode = digitalRead(mode_pin);
  if (mode == 1) {
	  // click to start or stop recording video
	  if (prev_state != curr_state) {
			myservo.write(20);
			delay(500);
			myservo.write(5);
	  }  
  } else if (curr_state == 1) {
		// click to take photo
		myservo.write(20);
		delay(500);
		myservo.write(5);
  }
  
  prev_state = curr_state;
  delay(1000);
  
} 
