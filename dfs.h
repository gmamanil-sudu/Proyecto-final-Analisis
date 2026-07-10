#ifndef DFS_H
#define DFS_H

#include <vector>
#include <string>
#include "grafo.h"

using namespace std;

// Estructura para devolver los resultados del DFS a main.cpp
struct ResultadoDFS {
    vector<int> ruta;          // secuencia de indices de ciudades (la ruta encontrada)
    int distanciaTotal;        // suma de distancias de la ruta
    double tiempoEjecucion;    // tiempo en milisegundos
    int nodosVisitados;        // cantidad de nodos explorados
    bool rutaEncontrada;       // indica si se encontro una ruta
};

ResultadoDFS ejecutarDFS(Grafo &grafo, int origen, int destino);

#endif