#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

class TablaHash {
private:
    unordered_map<int, unordered_set<int>> uniones; 

public:
    // añade una unión entre dos nodos
    void agregarUnion(int ini, int fin) {
        uniones[ini].insert(fin);
    }

    // Obtener vecinos de un nodo
    unordered_set<int> obtenerVecinos(int nodo) {
        if (uniones.find(nodo) != uniones.end()) {
            return uniones[nodo];
        } 
    }

    //Comprobar si la lista tiene un orden válido
    bool OrdenValido(vector<int> nodos) {
        set<int> nodo_procesado; // Almacena los nodos que ya hemos procesado

        for (int nodo : nodos) {
            // Comprobamos si algún vecino ya ha sido procesado
            for (int vecino : obtenerVecinos(nodo)) {
                if (nodo_procesado.count(vecino) > 0) {
                    return false; // Si un vecino ya está procesado, el orden no es válido
                }
            }
            // Marcamos el nodo como procesado
            nodo_procesado.insert(nodo);
        }
        return true; // Si no hay conflictos, el orden es válido
    }
};

int main() {
    TablaHash hash; // Crear una tabla hash
    
    ifstream archivo("input.txt"); // Abrir el archivo

    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo"<< endl;
        return 1;
    }

    int res = 0; 
    string linea; 

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

                if (i < linea.length() && linea[i] == '|') {
                    tieneConexion = true;
                }
            }
        }

        if (tieneConexion && nodos.size() >= 2) {
            // Si la línea es una conexión, agregarla a la tabla hash
            hash.agregarUnion(nodos[0], nodos[1]);
        } else {
            // Si no es una conexión, verificar el orden de los nodos
            if (hash.OrdenValido(nodos)) {
                res += nodos[nodos.size() / 2]; // Sumar el nodo del medio
            }
        }
    }

    // Imprimir la solución final
    cout << "Resultado: " << res << endl;

    return 0;
}
