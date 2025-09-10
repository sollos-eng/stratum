#include "DS18B20Multi.h"

// Construtor: inicializa OneWire e DallasTemperature com pino fixo
DS18B20Multi::DS18B20Multi()
  : oneWire(PINO_DS18B20), sensors(&oneWire) {}

// Inicializa os sensores
void DS18B20Multi::iniciar() {
  sensors.begin();
}

// Lê todos os sensores e retorna os valores por referência
void DS18B20Multi::lerTodos(float &t1, float &t2, float &t3) {
  sensors.requestTemperatures();
  t1 = sensors.getTempC(sensor1);
  t2 = sensors.getTempC(sensor2);
  t3 = sensors.getTempC(sensor3);
}
