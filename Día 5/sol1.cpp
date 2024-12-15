/* Advent Of Code Día 5
  Parte 1 */

#include <iostream>
#include <fstream>   // Para manejar archivos
#include <sstream>   // Para procesar líneas
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    map<int, vector<int>> edges;
    string line;
    string fileName = "Dia5.2.txt"; // Nombre del archivo de entrada
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo: " << fileName << endl;
        return 1;
    }

    int solucion = 0; // Declarar e inicializar la variable solucion

    while (getline(inputFile, line)) {
        if (line.empty() || !isdigit(line[0])) {
            continue; // Saltar líneas vacías o que no comiencen con un dígito
        }

        int longitud = line.length();
        vector<int> v;
        bool es_tubo = false;

        for (int i = 0; i < longitud; i++) {
            if (isdigit(line[i])) {
                int x = 0;

                // Construir número desde los caracteres
                while (i < longitud && isdigit(line[i])) {
                    x = 10 * x + (line[i] - '0');
                    i++;
                }

                v.push_back(x);

                // Verificar si aparece un tubo '|'
                if (i < longitud && line[i] == '|') {
                    es_tubo = true;
                }
            }
        }

        if (es_tubo) {
            // Añadir al mapa de adyacencia
            edges[v[0]].push_back(v[1]);
        } else {
            vector<int> antes;
            bool orden = true;

            // Verificar el orden de las páginas según `edges`
            for (int i = 0; i < (int)v.size(); i++) {
                int x = v[i];
                for (int j = 0; j < (int)edges[x].size(); j++) {
                    int y = edges[x][j];

                    // Verificar si `y` está en `antes`
                    for (int k = 0; k < (int)antes.size(); k++) {
                        if (antes[k] == y) {
                            orden = false;
                            break; // Salir si se detecta un problema en el orden
                        }
                    }
                }
                if (!orden) break;

                // Añadir `x` a la lista de nodos procesados
                antes.push_back(x);
            }

            // Si el orden es válido, sumar la solución
            if (orden) {
                solucion += v[v.size() / 2];
            }
        }
    }

    // Mostrar la solución
    cout << "Solucion: " << solucion << endl;

    return 0;
}
