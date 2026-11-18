#include <Servo.h>

Servo myservo;

int pos = 0;
boolean fire = false;

// Flame Sensor Pins (Active LOW for standard IR flame modules)
#define Left 9      // Left flame sensor
#define Right 10    // Right flame sensor
#define Forward 8   // Front flame sensor

// Motor Driver Pins
#define LM1 2       // Left motor input 1
#define LM2 3       // Left motor input 2
#define RM1 4       // Right motor input 1
#define RM2 5       // Right motor input 2

// Water Pump / Relay Pin
#define pump 6

void setup() {
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);

  myservo.attach(11);
  myservo.write(90); // Center the nozzle
}

void put_off_fire() {
  delay(500);

  // Stop the robot motors
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

  // Turn on the water pump
  digitalWrite(pump, HIGH);
  delay(500);

  // Sweep the servo nozzle back and forth to extinguish the fire
  for (pos = 50; pos <= 130; pos += 1) {
    myservo.write(pos);
    delay(10);
  }
  for (pos = 130; pos >= 50; pos -= 1) {
    myservo.write(pos);
    delay(10);
  }

  // Turn off the water pump and reset servo
  digitalWrite(pump, LOW);
  myservo.write(90);
  fire = false;
}

void loop() {
  myservo.write(90);

  // Check sensor readings (HIGH = No fire, LOW = Fire detected)
  if (digitalRead(Left) == HIGH && digitalRead(Right) == HIGH && digitalRead(Forward) == HIGH) {
    // No fire detected: Stop all motors
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  } 
  else if (digitalRead(Forward) == LOW) {
    // Fire detected straight ahead: Move forward
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    fire = true;
  } 
  else if (digitalRead(Left) == LOW) {
    // Fire detected on the left: Turn left
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
  } 
  else if (digitalRead(Right) == LOW) {
    // Fire detected on the right: Turn right
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }

  delay(300); // Short delay for stability

  // Execute extinguishing routine once aligned with the fire
  while (fire == true) {
    put_off_fire();
  }
}