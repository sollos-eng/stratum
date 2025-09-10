#pragma once
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Classe para gerenciar múltiplos sensores DS18B20
class DS18B20Multi {
  public:
    // Construtor: recebe o pino onde os sensores estão conectados
    DS18B20Multi(uint8_t pino);

    // Inicializa os sensores
    void iniciar();

    // Lê a temperatura de um sensor pelo endereço
    float lerTemperatura(const DeviceAddress device);

    // Faz leitura de todos os sensores (exemplo: 3 sensores fixos)
    void lerTodos(float &t1, float &t2, float &t3);

  private:
    OneWire oneWire;
    DallasTemperature sensors;
};
