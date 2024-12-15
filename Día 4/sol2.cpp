/*
Day 4 Advent Of Code
Parte 2 
Busqueda de la palabra XMAS en cruz
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Función que verifica si "MAS" está centrado en (x,y)
bool check_mas(const vector <string> &grid, int x, int y){
    int rows = grid.size(); 
    int cols = grid[0].size(); 
    
    // Verificar que los índices no se salgan de los límites
    if (x-1 < 0 || x+1 >=rows || y-1 < 0 || y+1 >= cols){
        return false; 
    }

    // Verificar si el patrón es 
    /*  M   .   M
        .   A   .
        S   .   S    */

    if (grid[x][y] == 'A'){
        if (grid[x-1][y+1] == 'M' && grid[x+1][y-1] == 'S'){
            if ((grid[x+1][y+1] == 'M' && grid[x-1][y-1] == 'S') ||
                (grid[x-1][y-1] == 'M' && grid[x+1][y+1] == 'S')) {
                return true; 
            }
        return false; 
        }

        if (grid[x+1][y-1] == 'M' && grid[x-1][y+1] == 'S'){
            if ((grid[x+1][y+1] == 'M' && grid[x-1][y-1] == 'S') ||
                (grid[x-1][y-1] == 'M' && grid[x+1][y+1] == 'S')){
                return true; 
            }
            return false; 
        }
    }
    return false; 
}

// Función para contar las apariciones de la palabra
int count_mas (const vector <string> &grid){
    int rows = grid.size(); 
    int cols = grid[0].size(); 
    int count = 0;

    for (int x = 1; x < rows-1; x++){
        for (int y = 1; y < cols-1; y++){
            if (check_mas(grid, x, y)){
                count++; 
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

    int result = count_mas(grid);

    cout << "El número de apariciones de la palabra MAS es: " << result << endl;

    return 0;
}