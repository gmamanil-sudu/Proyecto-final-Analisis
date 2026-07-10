#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>

using namespace std;

// Representa una carretera hacia otra ciudad
struct Arista {
    int destino;
    int distancia;
};

class Grafo {
private:
    vector<string> ciudades;                  // nombres de las ciudades
    vector<vector<Arista>> listaAdyacencia;    // carreteras de cada ciudad

public:
    void agregarCiudad(string nombre);
    void agregarCarretera(string ciudadOrigen, string ciudadDestino, int distancia);

    void mostrarMapa();
    void mostrarCiudades();

    int buscarIndice(string nombre);
    string obtenerNombreCiudad(int indice);
    int obtenerNumeroCiudades();
    vector<Arista> obtenerVecinos(int indice);

    void inicializarMapa(); // carga las ciudades y carreteras de ejemplo
};

#endif