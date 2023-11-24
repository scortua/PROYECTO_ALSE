/**
 * Project Untitled
 */

#ifndef _LUZ_H
#define _LUZ_H

#include "Sensor.h"

class Luz : public Sensor
{
public:
    void set_luz();

private:
    void luz();
};

#endif //_LUZ_H