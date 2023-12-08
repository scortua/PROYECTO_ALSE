/**
 * Project Untitled
 */

#ifndef _VIENTO_H
#define _VIENTO_H

#include "Sensor.h"

class Viento : public Sensor
{
public:
    void set_viento();
    float get_viento();

private:
    void viento();
};

#endif //_VIENTO_H