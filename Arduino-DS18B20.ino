
//Import all libraries required to support DS18B20 sensor
#include <OneWire.h>
#include <DallasTemperature.h>

const int SENSOR_PIN = 13; // Arduino pin connected to DS18B20 sensor's DQ pin

OneWire oneWire(SENSOR_PIN);         // setup a oneWire instance
DallasTemperature sensors(&oneWire); // pass oneWire to DallasTemperature library

float tempCelsius;    // temperature in Celsius
float tempFahrenheit; // temperature in Fahrenheit

void setup()
{
  Serial.begin(9600); // initialize serial
  sensors.begin();    // initialize the sensor
}

void loop()
{
  sensors.requestTemperatures();             // send the command to get temperatures
  tempCelsius = sensors.getTempCByIndex(0);  // read temperature in Celsius
  tempFahrenheit = tempCelsius * 9 / 5 + 32; // convert Celsius to Fahrenheit

  Serial.print("Temperature: ");
  Serial.print(tempCelsius);    // print the temperature in Celsius
  Serial.print("°C");
  Serial.print("  ~  ");        // separator between Celsius and Fahrenheit
  Serial.print(tempFahrenheit); // print the temperature in Fahrenheit
  Serial.println("°F");

  delay(500);
}
