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
            cout << "El resultado es: " << res << endl;                                   
            resultado.clear();
            numeros.clear();
        }
    }

    fichero.close();
    return 0;
}
