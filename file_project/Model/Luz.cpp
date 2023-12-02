/**
 * Project Untitled
 */

#include "Luz.h"
#include <random>
/**
 * Luz implementation
 */
using namespace std;

int getRandomNumber(int min, int max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

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