
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

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Aqil Semmm";  
char pass[] = "aqil hensem";  

#define POWER_PIN  18 
#define SIGNAL_PIN 34 
int value = 0; // variable to store the sensor value

void sendSensor(){
  
}
void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("The water sensor value: ");
  Serial.println(value);
  Blynk.virtualWrite(V4, value);
  delay(1000);
  
}

