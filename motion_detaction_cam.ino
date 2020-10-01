#include <Servo.h> 

#define MODE_PIN 8
#define SERVO_PIN 9
#define SENSOR_PIN 10
#define LED 14
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
                
int prev_state = 0;
int time_count = 0;

void setup() 
{ 
  pinMode(MODE_PIN, INPUT_PULLUP);	// PIN P2.2
  pinMode(SENSOR_PIN, INPUT);       // sensor input pin(P2.0)
  pinMode(LED, OUTPUT);
  myservo.attach(SERVO_PIN);        // attaches the servo on pin 9(P2.1) to the servo object
  myservo.write(20);
} 

void click_button(){
  myservo.write(5);
  delay(1000);
  myservo.write(20);
}

void loop() 
{ 

	int mode = digitalRead(MODE_PIN);
	int curr_state = digitalRead(SENSOR_PIN);
	if (curr_state == 1) {
		digitalWrite(LED, HIGH);
	} else {
		digitalWrite(LED, LOW);
	}
	if (mode == 0) {
		if (prev_state != curr_state) {
			// click to start or stop recording video
			click_button();
		}
	} else {
		if (curr_state == 1) {
			if (time_count == 0) {
				click_button();		// click to take photo
			}
			time_count++;
			if (time_count == 3) {
				time_count = 0;		// take a photo every 3 seconds.
			}
		} else {
			time_count = 0;
		}
	}
	  
	prev_state = curr_state;
	 delay(1000);
} 
