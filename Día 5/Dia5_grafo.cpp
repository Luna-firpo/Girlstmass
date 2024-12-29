#include <iostream>
#include <fstream>   // Para trabajar con archivos
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

// Clase para representar un grafo
class Grafo {
private:
    map<int, vector<int>> conexiones; // Almacena las conexiones (lista de adyacencia)

public:
    // Método para agregar una conexión (arista) entre dos nodos
    void agregarConexion(int desde, int hasta) {
        conexiones[desde].push_back(hasta);
    }

    // Método para obtener los nodos conectados (vecinos) de un nodo
    vector<int> obtenerVecinos(int nodo) {
        if (conexiones.find(nodo) != conexiones.end()) {
            return conexiones[nodo];
        } else {
            return {}; // Si el nodo no tiene vecinos, devolver una lista vacía
        }
    }

    // Método para verificar si una lista de nodos está en un orden válido
    bool esOrdenValido(vector<int> nodos) {
        set<int> procesados; // Almacena los nodos que ya hemos procesado

        for (int nodo : nodos) {
            // Verificamos si algún vecino ya ha sido procesado
            for (int vecino : obtenerVecinos(nodo)) {
                if (procesados.count(vecino) > 0) {
                    return false; // Si un vecino ya está procesado, el orden no es válido
                }
            }
            // Marcamos el nodo como procesado
            procesados.insert(nodo);
        }

        return true; // Si no hay conflictos, el orden es válido
    }
};

int main() {
    Grafo grafo; // Crear un grafo
    string nombreArchivo = "input.txt"; // Nombre del archivo con los datos
    ifstream archivo(nombreArchivo); // Abrir el archivo

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    int solucion = 0; // Variable para almacenar la solución final
    string linea;     // Para leer cada línea del archivo

    while (getline(archivo, linea)) {
        if (linea.empty() || !isdigit(linea[0])) {
            continue; // Saltar líneas vacías o líneas que no empiezan con un número
        }

        vector<int> nodos; // Almacena los nodos leídos de la línea
        bool tieneConexion = false; // Indica si la línea representa una conexión

        // Leer los números de la línea
        for (int i = 0; i < linea.length(); i++) {
            if (isdigit(linea[i])) {
                int numero = 0;
                // Construir el número completo
                while (i < linea.length() && isdigit(linea[i])) {
                    numero = numero * 10 + (linea[i] - '0');
                    i++;
                }
                nodos.push_back(numero);

                // Si después del número hay un '|', es una conexión
                if (i < linea.length() && linea[i] == '|') {
                    tieneConexion = true;
                }
            }
        }

        if (tieneConexion && nodos.size() >= 2) {
            // Si la línea es una conexión, agregarla al grafo
            grafo.agregarConexion(nodos[0], nodos[1]);
        } else {
            // Si no es una conexión, verificar el orden de los nodos
            if (grafo.esOrdenValido(nodos)) {
                solucion += nodos[nodos.size() / 2]; // Sumar el nodo del medio
            }
        }
    }

    // Imprimir la solución final
    cout << "Solución: " << solucion << endl;

    return 0;
}

