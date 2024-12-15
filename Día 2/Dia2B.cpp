#include <iostream>
#include <fstream>   // Para manejar archivos
#include <sstream>   // Para procesar lineas
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

        if (abs(dif) < 1 || abs(dif) > 3) {  // Comprueba si la diferencia no es 1, 2 o 3
            return false;
        }

        if (dif < 0) {
            Aumenta = false;  // No es creciente
        }
        if (dif > 0) {
            Disminuye = false;  // No es decreciente
        }
    }

    // El reporte es seguro si es creciente, decreciente
    return Aumenta || Disminuye;
}

// Función para verificar si un reporte se vuelve seguro al eliminar un único valor
bool ComprobarSeguroConEliminacion(vector<int>& V) {
    // Verificar si el reporte es seguro sin eliminar nada
    if (ComprobarSeguro(V)) {
        return true;
    }

    // Intentar eliminar cada valor una vez y comprobar si es segura
    for (size_t i = 0; i < V.size(); i++) {
        vector<int> V_copy = V;
        V_copy.erase(V_copy.begin() + i);                                               // Eliminar el valor en la posición i

        if (ComprobarSeguro(V_copy)) {
            return true;                                                                // Si la secuencia sin este valor es segura, devolver true
        }
    }

    return false;
}

int main() {
    string fileName = "input.txt";  // Nombre del archivo de entrada
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

        // Comprobar si el reporte es seguro (sin eliminar ni un valor o eliminando uno solo)
        if (!report.empty() && ComprobarSeguroConEliminacion(report)) {
            seguros++;
        }
    }

    inputFile.close(); // Cerrar el archivo

    // Imprimir el número total de reportes seguros
    cout << seguros << endl;

    return 0;
}
