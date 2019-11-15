int led = 13;
int led2 = 12;

#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// The DC motor connected to M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);

// The DC motor connected to M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(19200);
  AFMS.begin();
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
  Serial.println("Startup");
}

void forward() {
  Serial.print("Moving forward...");
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  delay(1000);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  Serial.println("Stopped");
}

void backward() {
  Serial.print("Moving forward...");
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
  delay(1000);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  Serial.println("Stopped");
}

void left() {
  Serial.print("Moving forward...");
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);
  delay(1000);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  Serial.println("Stopped");
}

void right() {
  Serial.print("Moving forward...");
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);
  delay(1000);
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  Serial.println("Stopped");
}
void loop() {
  char c = Serial.read();

  if (c == 'f') {
    forward();
  }

  if (c == 'b') {
    backward();
  }

if (c == 'l') {
    left();
  }

  if (c == 'r') {
    right();
  }
  
  digitalWrite(led, HIGH);
  digitalWrite(led2, LOW);
  delay(700);
  digitalWrite(led, LOW);
  digitalWrite(led2, HIGH);
  delay(700);
}

