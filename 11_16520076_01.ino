const int pingPin = 7;			// pin Arduino  yang akan membaca output sensor

void setup()
{
  Serial.begin(9600);			// membuta port serial
}

void loop()
{
  long duration, cm;			// variabel untuk menyimpan nilai durasi dan jarak (cm)si dan
  
  pinMode(pingPin, OUTPUT)		// atur pin sebagai output
  digitalWrite(pingPin, LOW);	// sinyal awal LOW
  delayMicroseconds(2); 		// Wait for 2 µs
  digitalWrite(pingPin, HIGH);	// trigger sensor dengan sinyal HIGH
  delayMicroseconds(5); 		// Wait for 5 µs
  digitalWrite(pingPin, LOW);	// trigger sensor dengan sinyal LOW
  
  pinMode(pingPin, INPUT);					// atur pin sebangai input
  duration = pulseIn(pingPin, HIGH);		// sinyal HIGH untuk dapat durasi
  cm = microsecondsToCentimeters(duration);	// konversi µs ke cm
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  // kecepatan suara 340 m/s atau 29µs/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return microseconds / 29 / 2;
}