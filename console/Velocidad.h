/**
 * Project Untitled
 */

#ifndef _VELOCIDAD_H
#define _VELOCIDAD_H

#include "Sensor.h"

class Velocidad : public Sensor
{
public:
    void set_velocidad();
    float get_velocidad();

private:
    void velocidad();
};

#endif //_VELOCIDAD_H