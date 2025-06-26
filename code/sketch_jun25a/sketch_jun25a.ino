// RC Plane Control with Arduino UNO or Nano
// Channels: Rudder, Elevator, Throttle, Aileron (4 CH)

#include <Servo.h>

Servo throttleServo;
Servo rudderServo;
Servo elevatorServo;
Servo aileronServo;

// Connect receiver outputs to these pins
const int throttlePin = 2;
const int rudderPin   = 3;
const int elevatorPin = 4;
const int aileronPin  = 5;

void setup() {
  throttleServo.attach(9);   // ESC/Throttle
  rudderServo.attach(10);    // Rudder servo
  elevatorServo.attach(11);  // Elevator servo
  aileronServo.attach(12);   // Aileron servo

  pinMode(throttlePin, INPUT);
  pinMode(rudderPin, INPUT);
  pinMode(elevatorPin, INPUT);
  pinMode(aileronPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  int throttleVal = pulseIn(throttlePin, HIGH, 25000);
  int rudderVal   = pulseIn(rudderPin, HIGH, 25000);
  int elevatorVal = pulseIn(elevatorPin, HIGH, 25000);
  int aileronVal  = pulseIn(aileronPin, HIGH, 25000);

  if (throttleVal > 1000 && throttleVal < 2000) {
    throttleServo.writeMicroseconds(throttleVal);
  }
  if (rudderVal > 1000 && rudderVal < 2000) {
    rudderServo.writeMicroseconds(rudderVal);
  }
  if (elevatorVal > 1000 && elevatorVal < 2000) {
    elevatorServo.writeMicroseconds(elevatorVal);
  }
  if (aileronVal > 1000 && aileronVal < 2000) {
    aileronServo.writeMicroseconds(aileronVal);
  }

  delay(10);
}
