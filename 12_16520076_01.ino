int npnPin = 7;
const int buzzPin = 8;

void setup()
{
  pinMode(npnPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  tone(buzzPin, 523, 500);
  Serial.println("Start");
  digitalWrite(npnPin, HIGH);
  delay(5000);
  Serial.println("Stop");
  digitalWrite(npnPin, LOW);
  delay(5000);
}