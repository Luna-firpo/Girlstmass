/* Advent Of Code Day 10
Parte 2 
Posibles caminos */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Direcciones: arriba, abajo, izquierda, derecha
const vector<pair<int, int> > directions = {
    {0, -1}, {0, 1}, {-1, 0}, {1, 0}
};

// Función para verificar si una posicón es válida
bool is_valid_position(int x, int y, int rows, int cols) {
    if (x >= 0 && y >= 0 && x < rows && y < cols) {
        return true;
    } else {
        return false;
    }
}

// Función recursiva para contar rutas válidas desde una celda
int count_trails (const vector<vector<int> > &map, vector<vector<bool> > &visited, int x, int y, int current_height) {
    int rows = map.size(); 
    int cols = map[0].size(); 

    // Comprobar si la celda está fuera del mapa, no es válida o ya está visitada
    if (!is_valid_position(x, y, rows, cols) || visited[x][y]) 
        return 0; 
    
    if (map[x][y] != current_height) 
        return 0;

    // Si se llega a un 9, se ha encontrado una ruta válida
    if (map[x][y] == 9) {
        cout << "Ruta válida encontrada" << endl;
        return 1;
    }

    // Marcar la celda como visitada
    visited[x][y] = true;

    int total_trails = 0; 

    // Explorar en las 4 direcciones
    for (const auto &[dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;

        if (is_valid_position(nx, ny, rows, cols)) {
            if (map[nx][ny] == map[x][y] + 1) {
                total_trails += count_trails(map, visited, nx, ny, current_height + 1);
            }
        }
    }

    // Desmarcar la celda
    visited[x][y] = false; 

    return total_trails; 
}

int calculate_total (const vector<vector<int> > &map) {
    int rows = map.size(); 
    int cols = map[0].size(); 
    int total_rating = 0; 

    // Recorrer el mapa en busca de trailheads (celdas con valor 0)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 0) {
                // Inicializar un vector de visitados
                vector<vector<bool> > visited(rows, vector<bool>(cols, false));

                // Contar las rutas válidas desde el trailhead
                int rating = count_trails(map, visited, i, j, 0); 
                total_rating += rating; 
            }
        }
    } 

    return total_rating;
}

// Leer el mapa desde un archivo
vector<vector<int> > read_map (const string &filename) {
    ifstream file (filename); 
    vector<vector<int> > map; 
    string line; 

    while (getline(file, line)) {
        vector<int> row; 
        for (char c : line) {
            row.push_back(c - '0');
        }
        map.push_back(row); 
    }

    file.close(); 
    return map; 
}

int main() {
    string filename = "input.txt"; 

    // Leer el mapa desde el archivo
    vector<vector<int> > map = read_map(filename);

    // Calcular el total de rutas válidas
    int total_rating = calculate_total(map);

    // Imprimir el resultado
    cout << "Total de rutas válidas: " << total_rating << endl;

    return 0;
}