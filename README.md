# SmartRoute

## Descripción del proyecto

SmartRoute es un sistema desarrollado en C++ que permite encontrar rutas entre ciudades representadas mediante un grafo ponderado. El proyecto compara el comportamiento de dos estrategias de búsqueda: DFS y Backtracking, mostrando la ruta encontrada, la distancia recorrida, el tiempo de ejecución y la cantidad de nodos visitados.

El objetivo del proyecto es analizar el desempeño de ambas estrategias para determinar sus ventajas, limitaciones y comportamiento al resolver un mismo problema.

## Integrantes del equipo

- Grecia Mamani Larico
- Heydy Castillo Arocutipa
- Angélica Huaman Cuba
- Albana Elizabeth Vásquez Paredes

## Instrucciones de ejecución

### Requisitos

- Compilador compatible con C++11 o superior.
- Visual Studio Code, Code::Blocks, Dev-C++ o cualquier IDE que soporte C++.

### Uso

1. Ejecutar el programa.
2. Seleccionar la ciudad de origen.
3. Seleccionar la ciudad de destino.
4. El sistema ejecutará los algoritmos DFS y Backtracking.
5. Finalmente se mostrará la ruta encontrada, la distancia, el tiempo de ejecución y la cantidad de nodos visitados por cada estrategia.

## Estrategias implementadas

### Depth-First Search (DFS)

DFS realiza una búsqueda en profundidad explorando un camino hasta el fondo antes de regresar para continuar con otra alternativa. Su principal ventaja es encontrar rápidamente una ruta válida, aunque no garantiza que sea la de menor distancia.

Complejidad temporal: O(n)

Complejidad espacial: O(n)

### Backtracking

Backtracking explora diferentes rutas posibles entre la ciudad de origen y la ciudad de destino. Cada vez que encuentra una solución compara la distancia obtenida con la mejor encontrada, conservando únicamente la ruta más corta.

Complejidad temporal: O(2ⁿ)

Complejidad espacial: O(n)

## Funcionalidades

- Representación de un mapa mediante grafos ponderados.
- Búsqueda de rutas entre ciudades.
- Comparación entre DFS y Backtracking.
- Cálculo de la distancia recorrida.
- Medición del tiempo de ejecución.
- Conteo de nodos visitados.
