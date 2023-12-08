/**
 * Project Untitled
 */

#ifndef _HUMEDAD_H
#define _HUMEDAD_H

#include "Sensor.h"

class Humedad : public Sensor
{
public:
    void set_humedad();
    float get_humedad();

private:
    void humedad();
};

#endif //_HUMEDAD_H