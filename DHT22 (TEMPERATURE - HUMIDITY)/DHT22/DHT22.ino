#include "DHT.h"
#define DHTPIN 6
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

/* DHT22 - TEMPERATURE AND HUMIDITY SENSORS*/
/* VARIABLE GLOBAL */
  float h = 0;
  float t = 0;
  float hic = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop(){
dht22();
}

void dht22() {
  delay(2000);
  h = dht.readHumidity();
  t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  hic = dht.computeHeatIndex(t, h, false);
}
