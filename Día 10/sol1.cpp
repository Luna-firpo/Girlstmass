/* Advent Of Code Day 10 
Parte 1
Encontrar caminos */

// camino = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

// Direcciones: arriba, abajo, izquierda, derecha
const vector<pair<int, int> > directions = {
    {0, -1}, {0, 1}, {-1, 0}, {1, 0}
}; 

// Función para verificar si la posición está dentro de los límites
bool is_valid_position(int x, int y, int rows, int cols) {
    if (x >= 0 && y >= 0 && x < rows && y < cols) {
        return true;
    } else { 
        return false; 
    }
}

// Función para explorar caminos desde un trailhead
void explore(const vector<vector<int> >& grid, vector<vector<bool> >& visited, int x, int y, set<pair<int, int> >& reachable_nines) {
    int rows = grid.size(); 
    int cols = grid[0].size();

    // Si la posición ya ha sido visitada, regresar
    if (visited[x][y])
        return; 
    
    // Marcar la posición como visitada
    visited[x][y] = true; 

    // Si se encuentra un 9, agregarlo a la lista de alcanzables
    if (grid[x][y] == 9) {
        reachable_nines.insert({x,y}); 
        return; //Cuando se encuentra un 9, no se sigue explorando
    }

    // Explorar en las 4 direcciones
    for (const auto& [dx, dy] : directions) {
        int nx = x + dx; 
        int ny = y + dy; 

        // Verificar si la nueva posición es válida
        if (is_valid_position(nx, ny, rows, cols)) {
            if(grid[nx][ny] == grid[x][y] +1) {
                explore(grid, visited, nx, ny, reachable_nines); 
            }
        }
    }
}

int total_sum (const vector<vector<int> >& grid, int start_x, int start_y) {
    int rows = grid.size(); 
    int cols = grid[0].size(); 

    // Conjunto para rastreas 9 alcanzables
    set<pair<int, int> > reachable_nines;

    // Matriz para rastrear las posiciones visitadas
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));

    // Iniciar la búsqueda recursiva desde el trailhead
    explore(grid, visited, start_x, start_y, reachable_nines);

    return reachable_nines.size(); 
}

int main() {
    // leer archivo de entrada
    string filename = "input.txt";
    ifstream file(filename);

    // Leer el archivo y construir matriz
    vector<vector<int> > grid;
    string line;
    while(getline(file, line)) {
        vector<int> row; 
        for (char c : line) {
            if (isdigit(c)) {
                row.push_back(c - '0'); // Convertir el carácter en un número
            }
        }
        grid.push_back(row); 
    }

    file.close(); 

    // Verificar si la matriz no está vacía 
    if (grid.empty()) {
        cerr << "No se pudo leer la matriz" << endl; 
        return 1; 
    }

    int rows = grid.size();
    int cols = grid[0].size();
    int total_score = 0; 

    // Buscar todos los trailheads (posiciones con valor 0)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 0) {
                total_score += total_sum(grid, i, j);
            }
        }
    }

    // Imprimir el resultado
    cout << "Puntaje total de trailheads: " << total_score << endl; 

    return 0; 
}
