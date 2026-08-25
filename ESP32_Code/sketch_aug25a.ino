#include <SPI.h>
#include <MFRC522.h>
#include <ESP32Servo.h>

#define SS_PIN 5
#define RST_PIN 22
#define SERVO_PIN 13

#define GREEN_LED 25
#define RED_LED 26
#define BUZZER 27

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myServo;

// 👉 PUT YOUR CARD UID HERE (from serial monitor)
String authorizedUID = "A1 67 46 54";

void beep(int times, int d) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER, HIGH);
    delay(d);
    digitalWrite(BUZZER, LOW);
    delay(d);
  }
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // Servo setup (ESP32)
  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);
  myServo.write(0); // LOCK

  // Default state
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  Serial.println("Scan RFID...");
}

void loop() {

  // Wait for card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  String content = "";

  // 🔥 Proper UID formatting (important fix)
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) content += "0";
    content += String(mfrc522.uid.uidByte[i], HEX);
    if (i != mfrc522.uid.size - 1) content += " ";
  }

  content.toUpperCase();
  content.trim();

  Serial.print("UID: ");
  Serial.println(content);

  // ✅ MATCH CHECK
  if (content == authorizedUID) {
    Serial.println("Access Granted");

    myServo.write(90); // OPEN
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    beep(1, 200);

    delay(3000);

    // Lock again
    myServo.write(0);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  } 
  else {
    Serial.println("Access Denied");

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    beep(3, 150);
  }

  mfrc522.PICC_HaltA();
}

