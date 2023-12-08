/**
 * Project Untitled
 */

#include "Velocidad.h"

/**
 * Velocidad implementation
 */

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