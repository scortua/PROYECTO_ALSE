#include <iostream>
#include <sqlite3.h>
#include <chrono>
#include <ctime>
#include <string>

#include "Sensor.h"
#include "Temperatura.h"
#include "Humedad.h"
#include "Velocidad.h"
#include "Viento.h"
#include "Precipitacion.h"
#include "Luz.h"

using namespace std;

std::string get_current_date()
{
    std::time_t now = std::time(nullptr);
    char date_str[11];
    std::strftime(date_str, sizeof(date_str), "%Y-%m-%d", std::localtime(&now));
    return std::string(date_str);
}

int main(int argc, char **argv)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;
    string sql;
    string fecha = get_current_date();
    int ts = atoi(argv[1]); // tiempo de muestreo

    /* crear la tabla de sensores */
    rc = sqlite3_open("base_datos.db", &db);

    if (rc != 0)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS sensores (SENSOR TEXT NOT NULL,"
             "MINIMO INTEGER NOT NULL, PROMEDIO INTEGER NOT NULL,"
             "MAXIMO INTEGER NOT NULL, FECHA TEXT NOT NULL);";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    sqlite3_close(db);

    // crear los sensores
    vector<float> temp;
    vector<float> hum;
    vector<float> vel;
    vector<float> viento;
    vector<float> prec;
    vector<float> luz;

    for (int i = 0; i < (60 / ts); i++) // Fix: Changed i+ts to i+=ts
    {
        Temperatura t;
        t.set_temperatura();
        temp.push_back(t.get_temperatura());

        Humedad h;
        h.set_humedad();
        hum.push_back(h.get_humedad());

        Velocidad v;
        v.set_velocidad();
        vel.push_back(v.get_velocidad());

        Viento vi;
        vi.set_viento();
        viento.push_back(vi.get_viento());

        Precipitacion p;
        p.set_precipitacion();
        prec.push_back(p.get_precipitacion());

        Luz l;
        l.set_luz();
        luz.push_back(l.get_luz());
        /*

            cout << "Temperatura " << i << ": " << temp[i] << endl;
            cout << "Humedad " << i << ": " << hum[i] << endl;
            cout << "Velocidad " << i << ": " << vel[i] << endl;
            cout << "Viento " << i << ": " << viento[i] << endl;
            cout << "Precipitacion " << i << ": " << prec[i] << endl;
            cout << "Luz " << i << ": " << luz[i] << endl;

        */
    }

    float minTemp = Sensor::min(60 / ts, temp);   // Fix: Added :: before min
    float maxTemp = Sensor::max(60 / ts, temp);   // Fix: Added :: before max
    float promTemp = Sensor::prom(60 / ts, temp); // Fix: Added :: before prom

    float minHum = Sensor::min(60 / ts, hum);   // Fix: Added :: before min
    float maxHum = Sensor::max(60 / ts, hum);   // Fix: Added :: before max
    float promHum = Sensor::prom(60 / ts, hum); // Fix: Added :: before prom

    float minVel = Sensor::min(60 / ts, vel);   // Fix: Added :: before min
    float maxVel = Sensor::max(60 / ts, vel);   // Fix: Added :: before max
    float promVel = Sensor::prom(60 / ts, vel); // Fix: Added :: before prom

    float minViento = Sensor::min(60 / ts, viento);   // Fix: Added :: before min
    float maxViento = Sensor::max(60 / ts, viento);   // Fix: Added :: before max
    float promViento = Sensor::prom(60 / ts, viento); // Fix: Added :: before prom

    float minPrec = Sensor::min(60 / ts, prec);   // Fix: Added :: before min
    float maxPrec = Sensor::max(60 / ts, prec);   // Fix: Added :: before max
    float promPrec = Sensor::prom(60 / ts, prec); // Fix: Added :: before prom

    float minLuz = Sensor::min(60 / ts, luz);   // Fix: Added :: before min
    float maxLuz = Sensor::max(60 / ts, luz);   // Fix: Added :: before max
    float promLuz = Sensor::prom(60 / ts, luz); // Fix: Added :: before prom

    cout << "Tiempo de muestreo: " << ts << " .Numero de muestreas: " << 60 / ts << endl;
    cout << "Fecha: " << fecha << endl;

    cout << "Temperatura: " << minTemp << " " << promTemp << " " << maxTemp << endl;
    cout << "Humedad: " << minHum << " " << promHum << " " << maxHum << endl;
    cout << "Velocidad: " << minVel << " " << promVel << " " << maxVel << endl;
    cout << "Viento: " << minViento << " " << promViento << " " << maxViento << endl;
    cout << "Precipitacion: " << minPrec << " " << promPrec << " " << maxPrec << endl;
    cout << "Luz: " << minLuz << " " << promLuz << " " << maxLuz << endl;

    /* Create SQL statement */
    sql = "INSERT INTO sensores (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
          "VALUES ('Temperatura', " +
          to_string(minTemp) + ", " + to_string(promTemp) + ", " + to_string(maxTemp) + ", '" + fecha + "'); "
                                                                                                        "INSERT INTO sensores (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                        "VALUES ('Humedad', " +
          to_string(minHum) + ", " + to_string(promHum) + ", " + to_string(maxHum) + ", '" + fecha + "'); "
                                                                                                     "INSERT INTO sensores (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                     "VALUES ('Velocidad', " +
          to_string(minVel) + ", " + to_string(promVel) + ", " + to_string(maxVel) + ", '" + fecha + "'); "
                                                                                                     "INSERT INTO sensores (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                     "VALUES ('Viento', " +
          to_string(minViento) + ", " + to_string(promViento) + ", " + to_string(maxViento) + ", '" + fecha + "'); "
                                                                                                              "INSERT INTO sensores (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                              "VALUES ('Precipitacion', " +
          to_string(minPrec) + ", " + to_string(promPrec) + ", " + to_string(maxPrec) + ", '" + fecha + "'); "
                                                                                                        "INSERT INTO sensores (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                        "VALUES ('Luz', " +
          to_string(minLuz) + ", " + to_string(promLuz) + ", " + to_string(maxLuz) + ", '" + fecha + "'); ";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);
    return 0;
}
