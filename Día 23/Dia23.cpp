#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Paso 1: Leer el archivo y construir el grafo como una matriz de adyacencia
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error: No se pudo abrir el archivo input.txt" << endl;
        return 1;
    }

    unordered_map<string, int> nodeIndex; // Mapea cada nodo (nombre) a un índice único.
    vector<string> nodes; // Almacena los nombres originales de los nodos para poder mapear índices de vuelta a nombres.
    vector<pair<int, int>> edges; // Lista de aristas: cada par (u, v) indica una conexión entre los nodos u y v.
    string line;

    // Leer conexiones y asignar índices
    while (getline(inputFile, line)) {
        size_t dash = line.find('-');
        string a = line.substr(0, dash); // Nodo inicial de la arista.
        string b = line.substr(dash + 1); // Nodo final de la arista.

        // Asignar un índice único a cada nodo
        if (!nodeIndex.count(a)) {
            nodeIndex[a] = nodes.size(); // Asignar el siguiente índice disponible.
            nodes.push_back(a); // Guardar el nombre del nodo.
        }
        if (!nodeIndex.count(b)) {
            nodeIndex[b] = nodes.size(); // Asignar el siguiente índice disponible.
            nodes.push_back(b); // Guardar el nombre del nodo.
        }

        edges.emplace_back(nodeIndex[a], nodeIndex[b]); // Agregar la arista como pares de índices.
    }
    inputFile.close();

    int n = nodes.size(); // Número total de nodos en el grafo.

    // Matriz de adyacencia: adjMatrix[i][j] = 1 si hay una conexión entre los nodos i y j, 0 en caso contrario.
    vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

    // Rellenar la matriz de adyacencia usando las aristas
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    // Paso 2: Programación dinámica para buscar triángulos
    // DP: dp[k][j] indica si existe un triángulo con los nodos k, j y algún nodo i (donde i < k y i < j).
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int triangleCount = 0; // Número total de triángulos encontrados.
    int filteredCount = 0; // Número de triángulos que contienen al menos un nodo que empieza con 't'.

    // Buscar triángulos en el grafo
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < k; ++j) {
            for (int i = 0; i < j; ++i) {
                // Si i, j y k están conectados mutuamente, forman un triángulo
                if (adjMatrix[i][j] && adjMatrix[i][k] && adjMatrix[j][k]) {
                    dp[k][j] = true;
                    triangleCount++;

                    // Verificar si alguno de los nodos del triángulo comienza con 't'
                    if (nodes[i][0] == 't' || nodes[j][0] == 't' || nodes[k][0] == 't') {
                        filteredCount++;
                    }
                }
            }
        }
    }

    // Paso 3: Mostrar resultados
    cout << "Número total de triángulos encontrados: " << triangleCount << endl;
    cout << "Número de triángulos que contienen nodos con 't': " << filteredCount << endl;

    return 0;
}
