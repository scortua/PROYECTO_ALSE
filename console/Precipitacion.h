/**
 * Project Untitled
 */

#ifndef _PRECIPITACION_H
#define _PRECIPITACION_H

#include "Sensor.h"

class Precipitacion : public Sensor
{
public:
    void set_precipitacion();
    float get_precipitacion();

private:
    void precipitacion();
};

#endif //_PRECIPITACION_H