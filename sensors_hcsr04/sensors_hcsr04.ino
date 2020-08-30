// Libraries
#include <Ultrasonic.h>

// Sensor pins
#define SR04_TRIGGER_PIN 4
#define SR04_ECHO_PIN 3

// Sensor definitions
Ultrasonic ultrasonic(SR04_TRIGGER_PIN, SR04_ECHO_PIN);

void setup() {
  // Set up serial communication
  Serial.begin(9600);
  
  // Legend
  Serial.println("distance(cm) ");

}

void loop() {
  
  delay(100); // Take a reading every 0.1 seconds

  // HC-SR04
  float distance = ultrasonic.read();
  Serial.println(distance);
  
}
