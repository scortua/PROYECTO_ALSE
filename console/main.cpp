#include <iostream>
#include <sqlite3.h>
#include <chrono>
#include <ctime>
#include <string>
#include <vector>

#include "Sensor.h"
#include "Temperatura.h"
#include "Humedad.h"
#include "Velocidad.h"
#include "Viento.h"
#include "Precipitacion.h"
#include "Luz.h"

#include <mysql/mysql.h>

using namespace std;

MYSQL *connection = mysql_init(NULL);
int query_state;

#define HOST "db4free.net"       // Reemplaza "tu_servidor" con la dirección IP o el nombre del host de tu servidor MySQL
#define USER "cortua_abellita"   // Reemplaza "tu_usuario" con tu nombre de usuario de MySQL
#define PASSWD "cortua_abellita" // Reemplaza "tu_contraseña" con tu contraseña de MySQL
#define DB "base_datos_alse"

string get_current_date()
{
    time_t now = time(nullptr);
    char date_str[20];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(date_str);
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
    rc = sqlite3_open("db_name.db", &db);

    if (rc != 0)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (1);
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n\n");
    }

    sqlstr = "CREATE TABLE IF NOT EXISTS sensores_pc (ID INTEGER PRIMARY KEY AUTOINCREMENT, SENSOR TEXT NOT NULL,"
             "MINIMO INTEGER NOT NULL, PROMEDIO INTEGER NOT NULL,"
             "MAXIMO INTEGER NOT NULL, FECHA TEXT NOT NULL);";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    // sqlite3_close(db);

    // crear los sensores
    vector<float> temp;
    vector<float> hum;
    vector<float> vel;
    vector<float> viento;
    vector<float> prec;
    vector<float> luz;

    // llenar los sensores
    for (int i = 0; i < (60 / ts); i++)
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
            // verificacion de los sensores
            cout << "Temperatura " << i << ": " << temp[i] << endl;
            cout << "Humedad " << i << ": " << hum[i] << endl;
            cout << "Velocidad " << i << ": " << vel[i] << endl;
            cout << "Viento " << i << ": " << viento[i] << endl;
            cout << "Precipitacion " << i << ": " << prec[i] << endl;
            cout << "Luz " << i << ": " << luz[i] << endl;

        */
    }

    float minTemp = Sensor::min(60 / ts, temp);
    float maxTemp = Sensor::max(60 / ts, temp);
    float promTemp = Sensor::prom(60 / ts, temp);

    float minHum = Sensor::min(60 / ts, hum);
    float maxHum = Sensor::max(60 / ts, hum);
    float promHum = Sensor::prom(60 / ts, hum);

    float minVel = Sensor::min(60 / ts, vel);
    float maxVel = Sensor::max(60 / ts, vel);
    float promVel = Sensor::prom(60 / ts, vel);

    float minViento = Sensor::min(60 / ts, viento);
    float maxViento = Sensor::max(60 / ts, viento);
    float promViento = Sensor::prom(60 / ts, viento);

    float minPrec = Sensor::min(60 / ts, prec);
    float maxPrec = Sensor::max(60 / ts, prec);
    float promPrec = Sensor::prom(60 / ts, prec);

    float minLuz = Sensor::min(60 / ts, luz);
    float maxLuz = Sensor::max(60 / ts, luz);
    float promLuz = Sensor::prom(60 / ts, luz);

    cout << "Tiempo de muestreo: " << ts << " .Numero de muestreas: " << 60 / ts << endl;
    cout << "Fecha: " << fecha << "\n\n";

    cout << "Temperatura: " << minTemp << " " << promTemp << " " << maxTemp << endl;
    cout << "Humedad: " << minHum << " " << promHum << " " << maxHum << endl;
    cout << "Velocidad: " << minVel << " " << promVel << " " << maxVel << endl;
    cout << "Viento: " << minViento << " " << promViento << " " << maxViento << endl;
    cout << "Precipitacion: " << minPrec << " " << promPrec << " " << maxPrec << endl;
    cout << "Luz: " << minLuz << " " << promLuz << " " << maxLuz << endl;

    // insertar los datos en la base de datos
    sql = "INSERT INTO sensores_pc (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
          "VALUES ('Temperatura', " +
          to_string(minTemp) + ", " + to_string(promTemp) + ", " + to_string(maxTemp) + ", '" + fecha + "'); "
                                                                                                        "INSERT INTO sensores_pc (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                        "VALUES ('Humedad', " +
          to_string(minHum) + ", " + to_string(promHum) + ", " + to_string(maxHum) + ", '" + fecha + "'); "
                                                                                                     "INSERT INTO sensores_pc (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                     "VALUES ('Velocidad', " +
          to_string(minVel) + ", " + to_string(promVel) + ", " + to_string(maxVel) + ", '" + fecha + "'); "
                                                                                                     "INSERT INTO sensores_pc (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                     "VALUES ('Viento', " +
          to_string(minViento) + ", " + to_string(promViento) + ", " + to_string(maxViento) + ", '" + fecha + "'); "
                                                                                                              "INSERT INTO sensores_pc (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
                                                                                                              "VALUES ('Precipitacion', " +
          to_string(minPrec) + ", " + to_string(promPrec) + ", " + to_string(maxPrec) + ", '" + fecha + "'); "
                                                                                                        "INSERT INTO sensores_pc (SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) "
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
    cout << "Base de datos creada" << endl;

    // Conectar a la base de datos remota
    if (mysql_real_connect(connection, HOST, USER, PASSWD, DB, 0, NULL, 0) == NULL)
    {
        cout << "Failed to connect to database: " << mysql_error(connection) << endl;
        return 1;
    }
    else
    {
        cout << "Connected to database successfully" << endl;
    }

    query_state = mysql_query(connection, "SELECT * FROM sensores");

    cout << "\n\n\n";
    if (query_state != 0)
    {
        cout << "MySQL query error: " << mysql_error(connection) << endl;
    }
    else
    {
        MYSQL_RES *result = mysql_store_result(connection);
        if (result == NULL)
        {
            cout << "MySQL store result error: " << mysql_error(connection) << endl;
        }
        else
        {
            int num_fields = mysql_num_fields(result);
            MYSQL_ROW row;
            while ((row = mysql_fetch_row(result)))
            {
                for (int i = 0; i < num_fields; i++)
                {
                    cout << row[i] << " ";
                }
                cout << endl;
            }
            mysql_free_result(result);
        }
    }

    mysql_close(connection);
    cout << "\nMySQL CLIENT database closed\n";

    return 0;
}
