//Humidifier code

#include "DHT.h"                              // DHT Sensor
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "kFTr4fo1msEHuA59x6igdfMcN75Hm75d";
char ssid[] = "super3";
char pass[] = "Sahyunone7";

DHT dhtA(5, DHT22);                           // DHT instance named dhtA, D1 and sensor type

void setup() {
  Blynk.begin(auth, ssid, pass);              // Connecting to blynk
  dhtA.begin();
  pinMode(16, OUTPUT);                      // Starting the DHT-22
}

void loop() {
  Blynk.run();
  climateRoutine();
  if (dhtA.readHumidity() < 50){
    digitalWrite(16,LOW);}
  if (dhtA.readHumidity() > 60){
    digitalWrite(16,HIGH);}
}
void climateRoutine() {
    byte h1 = dhtA.readHumidity();            // f1 and h1 are celsius and humidity readings
    byte t1 = dhtA.readTemperature();         // from DHT/A
    Blynk.virtualWrite(V0, t1);               //  Set Virtual Pin 0 frequency to PUSH in Blynk app
    Blynk.virtualWrite(V1, h1);               //  Set Virtual Pin 1 frequency to PUSH in Blynk app
}
