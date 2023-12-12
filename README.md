# PROYECTO_ALSE

Proyecto desarrollado por Santiago Cortes Tovar y Juan Andrés Abella Ballen, utilizando C/C++, SQLite, Git, GitHub, CMake y Qt5.

> **Nota:** Este proyecto tiene como objetivo utilizar C/C++, SQLite, Git, GitHub, CMake y Qt5.

## Descripción del Proyecto

Se ha creado una clase base llamada "Sensor" que será heredada por los siguientes 6 sensores. Estos sensores comparten atributos y métodos similares.

> **Importante:** A continuación se describen los sensores y sus respectivos rangos de medición.

### Sensores

1. **Temperatura**: Rango de medición: 10°C a 45°C.
2. **Humedad**: Rango de medición: 0% a 100%.
3. **Velocidad**: Rango de medición: 0 m/s a 40 m/s.
4. **Dirección del Viento**: Rango de medición: -180° a 180° (Norte).
5. **Precipitación**: Rango de medición: 0 mm a 50 mm.
6. **Intensidad de Luz**: Rango de medición: 0 a 2000 lúmenes.

> **Advertencia:** Todas las mediciones se realizarán a intervalos regulares y se almacenarán en una base de datos junto con la fecha de captura de los datos.

#### Ejemplos de Muestras

- Cada 5 segundos: 12 muestras
- Cada 6 segundos: 10 muestras
- Cada 7 segundos: 9 muestras
- Cada 8 segundos: 8 muestras
- Cada 9 segundos: 7 muestras
- Cada 10 segundos: 6 muestras
- Cada 11 segundos: 5 muestras
- Cada 12 segundos: 5 muestras
- Cada 13 segundos: 4 muestras
- Cada 14 segundos: 4 muestras
- Cada 15 segundos: 4 muestras
- Cada 16 segundos: 3 muestras
- Cada 17 segundos: 3 muestras
- Cada 18 segundos: 3 muestras
- Cada 19 segundos: 3 muestras
- Cada 20 segundos: 3 muestras
