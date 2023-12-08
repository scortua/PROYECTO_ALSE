/**
 * Project Untitled
 */

#include "Luz.h"
#include <random>
/**
 * Luz implementation
 */
using namespace std;

void Luz::set_luz()
{
    float minLuz = 0;   // replace with your minimum temperature
    float maxLuz = 100; // replace with your maximum temperature
    float humedad = getRandomNumber(minLuz, maxLuz);
    _Muestra = humedad;
}

float Luz::get_luz()
{
    return _Muestra;
}

void Luz::luz()
{
}