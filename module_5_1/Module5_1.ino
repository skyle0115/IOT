// Example testing sketch for various DHT11, DHT21, DHT22 humidity/temperature sensors
// Written by Lin Wei Ting in National Taipei University of Technology Applied Network Laboratory. Taipei, Taiwan.

#include "LDHT.h"
#include <Grove_LED_Bar.h>

#define DHTPIN 3          // what pin we're connected to
#define DHTTYPE DHT22     // using DHT11 sensor

LDHT dht(DHTPIN,DHTTYPE);
Grove_LED_Bar bar(9, 8, 0);

float tempC=0.0,Humi=0.0;

float Initial_Temp = 0.0;

void setup()
{
    Serial.begin(9600);
    dht.begin();
    bar.begin();
	
    Serial.print(DHTTYPE);
    //Serial.println(" test!");
}

void loop()
{
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    if(dht.read())
    {
        tempC = dht.readTemperature();
        //Humi = dht.readHumidity();
        
        Serial.print("Temperature Celcius = ");
        Serial.print(dht.readTemperature());
        Serial.println("C");

        bar.setLevel((tempC - 25)/0.35);
    }

    delay(500);
}
