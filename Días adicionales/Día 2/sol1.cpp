/* Advent Of Code Día 2
  Parte 1 */

#include <iostream>
#include <fstream>   // Para manejar archivos
#include <sstream>   //Para procesar lineas
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// Función para comprobar si un reporte es seguro
bool ComprobarSeguro(const vector<int>& V) {
    bool Aumenta = true;    // Lineal positiva
    bool Disminuye = true;  // Lineal negativa

    for (size_t i = 0; i < V.size() - 1; i++) {
        int dif = V[i + 1] - V[i];

        if (abs(dif) < 1 || abs(dif) > 3) {         // Comprueba si no se llevan 1, 2 o 3
            return false;                           // Reporte inseguro
        }

        if (dif < 0) {
            Aumenta = false;                        // No es creciente
        }
        if (dif > 0) {
            Disminuye = false;                      // No es decreciente
        }
    }

    return Aumenta || Disminuye;                    // Es seguro si es creciente o decreciente
}

int main() {
    string fileName = "Dia2.txt";  // Nombre del archivo de entrada
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo: " << fileName << endl;
        return 1;
    }

    int seguros = 0; // Contador de reportes seguros
    string line;

    // Leer el archivo línea por línea
    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> report;
        int num;

        // Leer los números en la línea actual
        while (ss >> num) {
            report.push_back(num);
        }

        // Comprobar si el reporte es seguro
        if (!report.empty() && ComprobarSeguro(report)) {
            seguros++;
        }
    }

    inputFile.close(); // Cerrar el archivo

    // Imprimir el número total de reportes seguros
    cout << seguros << endl;

    return 0;
}
