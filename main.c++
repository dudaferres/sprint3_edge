#include <ArduinoJson.h>
#include <DHT.h>
 
#define ledG 13
#define ledR 12
 
#define buzzer 8
 
#define DHTPIN 6
#define DHTTYPE DHT22
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
  dht.begin();
  Serial.begin(9600);
 
}
 
void loop() {
  float temp = dht.readTemperature();
 
  StaticJsonDocument<100> json;
  json["Temperatura"] = temp;
 
  serializeJson(json, Serial);
  Serial.println();
 
  if (temp < 35) {
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
    tone(buzzer, 200, 2000);
  } else if (temp >= 35 && temp <= 37) {
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
  } else{
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
    tone(buzzer, 200, 2000);
    delay(3000);
  }
 
  delay(3000);
}