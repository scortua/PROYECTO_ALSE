/**
 * Project Untitled
 */

#include "Temperatura.h"
#include <random>

/**
 * Tempertatura implementation
 */
using namespace std;

int getRandomNumber(int min, int max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

void Temperatura::set_temperatura()
{
    float minTemp = 10; // replace with your minimum temperature
    float maxTemp = 45; // replace with your maximum temperature
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