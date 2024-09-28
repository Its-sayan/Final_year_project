#include<iostream>
#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>
using namespace std;
// Define pin assignments
const int trigPin = 9;
const int echoPin = 10;
const int lcd_rs = 12;
const int lcd_en = 11;
const int lcd_d4 = 5;
const int lcd_d5 = 4;
const int lcd_d6 = 3;
const int lcd_d7 = 2;

void setup() {
  // Initialize Wi-Fi
  WiFi.begin("your_ssid", "your_password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to Wi-Fi");

  // Initialize LCD
  lcd.begin(16, 2);
}

void loop() {
  // Measure distance using ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;

  // Send distance data over Wi-Fi (e.g., using a web server or MQTT)

  // Display distance on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");
}
