#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <vector>
#include <string>
#include "grafo.h"

using namespace std;

// Estructura para devolver los resultados del Backtracking a main.cpp
struct ResultadoBacktracking {
    vector<int> mejorRuta;      // secuencia de indices de ciudades (la mejor ruta)
    int distanciaMinima;        // distancia de la mejor ruta encontrada
    double tiempoEjecucion;     // tiempo en milisegundos
    int nodosVisitados;         // cantidad de nodos explorados (todas las llamadas)
    bool rutaEncontrada;        // indica si se encontro al menos una ruta
};

ResultadoBacktracking ejecutarBacktracking(Grafo &grafo, int origen, int destino);

#endif