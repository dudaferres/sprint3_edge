#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>


#define DHTPIN 15
#define ledG 12
#define ledR 13
#define buzzer 2
DHT dht(DHTPIN, DHT22);

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
  dht.begin();

  WiFi.begin("Wokwi-GUEST", "");
  while (WiFi.status() != WL_CONNECTED) delay(100);

  mqttClient.setServer("test.mosquitto.org", 1883);

  mqttClient.connect("esp32-cliente");
}

void loop() {
  mqttClient.loop();

  float temp = dht.readTemperature();
  float umi = dht.readHumidity();


  StaticJsonDocument<100> json;
  json["Temperatura"] = temp;

  char jsonBuffer[200];
  serializeJson(json, jsonBuffer);

  mqttClient.publish("sensor/dht/gabi", jsonBuffer);

  if (temp >= 35 && temp <= 37){
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
  } else {
    digitalWrite(ledG, LOW);
    digitalWrite(ledR, HIGH);
    tone(buzzer, 200, 2000);
  }
  delay(3000);
  
}
