
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

// Hardware pin which is connected to relay.
const int relayPin = 27;

BLYNK_WRITE(V5) {
  int pinValue = param.asInt();
  digitalWrite(relayPin, pinValue);
}

void setup() {
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  Blynk.run();
}
