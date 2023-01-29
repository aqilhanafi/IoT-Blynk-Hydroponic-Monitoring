
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
 
/********** Water Level *********/
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
/********** DHT *********/
#include <DHT.h>
/********** DS18B20 *********/
#include <OneWire.h>
#include <DallasTemperature.h>
#define SENSOR_PIN  19 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Aqil Semmm";  
char pass[] = "aqil hensem";  

/********** Water Level *********/
#define POWER_PIN  18 
#define SIGNAL_PIN 34 
int value = 0; // variable to store the sensor value
/********** DHT *********/
BlynkTimer timer;
#define DHTPIN 21 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
/********** pH *********/
int pHpin = 15;
/********** DS18B20 *********/
OneWire oneWire(SENSOR_PIN);
DallasTemperature DS18B20(&oneWire);
float tempC; // temperature in Celsius
/********** Pump *********/
const int relayPin = 27;

/********** Pump *********/
BLYNK_WRITE(V5) {
  int pinValue = param.asInt();
  digitalWrite(relayPin, pinValue);
}

void sendSensor(){
/********** DHT *********/
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
void setup() {
/********** Water Level *********/
  Serial.begin(115200);
  pinMode(POWER_PIN, OUTPUT);   // configure pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
  Blynk.begin(auth, ssid, pass);
/********** DHT *********/
  dht.begin();
  timer.setInterval(100L, sendSensor);
/********** Pump *********/
  pinMode(relayPin, OUTPUT);
}

void loop() {
/********** Water Level *********/
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF
  Serial.print("Water level value: ");
  Serial.println(value);
  Blynk.virtualWrite(V4, value);
  delay(1000);
/********** DHT *********/
  Blynk.run();
  timer.run();
/********** pH *********/
  float pH = readPH();
  Blynk.virtualWrite(V2, pH);
  delay(1000);
/********** DS18B20 *********/
  DS18B20.requestTemperatures();       // send the command to get temperatures
  tempC = DS18B20.getTempCByIndex(0);  // read temperature in °C
  Serial.print("Water temperature: ");
  Serial.print(tempC);    // print the temperature in °C
  Serial.println("°C");
  Blynk.virtualWrite(V3, tempC);
  delay(500);
}
/********** pH *********/
float readPH() {
  return 7.0;
}
