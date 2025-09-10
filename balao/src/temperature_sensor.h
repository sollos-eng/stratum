#pragma once
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class DS18B20Multi {
  public:
    DS18B20Multi();      // construtor sem parâmetros
    void iniciar();      // inicializa os sensores
    void lerTodos(float &t1, float &t2, float &t3); // lê todos os sensores

  private:
    static const uint8_t PINO_DS18B20 = 15; // pino fixo do barramento
    OneWire oneWire;
    DallasTemperature sensors;

    // Endereços fixos dos sensores
    DeviceAddress sensor1 = { 0x28, 0x22, 0xF8, 0x95, 0xF0, 0x01, 0x3C, 0x6A };
    DeviceAddress sensor2 = { 0x28, 0x0E, 0xA1, 0x46, 0xD4, 0x7D, 0x1F, 0x7E };
    DeviceAddress sensor3 = { 0x28, 0xFF, 0x64, 0x1E, 0xCD, 0x09, 0x55, 0x7E };
};
