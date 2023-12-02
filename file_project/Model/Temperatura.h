/**
 * Project Untitled
 */

#ifndef _TEMPERATURA_H
#define _TEMPERATURA_H

#include "Sensor.h"

class Temperatura : public Sensor
{
public:
    void set_temperatura();
    float get_temperatura();

private:
    void temperatura();
};

#endif //_TEMPERATURA_H