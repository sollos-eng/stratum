#include <Arduino.h>


/*

 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */

// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to GPIO15
#define ONE_WIRE_BUS 15
// Setup a oneWire instance to communicate with a OneWire device
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

DeviceAddress sensor1 = { 0x28, 0x22, 0xF8, 0x95, 0xF0, 0x1, 0x3C, 0x6A };
DeviceAddress sensor2 = { 0x28, 0xE, 0xA1, 0x46, 0xD4, 0x7D, 0x1F, 0x7E };
DeviceAddress sensor3 = { 0x28, 0xFF, 0x64, 0x1E, 0XCD, 0X9, 0X55, 0X7E };

void setup(void){
  Serial.begin(115200);
  sensors.begin();
}

void loop(void){ 
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");
  
  Serial.print(">Sensor 1(*C): ");
  Serial.println(sensors.getTempC(sensor1)); 
 
  Serial.print(">Sensor 2(*C): ");
  Serial.println(sensors.getTempC(sensor2)); 
  
  Serial.print(">Sensor 3(*C): ");
  Serial.println(sensors.getTempC(sensor3)); 
  
  
  delay(2000);
}
