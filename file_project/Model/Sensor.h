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
    float max(int, vector<float>);

    float min(int, vector<float>);

    float prom(int, vector<float>);

protected:
    int _TiempoMedida;
    double _Muestra;

private:
    void sensor();
};

#endif //_SENSOR_H