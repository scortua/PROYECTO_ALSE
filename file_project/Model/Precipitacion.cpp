/**
 * Project Untitled
 */

#include "Precipitacion.h"
#include <random>

using namespace std;

/**
 * Precipitacion implementation
 */

int getRandomNumber(int min, int max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

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