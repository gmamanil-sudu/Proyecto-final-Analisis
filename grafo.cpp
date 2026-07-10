#include "grafo.h"
#include <iostream>

using namespace std;

void Grafo::agregarCiudad(string nombre) {
    ciudades.push_back(nombre);
    listaAdyacencia.push_back(vector<Arista>()); // espacio para sus carreteras
}

void Grafo::agregarCarretera(string ciudadOrigen, string ciudadDestino, int distancia) {
    int origen = buscarIndice(ciudadOrigen);
    int destino = buscarIndice(ciudadDestino);

    if (origen == -1 || destino == -1) {
        cout << "Error: una de las ciudades no existe." << endl;
        return;
    }

    // El grafo es no dirigido: la carretera funciona en ambos sentidos
    listaAdyacencia[origen].push_back({destino, distancia});
    listaAdyacencia[destino].push_back({origen, distancia});
}

int Grafo::buscarIndice(string nombre) {
    for (int i = 0; i < (int)ciudades.size(); i++) {
        if (ciudades[i] == nombre) {
            return i;
        }
    }
    return -1;
}

string Grafo::obtenerNombreCiudad(int indice) {
    return ciudades[indice];
}

int Grafo::obtenerNumeroCiudades() {
    return ciudades.size();
}

vector<Arista> Grafo::obtenerVecinos(int indice) {
    return listaAdyacencia[indice];
}

void Grafo::mostrarCiudades() {
    cout << "\nCiudades disponibles:" << endl;
    for (int i = 0; i < (int)ciudades.size(); i++) {
        cout << "- " << ciudades[i] << endl;
    }
}

void Grafo::mostrarMapa() {
    cout << "\n===== MAPA DE CIUDADES =====" << endl;
    for (int i = 0; i < (int)ciudades.size(); i++) {
        cout << ciudades[i] << " -> ";
        for (int j = 0; j < (int)listaAdyacencia[i].size(); j++) {
            int destino = listaAdyacencia[i][j].destino;
            int distancia = listaAdyacencia[i][j].distancia;
            cout << ciudades[destino] << "(" << distancia << "km) ";
        }
        cout << endl;
    }
}

void Grafo::inicializarMapa() {
    // Ciudades de ejemplo
    agregarCiudad("Arequipa");
    agregarCiudad("Lima");
    agregarCiudad("Cusco");
    agregarCiudad("Puno");
    agregarCiudad("Tacna");
    agregarCiudad("Moquegua");

    // Carreteras de ejemplo (origen, destino, distancia en km)
    agregarCarretera("Arequipa", "Lima", 1009);
    agregarCarretera("Arequipa", "Cusco", 521);
    agregarCarretera("Arequipa", "Puno", 297);
    agregarCarretera("Arequipa", "Moquegua", 213);
    agregarCarretera("Moquegua", "Tacna", 158);
    agregarCarretera("Puno", "Cusco", 388);
    agregarCarretera("Cusco", "Lima", 1105);
    agregarCarretera("Puno", "Tacna", 458);
}