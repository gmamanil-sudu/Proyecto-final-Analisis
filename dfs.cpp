#include "dfs.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Variables auxiliares usadas durante la busqueda
vector<bool> visitadoDFS;
vector<int> caminoActualDFS;
int contadorNodosDFS;

// Funcion recursiva que hace la busqueda en profundidad
// Se detiene apenas encuentra el destino (no busca la mejor, solo "una" ruta)
bool buscarDFS(Grafo &grafo, int actual, int destino, int distanciaAcumulada, int &distanciaFinal) {
    visitadoDFS[actual] = true;
    caminoActualDFS.push_back(actual);
    contadorNodosDFS++;

    if (actual == destino) {
        distanciaFinal = distanciaAcumulada;
        return true;
    }

    vector<Arista> vecinos = grafo.obtenerVecinos(actual);

    for (int i = 0; i < (int)vecinos.size(); i++) {
        int siguienteCiudad = vecinos[i].destino;
        int distanciaCarretera = vecinos[i].distancia;

        if (!visitadoDFS[siguienteCiudad]) {
            bool encontrado = buscarDFS(grafo, siguienteCiudad, destino,
                                         distanciaAcumulada + distanciaCarretera,
                                         distanciaFinal);
            if (encontrado) {
                return true; // ya se encontro la ruta, no seguir buscando
            }
        }
    }

    // Si no se encontro camino desde esta ciudad, se retrocede (se quita del camino)
    caminoActualDFS.pop_back();
    return false;
}

ResultadoDFS ejecutarDFS(Grafo &grafo, int origen, int destino) {
    ResultadoDFS resultado;

    // Reiniciar variables auxiliares para esta ejecucion
    int totalCiudades = grafo.obtenerNumeroCiudades();
    visitadoDFS.assign(totalCiudades, false);
    caminoActualDFS.clear();
    contadorNodosDFS = 0;

    int distanciaFinal = 0;

    // Medir tiempo de ejecucion con chrono
    auto inicio = high_resolution_clock::now();

    bool encontrado = buscarDFS(grafo, origen, destino, 0, distanciaFinal);

    auto fin = high_resolution_clock::now();
    duration<double, milli> duracion = fin - inicio;

    resultado.rutaEncontrada = encontrado;
    resultado.nodosVisitados = contadorNodosDFS;
    resultado.tiempoEjecucion = duracion.count();

    if (encontrado) {
        resultado.ruta = caminoActualDFS;
        resultado.distanciaTotal = distanciaFinal;
    } else {
        resultado.distanciaTotal = -1;
    }

    return resultado;
}