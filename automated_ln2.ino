#include <SoftwareSerial.h>

int targetWeight = 5;
bool startValue = false;
SoftwareSerial mySerial(0,1);

void targetIncrease() {
  noInterrupts();
  targetWeight += 5;
  interrupts();
}

void targetDecrease() {
  noInterrupts();
  if (targetWeight > 10) {
    targetWeight -= 5;
  }
  interrupts();
}

void alarm() {
  noInterrupts();
  digitalWrite(9, HIGH);
  delay(5000);
  digitalWrite(9, LOW);
  interrupts();
}

void start() {
  noInterrupts();
  startValue = !startValue;
  interrupts();
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(6), targetIncrease, FALLING);
  attachInterrupt(digitalPinToInterrupt(7), targetDecrease, FALLING);
  attachInterrupt(digitalPinToInterrupt(8), start, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  double currentWeight = mySerial.read();
  double startWeight = currentWeight;
  while (startValue == true) {
    currentWeight = mySerial.read();
    double neededWeight = startWeight - targetWeight;
    if (currentWeight <= neededWeight) {
      alarm();
    }
  }
}
