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

#define HOST "db4free.net"       // host de la base de datos
#define USER "cortua_abellita"   // usuario de la base de datos
#define PASSWD "cortua_abellita" // contraseña de la base de datos
#define DB "base_datos_alse"     // nombre de la base de datos

string get_current_date()
{
    time_t now = time(nullptr);
    char date_str[20];
    strftime(date_str, sizeof(date_str), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(date_str);
}

int main(int argc, char **argv)
{
    sqlite3 *db;                       // puntero que apunta a la base de datos db_name.db
    sqlite3_stmt *statement;           // puntero que apunta a una consulta de base de datos
    char *zErrMsg = 0;                 // puntero que apunta a un mensaje de error
    int rc;                            // variable que almacena el codigo de retorno de sqlite3
    string sqlstr;                     // variable que almacena la consulta de base de datos
    string sql;                        // variable que almacena la consulta de base de datos
    string fecha = get_current_date(); // fecha actual
    int ts = atoi(argv[1]);            // tiempo de muestreo

    /* crear la tabla de sensores */
    rc = sqlite3_open("db_name.db", &db);
    // verificar si se abrio la base de datos
    if (rc != 0)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n\n");
    }
    // creamos la tabla sesores en la base de datos db:name.db
    sqlstr = "CREATE TABLE IF NOT EXISTS sensores_pc (ID INTEGER PRIMARY KEY AUTOINCREMENT, SENSOR TEXT NOT NULL,"
             "MINIMO INTEGER NOT NULL, PROMEDIO INTEGER NOT NULL,"
             "MAXIMO INTEGER NOT NULL, FECHA TEXT NOT NULL);";

    rc = sqlite3_exec(db, sqlstr.c_str(), 0, 0, &zErrMsg);

    // sqlite3_close(db);

    // crear los sensores
    vector<float> temp;   // vector que almacena las temperaturas
    vector<float> hum;    // vector que almacena las humedades
    vector<float> vel;    //   vector que almacena las velocidades
    vector<float> viento; // vector que almacena los vientos
    vector<float> prec;   // vector que almacena las precipitaciones
    vector<float> luz;    // vector que almacena las luces

    // llenar los sensores
    for (int i = 0; i < (60 / ts); i++)
    {
        Temperatura t;                         // objeto de la clase Temperatura
        t.set_temperatura();                   // asignar un valor a la temperatura
        temp.push_back(t.get_temperatura());   // agregar la temperatura al vector
        Humedad h;                             // objeto de la clase Humedad
        h.set_humedad();                       // asignar un valor a la humedad
        hum.push_back(h.get_humedad());        // agregar la humedad al vector
        Velocidad v;                           // objeto de la clase Velocidad
        v.set_velocidad();                     // asignar un valor a la velocidad
        vel.push_back(v.get_velocidad());      // agregar la velocidad al vector
        Viento vi;                             // objeto de la clase Viento
        vi.set_viento();                       // asignar un valor al viento
        viento.push_back(vi.get_viento());     // agregar el viento al vector
        Precipitacion p;                       // objeto de la clase Precipitacion
        p.set_precipitacion();                 // asignar un valor a la precipitacion
        prec.push_back(p.get_precipitacion()); // agregar la precipitacion al vector
        Luz l;                                 // objeto de la clase Luz
        l.set_luz();                           // asignar un valor a la luz
        luz.push_back(l.get_luz());            // agregar la luz al vector
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

    float minTemp = Sensor::min(60 / ts, temp);       // minimo de las temperaturas
    float maxTemp = Sensor::max(60 / ts, temp);       // maximo de las temperaturas
    float promTemp = Sensor::prom(60 / ts, temp);     // promedio de las temperaturas
    float minHum = Sensor::min(60 / ts, hum);         // minimo de las humedades
    float maxHum = Sensor::max(60 / ts, hum);         // maximo de las humedades
    float promHum = Sensor::prom(60 / ts, hum);       // promedio de las humedades
    float minVel = Sensor::min(60 / ts, vel);         // minimo de las velocidades
    float maxVel = Sensor::max(60 / ts, vel);         // maximo de las velocidades
    float promVel = Sensor::prom(60 / ts, vel);       // promedio de las velocidades
    float minViento = Sensor::min(60 / ts, viento);   // minimo de los vientos
    float maxViento = Sensor::max(60 / ts, viento);   // maximo de los vientos
    float promViento = Sensor::prom(60 / ts, viento); // promedio de los vientos
    float minPrec = Sensor::min(60 / ts, prec);       // minimo de las precipitaciones
    float maxPrec = Sensor::max(60 / ts, prec);       // maximo de las precipitaciones
    float promPrec = Sensor::prom(60 / ts, prec);     // promedio de las precipitaciones
    float minLuz = Sensor::min(60 / ts, luz);         // minimo de las luces
    float maxLuz = Sensor::max(60 / ts, luz);         // maximo de las luces
    float promLuz = Sensor::prom(60 / ts, luz);       // promedio de las luces

    // verificacion de los datos
    cout << "Tiempo de muestreo: " << ts << " .Numero de muestreas: " << 60 / ts << endl;
    cout << "Fecha: " << fecha << "\n\n";
    // verificacion de los datos
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
        return 1;
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }

    // Conectar a la base de datos remota
    if (mysql_real_connect(connection, HOST, USER, PASSWD, DB, 0, NULL, 0) == NULL)
    {
        cout << "\n\nFailed to connect to database: " << mysql_error(connection) << endl;
        return 1;
    }
    else
    {
        cout << "\n\nConnected to database successfully" << endl;
    }
    // Obtener los datos de la tabla sensores de la base de datos local sensores_pc
    sql = "SELECT * FROM sensores_pc";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, &zErrMsg);
    sqlite3_prepare_v2(db, sql.c_str(), -1, &statement, NULL); // preparar la consulta

    // Insertar los datos en la tabla sensores de la base de datos en la nube
    while (sqlite3_step(statement) == SQLITE_ROW) // obtener los datos de la consulta fila por fila
    {
        int id = sqlite3_column_int(statement, 0);                                         // obtiene el id de cada fila
        string sensor = reinterpret_cast<const char *>(sqlite3_column_text(statement, 1)); // se guarda el sensor
        float minimo = static_cast<float>(sqlite3_column_double(statement, 2));            // se guarda el minimo
        float promedio = static_cast<float>(sqlite3_column_double(statement, 3));          // se guarda el promedio
        float maximo = static_cast<float>(sqlite3_column_double(statement, 4));            // se guarda el maximo
        string fecha = reinterpret_cast<const char *>(sqlite3_column_text(statement, 5));  // se guarda la fecha
        // insertar los datos en la base de datos en la nube
        string insertQuery = "INSERT IGNORE INTO sensores (ID, SENSOR, MINIMO, PROMEDIO, MAXIMO, FECHA) VALUES ('" + to_string(id) + "','" +
                             sensor + "', " + to_string(minimo) + ", " + to_string(promedio) + ", " +
                             to_string(maximo) + ", '" + fecha + "')";
        if (mysql_query(connection, insertQuery.c_str()) != 0)
        {
            fprintf(stderr, "Failed to insert data into cloud database: %s\n", mysql_error(connection));
            return 1;
        }
    }
    cout << "\n\nBase de datos copiada exitosamente a la nube" << endl;

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

    sqlite3_finalize(statement);
    sqlite3_close(db);
    mysql_close(connection);
    cout << "\nMySQL CLIENT database closed\n\n";

    return 0;
}