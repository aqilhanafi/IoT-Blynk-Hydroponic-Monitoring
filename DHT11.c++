
#define BLYNK_TEMPLATE_ID "TMPLmOCGqX0u"
#define BLYNK_DEVICE_NAME "Temperature and Humidity Monitor"
#define BLYNK_AUTH_TOKEN "KgwD_Li5zo-EFMl0NSNze2UORstQQ5DT"

/*
 * Temperature V0
 * Humidity V1
 * pH Sensor V2
 * DS18B20 V3
 * Water Level Sensor V4
 * Pump V5
 */
 
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "aqil punya";  
char pass[] = "aqilhensem";  

BlynkTimer timer;
#define DHTPIN 21 
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}
void setup()
{    
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(100L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }
 
