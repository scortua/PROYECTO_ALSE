/**
 * Project Untitled
 */

#include "Temperatura.h"
#include <random>

/**
 * Tempertatura implementation
 */
using namespace std;

void Temperatura::set_temperatura()
{
    float minTemp = -10.0; // replace with your minimum temperature
    float maxTemp = 45.0; // replace with your maximum temperature
    float temperatura = getRandomNumber(minTemp, maxTemp);
    _Muestra = temperatura;
}

float Temperatura::get_temperatura()
{
    return _Muestra;
}

void Temperatura::temperatura()
{
}