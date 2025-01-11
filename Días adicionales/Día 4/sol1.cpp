/* Day 4 Advent Of Code
  Parte 1 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Direcciones posibles: {x, y}
const vector<pair<int, int> > directions = {
    {0, 1},  // Derecha
    {0, -1}, // Izquierda
    {1, 0},  // Abajo
    {-1, 0}, // Arriba
    {1, 1},  // Abajo Derecha
    {1, -1}, // Abajo Izquierda
    {-1, 1}, // Arriba Derecha
    {-1, -1} // Arriba Izquierda
};

// Función que verifica si "XMAS" empieza desde la celda (x, y) en una dirección (dx, dy)
bool check_word(const vector<string> &grid, const string & word, int x, int y, int dx, int dy){
    // Declaración del número de filas y columnas 
    int rows = grid.size(); 
    int cols = grid[0].size(); 
    int n = word.length(); 

    for (int i = 0; i < n; i ++){
        int nx = x + i *dx; 
        int ny = y + i *dy; 

        // Verificar si la celda está dentro de los límites de la matriz
        if (nx < 0 || nx  >= rows || ny < 0 || ny >= cols){
            return false; 
        }

        // Comprobar que el caracter actual se corresponda con el caracter de la palabra
        if (grid[nx][ny] != word[i]){
            return false; 
        }
    }
    return true; 
}

// Función para contar las apariciones de la palabra
int count_word (const vector <string> &grid, const string &word){
    int rows = grid.size(); 
    int cols = grid[0].size(); 
    int count = 0; 

    for (int x = 0; x < rows; x++){
        for (int y = 0; y < cols; y++){
            // Buscar XMAS desde todas las direcciones
            for (const auto &[dx, dy] : directions){
                if (check_word(grid, word, x, y, dx, dy)){
                    count++; 
                }
            }
        }
    }

    return count; 
}

int main() {
    vector<string> grid;  
    string filename = "input.txt";
    string line; 

    // Leer el archivo de entrada
    ifstream file(filename); 
    if (!file){
        cerr << "No se pudo abrir el archivo: " << filename << endl; 
        return 1; 
    }

    while (getline(file, line)){
        grid.push_back(line); 
    }
    file.close(); 

    // Verificar que el archivo no esté vacío
    if (grid.empty()){
        cerr << "El archivo está vacío" << endl; 
        return 1; 
    }

    string word = "XMAS"; 

    int result = count_word(grid, word); 

    cout << "El número de apariciones de la palabra " << word << " es: " << result << endl; 

    return 0;  
}
