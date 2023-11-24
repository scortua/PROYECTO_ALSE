/**
 * Project Untitled
 */

#ifndef _SENSOR_H
#define _SENSOR_H

class Sensor
{
public:
    void escribir_bd();

    void promedio();

    void max();

    void min();

    void prom();

    void getMax();

    void getMin();

    void getProm();

protected:
    int _TiempoMedida;
    double _Medida;

private:
    void sensor();
};

#endif //_SENSOR_H