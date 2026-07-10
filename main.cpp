#include <iostream>
#include "grafo.h"

// Cuando Angelica y Heydy terminen sus modulos, aqui se agregaran:
// #include "dfs.h"
// #include "backtracking.h"

using namespace std;

void mostrarMenu() {
    cout << "\n========================================" << endl;
    cout << "SISTEMA DE RUTAS ENTRE CIUDADES" << endl;
    cout << "========================================" << endl;
    cout << "1. Mostrar mapa" << endl;
    cout << "2. Comparar estrategias" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void compararEstrategias(Grafo &grafo) {
    grafo.mostrarCiudades();

    string origen, destino;
    cout << "\nIngrese la ciudad de origen: ";
    cin >> origen;
    cout << "Ingrese la ciudad de destino: ";
    cin >> destino;

    int indiceOrigen = grafo.buscarIndice(origen);
    int indiceDestino = grafo.buscarIndice(destino);

    if (indiceOrigen == -1 || indiceDestino == -1) {
        cout << "\nUna de las ciudades ingresadas no existe." << endl;
        return;
    }

    cout << "\nBuscando ruta entre " << origen << " y " << destino << "..." << endl;

    // ---------------------------------------------------
    // AQUI SE LLAMARA AL ALGORITMO DFS (modulo de Angelica)
    // Ejemplo futuro:
    // ResultadoDFS resultadoDFS = ejecutarDFS(grafo, indiceOrigen, indiceDestino);
    // ---------------------------------------------------

    // ---------------------------------------------------
    // AQUI SE LLAMARA AL ALGORITMO BACKTRACKING (modulo de Heydy)
    // Ejemplo futuro:
    // ResultadoBacktracking resultadoBT = ejecutarBacktracking(grafo, indiceOrigen, indiceDestino);
    // ---------------------------------------------------

    cout << "\n(Los algoritmos DFS y Backtracking todavia no estan integrados)" << endl;

    // ---------------------------------------------------
    // AQUI SE MOSTRARA LA COMPARACION FINAL
    // usando los datos de resultadoDFS y resultadoBT
    // ---------------------------------------------------
}

int main() {
    Grafo grafo;
    grafo.inicializarMapa();

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                grafo.mostrarMapa();
                break;
            case 2:
                compararEstrategias(grafo);
                break;
            case 3:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion invalida." << endl;
        }

    } while (opcion != 3);

    return 0;
}