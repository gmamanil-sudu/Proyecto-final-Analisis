#include "backtracking.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Variables auxiliares usadas durante la busqueda
vector<bool> visitadoBT;
vector<int> caminoActualBT;
vector<int> mejorCaminoBT;
int mejorDistanciaBT;
int contadorNodosBT;
bool seEncontroRutaBT;

// Funcion recursiva que prueba TODAS las rutas posibles y se queda con la mejor
void buscarBacktracking(Grafo &grafo, int actual, int destino, int distanciaAcumulada) {
    visitadoBT[actual] = true;
    caminoActualBT.push_back(actual);
    contadorNodosBT++;

    if (actual == destino) {
        // Se encontro una ruta completa: comparar con la mejor hasta ahora
        if (!seEncontroRutaBT || distanciaAcumulada < mejorDistanciaBT) {
            mejorDistanciaBT = distanciaAcumulada;
            mejorCaminoBT = caminoActualBT;
            seEncontroRutaBT = true;
        }
    } else {
        vector<Arista> vecinos = grafo.obtenerVecinos(actual);

        for (int i = 0; i < (int)vecinos.size(); i++) {
            int siguienteCiudad = vecinos[i].destino;
            int distanciaCarretera = vecinos[i].distancia;

            if (!visitadoBT[siguienteCiudad]) {
                buscarBacktracking(grafo, siguienteCiudad, destino,
                                    distanciaAcumulada + distanciaCarretera);
            }
        }
    }

    // Retroceder: quitar la ciudad actual y desmarcarla para probar otras rutas
    caminoActualBT.pop_back();
    visitadoBT[actual] = false;
}

ResultadoBacktracking ejecutarBacktracking(Grafo &grafo, int origen, int destino) {
    ResultadoBacktracking resultado;

    // Reiniciar variables auxiliares para esta ejecucion
    int totalCiudades = grafo.obtenerNumeroCiudades();
    visitadoBT.assign(totalCiudades, false);
    caminoActualBT.clear();
    mejorCaminoBT.clear();
    mejorDistanciaBT = 0;
    contadorNodosBT = 0;
    seEncontroRutaBT = false;

    // Medir tiempo de ejecucion con chrono
    auto inicio = high_resolution_clock::now();

    buscarBacktracking(grafo, origen, destino, 0);

    auto fin = high_resolution_clock::now();
    duration<double, milli> duracion = fin - inicio;

    resultado.rutaEncontrada = seEncontroRutaBT;
    resultado.nodosVisitados = contadorNodosBT;
    resultado.tiempoEjecucion = duracion.count();

    if (seEncontroRutaBT) {
        resultado.mejorRuta = mejorCaminoBT;
        resultado.distanciaMinima = mejorDistanciaBT;
    } else {
        resultado.distanciaMinima = -1;
    }

    return resultado;
}