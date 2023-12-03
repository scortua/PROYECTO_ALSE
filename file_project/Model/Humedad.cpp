/**
 * Project Untitled
 */

#include "Humedad.h"
#include <random>

/**
 * Humedad implementation
 */

void Humedad::set_humedad()
{
    float minHum = 0;   // replace with your minimum temperature
    float maxHum = 100; // replace with your maximum temperature
    float humedad = getRandomNumber(minHum, maxHum);
    _Muestra = humedad;
}

float Humedad::get_humedad()
{
    return _Muestra;
}

void Humedad::humedad()
{
}