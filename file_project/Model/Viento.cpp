/**
 * Project Untitled
 */

#include "Viento.h"

/**
 * Viento implementation
 */

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