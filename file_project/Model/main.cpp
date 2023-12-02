#include <iostream>
#include <sqlite3.h>

#include "Sensor.h"
#include "Temperatura.h"
#include "Humedad.h"
#include "Velocidad.h"
#include "Viento.h"
#include "Precipitacion.h"
#include "Luz.h"

using namespace std;

int main(int argc, char **argv)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    string sqlstr;

    /* crear la tabla de sensores */
    rc = sqlite3_open("test.db", &db);

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

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        return (2);
    }
    else
    {
        fprintf(stdout, "Table created successfully\n");
    }

    // informacion de lo sensores

    // insertar informacion en la tabla
}
