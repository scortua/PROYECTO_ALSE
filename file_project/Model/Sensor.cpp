/**
 * Project Untitled
 */

#include "Sensor.h"
#include <string.h>
#include <vector>
#include <random>

/**
 * Sensor implementation
 */

using namespace std;

float Sensor::max(float _Nmuestras, vector<float> _vector)
{
    float max = _vector[0];
    for (int i = 1; i < _Nmuestras; i++)
    {
        if (max < _vector[i])
        {
            max = _vector[i];
        }
    }
    return max;
}

float Sensor::min(float _Nmuestras, vector<float> _vector)
{
    float min = _vector[0];
    for (int i = 1; i < _Nmuestras; i++)
    {
        if (min > _vector[i])
        {
            min = _vector[i];
        }
    }
    return min;
}

float Sensor::prom(float _Nmuestras, vector<float> _vector)
{
    float prom = 0;
    for (int i = 1; i < _Nmuestras; i++)
    {
        prom += _vector[i];
    }
    prom = prom / _Nmuestras;
    return prom;
}

float Sensor::getRandomNumber(float min, float max)
{
    random_device rd;  // Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> distrib(min, max);

    return distrib(gen);
}

void Sensor::sensor()
{
}