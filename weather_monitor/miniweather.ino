//humidity,temperature,rain detector sensors are used to monitor weather
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int analogPin =0;
void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
}

void loop() {
  // wait a few seconds between measurements.
  delay(1000);

  // read humidity
  float humi  = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();

  // check if any reads failed
  if (isnan(humi) || isnan(tempC)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  "); 

    Serial.print("Temperature: ");
    Serial.print(tempC-4);
    Serial.print("°C ");
  }
  if(analogRead(analogPin)<300) Serial.println("--Heavy Rain");
  else if(analogRead(analogPin)<500) Serial.println("--Moderate Rain");
  else Serial.println("--No Rain");
  Serial.println();
}
