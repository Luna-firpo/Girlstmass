#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
void ver_vector(vector<int>& resultado){
    for(int i = 0; i < resultado.size(); i++){
        cout << resultado[i] << ' ';
        
    }
    cout << endl;
}
void ordenar_vector(const vector<int>& numeros, vector<int>& resultado) {
    int orden_par = 0;
    for (size_t i = 0; i < numeros.size(); i++) {
        int valor = numeros[i];
        if (i % 2 == 0) {
            if (i > 0) orden_par++;
            for (int j = 0; j < valor; j++) {
                resultado.push_back(orden_par);
            }
        } else {
            for (int j = 0; j < valor; j++) {
                resultado.push_back(-1);
            }
        }
    }
    ver_vector(resultado);
}


void mover_puntos(vector<int>& resultado, size_t ini, size_t fin) {
    while (ini < fin) {
        if (resultado[ini] == -1 && resultado[fin] != -1) {
            swap(resultado[ini], resultado[fin]);
            ini++;
            fin--;
        } else if (resultado[ini] != -1 && resultado[fin] != -1) {
            ini++;
        } else if (resultado[ini] == -1 && resultado[fin] == -1) {
            fin--;
        } else {
            ini++;
            fin--;
        }
       
    }
    ver_vector(resultado);
}

long long operacion(const vector<int>& resultado) {
    long long solucion = 0;
    for (size_t a = 0; a < resultado.size(); a++) {
        if ((resultado[a])> 0) {
            int res = resultado[a];
            solucion += a * res;
        }
    }
    return solucion;
}

int main() {
    vector<int> numeros;
    vector<int> resultado;
    string linea;
    ifstream fichero("fichero_dia9.txt");

    if (!fichero.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return 1;
    }

    while (getline(fichero, linea)) {
        if (!linea.empty()) {
            for (char num : linea) {
                if (isdigit(num)) {
                    numeros.push_back(num - '0');
                }
            }

            ordenar_vector(numeros, resultado);
            mover_puntos(resultado, 0, resultado.size() - 1);
            long long res = operacion(resultado);
            cout << "El resultado es: " << res << endl;                                   //DYV UNA MEZCLA SENCILLO, PROG DINÁMICA AÑADIR FUNCIÓN MEMORIA Y OTRO COMPLETO
                                                                                          //FIB, MONEDOA Y MOCHILA, TUBOS DE PROG DINÁMICA
            resultado.clear();
            numeros.clear();
        }
    }

    fichero.close();
    return 0;
}


/*opción 2
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int procesar_linea(const string& linea) {
    int solucion = 0;
    int indice_global = 0; // Índice global para calcular posiciones en el resultado
    int orden_par = 0;     // Contador de bloques pares

    for (char num : linea) {
        if (isdigit(num)) {
            int valor = num - '0';
            if (indice_global % 2 == 0) {
                // Caso posición par: números
                if (indice_global > 0) orden_par++;
                for (int j = 0; j < valor; j++) {
                    solucion += indice_global * orden_par; // Acumulamos directamente
                    indice_global++;
                }
            } else {
                // Caso posición impar: puntos
                indice_global += valor; // Avanzamos el índice global sin acumular
            }
        }
    }

    return solucion;
}

int main() {
    ifstream fichero("fichero_dia9.txt");
    if (!fichero.is_open()) {
        cerr << "No se pudo abrir el archivo.\n";
        return 1;
    }

    string linea;
    while (getline(fichero, linea)) { // Leer línea a línea
        if (!linea.empty()) {
            int resultado = procesar_linea(linea);
            cout << "El resultado es: " << resultado << endl;
        }
    }
    fichero.close();

    return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

void ordenar_vector(vector<int>& numeros, vector<char>& resultado, int i = 0, int orden_par = 0) {
    if (i >= numeros.size()) {
        return;
    }

    int valor = numeros[i]; // Tomamos el número actual

    if (i % 2 == 0) {
        // Caso: posición par (números)
        if (i > 0) orden_par++; // Incrementamos el valor para posiciones pares después de la primera
        for (int j = 0; j < valor; j++) {
            resultado.push_back('0' + orden_par);
        }
    } else {
        // Caso: posición impar (puntos)
        for (int j = 0; j < valor; j++) {
            resultado.push_back('.');
        }
    }

    // Llamada recursiva para el siguiente índice
    ordenar_vector(numeros, resultado, i + 1, orden_par);

    // Tenemos el vector con los puntos guardado en resultado
}

void mover_puntos(vector<char>& resultado, int ini, int fin) {
    if (ini >= fin) {
        return;
    }

    if (resultado[ini] == '.' && resultado[fin] != '.') {
        // Caso: el inicio es '.' y el fin no es '.', intercambiamos y avanzamos
        swap(resultado[ini], resultado[fin]);
        mover_puntos(resultado, ini + 1, fin - 1);
    } else if (resultado[ini] != '.' && resultado[fin] != '.') {
        // Caso: ninguno de los extremos es '.', avanzamos el inicio
        mover_puntos(resultado, ini + 1, fin);
    } else if (resultado[ini] == '.' && resultado[fin] == '.') {
        // Caso: ambos extremos son '.', retrocedemos el fin
        mover_puntos(resultado, ini, fin - 1);
    } else {
        // Caso general: avanzar ambos extremos si no se cumple ninguna de las anteriores
        mover_puntos(resultado, ini + 1, fin - 1);
    }
}

int operacion(vector<char>& resultado) {
    int solucion = 0;
    for (int a = 0; a < resultado.size(); a++) {
        if (isdigit(resultado[a])) {
            int res = resultado[a] - '0';
            int mult = a * res;
            solucion += mult;
        }
    }
    return solucion;
}

int main() {
    vector<int> numeros;
    vector<char> resultado;
    string linea;
    ifstream fichero("fichero_dia9.txt"); // Abrir archivo

    if (!fichero.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return 1; // Salir si el archivo no se abre
    }

    // Leer el archivo completo línea por línea
    while (getline(fichero, linea)) {
        if (!linea.empty()) {
            for (char num : linea) {
                if (isdigit(num)) { // Si el carácter es un número
                    numeros.push_back(num - '0'); // Convertir de char a int y agregar al vector
                }
            }

            ordenar_vector(numeros, resultado);

            mover_puntos(resultado, 0, resultado.size() - 1);

            int res = operacion(resultado);
            cout << "El resultado es: " << res << endl;

            // Limpiar el vector de resultado para la próxima línea
            resultado.clear();
            numeros.clear();
        }
    }

    fichero.close();
    return 0;
}

*/
