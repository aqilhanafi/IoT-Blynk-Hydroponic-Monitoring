
#define BLYNK_TEMPLATE_ID "TMPLN9h6oKk9"
#define BLYNK_DEVICE_NAME "Hydroponic Monitor"
#define BLYNK_AUTH_TOKEN "2V2KXq2lnh7i0AxmZWWawJcH2oimBCqI"

/*
 * Temperature V0
 * Humidity V1
 * pH Sensor V2
 * DS18B20 V3
 * Water Level Sensor V4
 * Pump V5
 */
 
#include <OneWire.h>
#include <DallasTemperature.h>
#define SENSOR_PIN  19 
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Aqil Semmm";  
char pass[] = "aqil hensem";  

float tempC; // temperature in Celsius

void sendSensor(){
  
}
void setup() {
  Serial.begin(115200); // initialize serial
  DS18B20.begin();    // initialize the DS18B20 sensor
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  DS18B20.requestTemperatures();       // send the command to get temperatures
  tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C
  Serial.print("Temperature: ");
  Serial.print(tempC);    // print the temperature in °C
  Serial.println("°C");
  Blynk.virtualWrite(V3, tempC);
  delay(500);
}