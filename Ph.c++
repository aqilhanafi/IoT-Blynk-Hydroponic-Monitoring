
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>

/*
 * Temperature V0
 * Humidity V1
 * pH Sensor V2
 * DS18B20 V3
 * Water Level Sensor V4
 * Pump V5
 */
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Aqil Semmm";  
char pass[] = "aqil hensem";  
int pHpin = 15;

void sendSensor(){
}

void setup() {
  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Connect to Blynk
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected");
}

void loop() {

  float pH = readPH();
  Blynk.virtualWrite(V2, pH);
  delay(1000);
}

float readPH() {
  return 7.0;
}
