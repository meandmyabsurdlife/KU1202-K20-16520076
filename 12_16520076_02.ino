#include <Servo.h>
Servo servo_0;
const int servoPin = 7;
const int ledPin = 2;
int pos = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  servo_0.attach(servoPin);
  servo_0.write(pos);
}

void loop()
{
  digitalWrite(2, HIGH);
  for (pos = 0; pos <= 90; pos += 1)
  {
    servo_0.write(pos);
    delay(15);
  }
  delay(2000);
  
  digitalWrite(2, LOW);
  for (pos = 90; pos >= 0; pos -= 1)
  {
    servo_0.write(pos);
    delay(15);
  }
  delay(2000);
}