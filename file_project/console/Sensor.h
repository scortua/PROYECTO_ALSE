/**
 * Project Untitled
 */

#ifndef _SENSOR_H
#define _SENSOR_H

#include <vector>
#include <random>

using namespace std;


class Sensor
{
public:
    static float max(float, vector<float>);

    static float min(float, vector<float>);

    static float prom(float, vector<float>);

    float getRandomNumber(float, float);


protected:
    int _TiempoMedida;
    double _Muestra;

private:
    void sensor();
};

#endif //_SENSOR_H