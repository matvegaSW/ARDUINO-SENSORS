#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

/* CENTRALE INERTIELLE (10 DOF ­ L3GD20H ­ LSM303 ­ BMP180) */

float temperaturebmp;
float altitudeBMP;
float pression;

void setup(void) 
{
  Serial.begin(9600);
  if(!)
  {
    Serial.print("BMP - Erreur");
    while(1);
  }
}

void loop(void) 
{
  sensors_event_t event;
  bmp.getEvent(&event);

  if (event.pressure)
  {
    pression=event.pressure;

    bmp.getTemperature(&temperaturebmp);
    Serial.print(temperaturebmp);

    altitudeBMP = SENSORS_PRESSURE_SEALEVELHPA;
    Serial.print(bmp.pressureToAltitude(altitudeBMP,event.pressure));
  }
  else
  {
    Serial.println("BMP - Erreur");
  }
  delay(1000);
}
