cmake_minimum_required(VERSION 3.10)

project(proyecto)

add_executable(proyecto main.cpp Sensor.cpp Sensor.h Temperatura.cpp Temperatura.h Humedad.cpp Humedad.h Precipitacion.cpp Precipitacion.h Velocidad.cpp Velocidad.h Luz.cpp Luz.h Viento.cpp Viento.h)

target_link_libraries(proyecto sqlite3) 
target_link_libraries(proyecto mysqlclient)