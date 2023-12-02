/**
 * Project Untitled
 */

#include "Viento.h"

/**
 * Viento implementation
 */

int getRandomNumber(int min, int max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void Viento::set_viento()
{
    float minViento = -180; // replace with your minimum temperature
    float maxViento = 180;  // replace with your maximum temperature
    float viento = getRandomNumber(minViento, maxViento);
    _Muestra = viento;
}

void Viento::viento()
{
}

float Viento::get_viento()
{
    return _Muestra;
}