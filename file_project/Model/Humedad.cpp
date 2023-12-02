/**
 * Project Untitled
 */

#include "Humedad.h"
#include <random>

/**
 * Humedad implementation
 */
int getRandomNumber(int min, int max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

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