#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

struct Region {
    int area = 0;
    int perimeter = 0;
};

void procesar_region(const vector<string>& mapa, int i, int j, vector<vector<bool>>& visitado, char letra, Region& region) {
    // Establecer los bordes de la región y contar la área
    if (i < 0 || i >= mapa.size() || j < 0 || j >= mapa[i].size() || visitado[i][j] || mapa[i][j] != letra) {
        return;
    }

    // Marcar como visitado
    visitado[i][j] = true;
    region.area++;

    // Verificar los 4 posibles bordes: arriba, abajo, izquierda y derecha
    if (i == 0 || mapa[i-1][j] != letra) region.perimeter++;  // Arriba
    if (i == mapa.size() - 1 || mapa[i+1][j] != letra) region.perimeter++;  // Abajo
    if (j == 0 || mapa[i][j-1] != letra) region.perimeter++;  // Izquierda
    if (j == mapa[i].size() - 1 || mapa[i][j+1] != letra) region.perimeter++;  // Derecha

    // Recursión para los vecinos
    procesar_region(mapa, i-1, j, visitado, letra, region);  // Arriba
    procesar_region(mapa, i+1, j, visitado, letra, region);  // Abajo
    procesar_region(mapa, i, j-1, visitado, letra, region);  // Izquierda
    procesar_region(mapa, i, j+1, visitado, letra, region);  // Derecha
}

int main() {
    ifstream fichero("fichero_dia12.txt");
    if (!fichero) {
        cout << "No se puede abrir el archivo\n";
        return 0;
    }

    vector<string> mapa;
    string linea;

    // Leer el mapa
    while (getline(fichero, linea)) {
        mapa.push_back(linea);
    }

    fichero.close();  // Cerrar el archivo

    vector<vector<bool>> visitado(mapa.size(), vector<bool>(mapa[0].size(), false));
    unordered_set<char> plant_types;  // Para rastrear las plantas diferentes
    vector<Region> regiones;

    // Procesar todas las celdas del mapa
    for (int i = 0; i < mapa.size(); i++) {
        for (int j = 0; j < mapa[i].size(); j++) {
            char letra = mapa[i][j];
            if (isupper(letra) && !visitado[i][j]) {  // Si la celda es una letra mayúscula y no se ha visitado
                Region region;
                procesar_region(mapa, i, j, visitado, letra, region);
                regiones.push_back(region);
                plant_types.insert(letra);  // Registrar el tipo de planta
            }
        }
    }

    // Calcular el precio total
    int precio_total = 0;
    for (const Region& region : regiones) {
        precio_total += region.area * region.perimeter;
    }

    // Imprimir el precio total
    cout << "Precio total de la cerca: " << precio_total << endl;

    return 0;
}
