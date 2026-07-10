#include <iostream>
#include "grafo.h"
#include "dfs.h"
#include "backtracking.h"

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

    // Ejecutar ambos algoritmos sobre el mismo grafo, origen y destino
    ResultadoDFS resultadoDFS = ejecutarDFS(grafo, indiceOrigen, indiceDestino);
    ResultadoBacktracking resultadoBT = ejecutarBacktracking(grafo, indiceOrigen, indiceDestino);

    // ---------- Mostrar resultado de DFS ----------
    cout << "\n===== RESULTADO DFS =====" << endl;
    if (resultadoDFS.rutaEncontrada) {
        cout << "Ruta: ";
        for (int i = 0; i < (int)resultadoDFS.ruta.size(); i++) {
            cout << grafo.obtenerNombreCiudad(resultadoDFS.ruta[i]);
            if (i < (int)resultadoDFS.ruta.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Distancia total: " << resultadoDFS.distanciaTotal << " km" << endl;
    } else {
        cout << "No se encontro ruta." << endl;
    }
    cout << "Nodos visitados: " << resultadoDFS.nodosVisitados << endl;
    cout << "Tiempo de ejecucion: " << resultadoDFS.tiempoEjecucion << " ms" << endl;

    // ---------- Mostrar resultado de Backtracking ----------
    cout << "\n===== RESULTADO BACKTRACKING =====" << endl;
    if (resultadoBT.rutaEncontrada) {
        cout << "Mejor ruta: ";
        for (int i = 0; i < (int)resultadoBT.mejorRuta.size(); i++) {
            cout << grafo.obtenerNombreCiudad(resultadoBT.mejorRuta[i]);
            if (i < (int)resultadoBT.mejorRuta.size() - 1) cout << " -> ";
        }
        cout << endl;
        cout << "Distancia minima: " << resultadoBT.distanciaMinima << " km" << endl;
    } else {
        cout << "No se encontro ruta." << endl;
    }
    cout << "Nodos visitados: " << resultadoBT.nodosVisitados << endl;
    cout << "Tiempo de ejecucion: " << resultadoBT.tiempoEjecucion << " ms" << endl;

    // ---------- Comparacion final ----------
    cout << "\n===== COMPARACION ENTRE ALGORITMOS =====" << endl;

    if (resultadoDFS.rutaEncontrada && resultadoBT.rutaEncontrada) {
        // Mejor solucion (menor distancia)
        if (resultadoDFS.distanciaTotal < resultadoBT.distanciaMinima) {
            cout << "Mejor solucion: DFS encontro una ruta mas corta." << endl;
        } else if (resultadoBT.distanciaMinima < resultadoDFS.distanciaTotal) {
            cout << "Mejor solucion: Backtracking encontro la ruta optima." << endl;
        } else {
            cout << "Ambos algoritmos encontraron la misma distancia." << endl;
        }

        // Mas rapido
        if (resultadoDFS.tiempoEjecucion < resultadoBT.tiempoEjecucion) {
            cout << "Algoritmo mas rapido: DFS." << endl;
        } else {
            cout << "Algoritmo mas rapido: Backtracking." << endl;
        }

        cout << "\nVentajas de DFS: rapido, usa poca memoria, sencillo de implementar." << endl;
        cout << "Desventajas de DFS: no garantiza la ruta mas corta." << endl;
        cout << "\nVentajas de Backtracking: garantiza la ruta optima (menor distancia)." << endl;
        cout << "Desventajas de Backtracking: mucho mas lento, explora mas nodos." << endl;
    } else {
        cout << "No se puede comparar: alguno de los algoritmos no encontro ruta." << endl;
    }
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