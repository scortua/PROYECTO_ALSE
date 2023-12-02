/**
 * Project Untitled
 */

#include "Velocidad.h"

/**
 * Velocidad implementation
 */
int getRandomNumber(int min, int max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

void Velocidad::set_velocidad()
{
    float minVel = 0;  // replace with your minimum temperature
    float maxVel = 40; // replace with your maximum temperature
    float velocidad = getRandomNumber(minVel, maxVel);
    _Muestra = velocidad;
}

float Velocidad::get_velocidad()
{
    return _Muestra;
}

void Velocidad::velocidad()
{
}