#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;

// Tipo auxiliar para representar la posición en la cuadrícula
struct Posicion {
    int fila;
    int columna;

    // Sobrecarga del operador < para usar Posicion en un set
    bool operator<(const Posicion& otra) const {
        return (fila < otra.fila) || (fila == otra.fila && columna < otra.columna);
    }
};

int predecirRutaGuardia(const vector<string>& mapa) {
    // Direcciones: Arriba, Derecha, Abajo, Izquierda
    vector<char> direcciones = {'^', '>', 'v', '<'};
    vector<Posicion> movimientos = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // Buscar la posición inicial del guardia y su dirección
    int filas = mapa.size();
    int columnas = mapa[0].size();
    int filaGuardia = -1, columnaGuardia = -1, indiceDireccion = -1;

    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            char celda = mapa[f][c];
            if (celda == '^' || celda == '>' || celda == 'v' || celda == '<') {
                filaGuardia = f;
                columnaGuardia = c;
                indiceDireccion = find(direcciones.begin(), direcciones.end(), celda) - direcciones.begin();
                break;
            }
        }
        if (filaGuardia != -1) break;
    }

    // Si no se encuentra al guardia, retornar un error
    if (filaGuardia == -1) {
        cout << "No se encontró al guardia en el mapa.\n";
        return 0;
    }

    // Verificar si la posición inicial está bloqueada
    if (mapa[filaGuardia][columnaGuardia] == '#') {
        cout << "La posición inicial del guardia está bloqueada por un obstáculo.\n";
        return 0;
    }

    // Conjunto para rastrear las posiciones visitadas
    set<Posicion> visitadas;
    visitadas.insert({filaGuardia, columnaGuardia});

    // Simular el movimiento del guardia
    while (true) {
        // Calcular la siguiente posición a partir de la dirección actual
        int nuevaFila = filaGuardia + movimientos[indiceDireccion].fila;
        int nuevaColumna = columnaGuardia + movimientos[indiceDireccion].columna;

        // Verificar si el guardia se sale del mapa
        if (nuevaFila < 0 || nuevaFila >= filas || nuevaColumna < 0 || nuevaColumna >= columnas) {
            break; // El guardia salió del mapa
        }

        // Verificar si hay un obstáculo al frente
        if (mapa[nuevaFila][nuevaColumna] == '#') {
            // Girar a la derecha
            indiceDireccion = (indiceDireccion + 1) % 4;
        } else {
            // Avanzar
            filaGuardia = nuevaFila;
            columnaGuardia = nuevaColumna;
            visitadas.insert({filaGuardia, columnaGuardia});
        }
    }

    // Retornar la cantidad de posiciones distintas visitadas
    return visitadas.size();
}

int main() {
    // Ejemplo de entrada
    ifstream entrada("input.txt");
    vector<string> mapa;
    string linea;
    
    if (!entrada.is_open()) {
        cout << "No se pudo abrir el archivo\n";
        return 1;
    }

    while (getline(entrada, linea)) {
        mapa.push_back(linea);
    }
    entrada.close();

    int resultado = predecirRutaGuardia(mapa);
    cout << "Número de posiciones distintas visitadas: " << resultado << endl;

    return 0;
}
