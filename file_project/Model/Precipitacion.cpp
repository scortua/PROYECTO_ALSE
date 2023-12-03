/**
 * Project Untitled
 */

#include "Precipitacion.h"
#include <random>

using namespace std;

/**
 * Precipitacion implementation
 */

void Precipitacion::set_precipitacion()
{
    float minPrec = 0;  // replace with your minimum temperature
    float maxPrec = 50; // replace with your maximum temperature
    float precipitacion = getRandomNumber(minPrec, maxPrec);
    _Muestra = precipitacion;
}

void Precipitacion::precipitacion()
{
}

float Precipitacion::get_precipitacion()
{
    return _Muestra;
}