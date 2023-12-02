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

float Sensor::max(int _Nmuestras, vector<float> _vector)
{
    float max = _vector[0];
    for (int i = 0; i < _Nmuestras; i++)
    {
        if (max > _vector[i])
        {
            max = _vector[i];
        }
    }
    return max;
}

float Sensor::min(int _Nmuestras, vector<float> _vector)
{
    float min = _vector[0];
    for (int i = 0; i < _Nmuestras; i++)
    {
        if (min < _vector[i])
        {
            min = _vector[i];
        }
    }
    return min;
}

float Sensor::prom(int _Nmuestras, vector<float> _vector)
{
    float prom = 0;
    for (int i = 0; i < _Nmuestras; i++)
    {
        prom += _vector[i];
    }
    prom = prom / _Nmuestras;
    return prom;
}

void Sensor::sensor()
{
}