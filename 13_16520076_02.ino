#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int ping_Pin = A1;
long dur, cm;

void setup()  {
  lcd.begin(16, 2);
  lcd.print("PING Sensor");
}

void loop()   {
  cm = read_sensor_ultrasonic();
  
  lcd.setCursor(0,1);
  lcd.print("Jarak");
  lcd.setCursor(6, 1);
  lcd.print(cm);
}

int read_sensor_ultrasonic()  {
  /*baca dari ultrasonci sendor*/ 
  
  pinMode(ping_Pin, OUTPUT);		// atur pin sebagai output
  digitalWrite(ping_Pin, LOW);	// sinyal awal LOW
  delayMicroseconds(2); 		// Wait for 2 µs
  digitalWrite(ping_Pin, HIGH);	// trigger sensor dengan sinyal HIGH
  delayMicroseconds(5); 		// Wait for 5 µs
  digitalWrite(ping_Pin, LOW);	// trigger sensor dengan sinyal LOW
  
  pinMode(ping_Pin, INPUT);					// atur pin sebangai input
  dur = pulseIn(ping_Pin, HIGH);		// sinyal HIGH untuk dapat durasi
  cm = microsecondsToCentimeters(dur);	// konversi µs ke cm
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds) {
  // kecepatan suara 340 m/s atau 29µs/cm
  // dibagi dua untuk mencari jarak sensor-objek
  return microseconds / 29 / 2;
}