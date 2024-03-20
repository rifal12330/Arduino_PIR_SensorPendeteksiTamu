// Definisikan pin yang digunakan
const int pirSensorPin = 2; // Pin sensor PIR terhubung ke pin 2
const int ledPin = 4;      // LED terhubung ke pin 13
const int buzzerPin = 3;    // Buzzer terhubung ke pin 9

void setup() {
  pinMode(pirSensorPin, INPUT); // Atur pin sensor PIR sebagai input
  pinMode(ledPin, OUTPUT);       // Atur pin LED sebagai output
  pinMode(buzzerPin, OUTPUT);    // Atur pin buzzer sebagai output

  Serial.begin(9600); // Mulai komunikasi serial dengan kecepatan 9600 bps
}

void loop() {
  // Baca nilai sensor PIR
  int motionDetected = digitalRead(pirSensorPin);

  // Jika gerakan terdeteksi
  if (motionDetected == HIGH) {
    Serial.println("Ada gerakan"); // Cetak pesan ke Serial Monitor
    digitalWrite(ledPin, HIGH);    // Nyalakan LED
    digitalWrite(buzzerPin, HIGH); // Nyalakan buzzer
    delay(500);                    // Tunda selama setengah detik
    digitalWrite(buzzerPin, LOW);  // Matikan buzzer
  } else {
    Serial.println("Tidak Ada Gerakan");
    digitalWrite(ledPin, LOW); 
    delay(500);// Matikan LED jika tidak ada gerakan
  }
}
