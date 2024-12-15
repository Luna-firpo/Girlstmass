/*Advent Of Code Day 13
Parte 1 
Máquinas recreativas*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

// Estructura para almacenar los valores de los botones y el premio
struct Machine {
    long long ax, ay, bx, by, px, py; 
}; 

// Función para leer el archivo de entrada - COMPROBADA
void read_input(vector<Machine> &machines) {
    ifstream file("input.txt");
    string line;

    while (getline(file, line)) {
        Machine machine; 
        if (line.find("Button A:") != string::npos) {
            // Parsear la línea para obtener los valores de los botones y el premio
            sscanf(line.c_str(), "Button A: X+%lld, Y+%lld", &machine.ax, &machine.ay);
            getline(file, line);
            sscanf(line.c_str(), "Button B: X+%lld, Y+%lld", &machine.bx, &machine.by);
            getline(file, line);
            sscanf(line.c_str(), "Prize: X=%lld, Y=%lld", &machine.px, &machine.py);
            machines.push_back(machine);
        }
    }
    file.close();

    cout << "Number of machines:" << machines.size() << endl;
    // Output the stored values for verification
    for (const auto& machine : machines) {
        cout << "Button A: X+" << machine.ax << ", Y+" << machine.ay << endl;
        cout << "Button B: X+" << machine.bx << ", Y+" << machine.by << endl;
        cout << "Prize: X=" << machine.px << ", Y=" << machine.py << endl;
    }
}

//Part 1 with DyV
// Función para calcular los valores de los botones A y B
vector<vector<long long>> values(vector<Machine>& machines, int start, int end) { 
    // Inicializar vector de resultados 
    vector<vector<long long>> value(end - start + 1, vector<long long>(2, 0));  

    // Caso base
    if (start == end) {
        const int MAX = 100;
        long long cost = LLONG_MAX; 
        int bestA = -1, bestB = -1;

        for (int nA = 0; nA <= MAX; nA++) { // Probar todos los A presses
            for (int nB = 0; nB <= MAX; nB++) { // Probar todos los B presses
                long long x = (long long)nA * machines[start].ax + (long long)nB * machines[start].bx;
                long long y = (long long)nA * machines[start].ay + (long long)nB * machines[start].by;

                if (x == machines[start].px && y == machines[start].py) {
                    long long current_cost = (long long)nA * 3 + (long long)nB * 1; // Coste
                    if (current_cost < cost) {
                        cost = current_cost;
                        bestA = nA;
                        bestB = nB;
                    }
                }
            }
        }

        if (cost < LLONG_MAX) {
            value[0][0] = bestA;
            value[0][1] = bestB;
        } else {
            cout << "No solution found for machine " << start << endl;
            value[0][0] = 0;
            value[0][1] = 0;
        }
        return value;
    }

    int mid = (start + end) / 2;
    vector<vector<long long>> left = values(machines, start, mid);  
    vector<vector<long long>> right = values(machines, mid + 1, end); 

    vector<vector<long long>> result(end - start + 1, vector<long long>(2, 0));
    for (int i = 0; i <= mid - start; i++) {
        result[i] = left[i];
    }
    for (int i = 0; i <= end - mid - 1; i++) {
        result[mid - start + 1 + i] = right[i];
    }

    return result;
}



/*vector<vector<long long>> valores(vector<vector<vector<long long>>>& data, int start, int end) {
    // Inicializar vector de resultados
    vector<vector<long long>> valor(end - start + 1, vector<long long>(2, 0));  

    // Caso base
    if (start == end) {
        const int MAX_PRESSES = 100;
        int cost = INT_MAX; 
        int bestA = 0, bestB = 0;

        for (int nA = 0; nA <= INT_MAX; nA++) { // Probar todos los A presses
            for (int nB = 0; nB <= INT_MAX; nB++) { // Probar todos los B presses
                int x = nA * data[start][0][0] + nB * data[start][1][0];
                int y = nA * data[start][0][1] + nB * data[start][1][1];

                if (x == data[start][2][0] && y == data[start][2][1]) {
                    int current_cost = nA * 3 + nB * 1; // Coste
                    if (current_cost < cost) {
                        cost = current_cost;
                        bestA = nA;
                        bestB = nB;
                    }
                }
            }
        }

        if (cost < INT_MAX) {
            valor[0][0] = bestA;
            valor[0][1] = bestB;
        } else {
            valor[0][0] = 0;
            valor[0][1] = 0;
        }
        return valor;
    }

    int mid = (start + end) / 2;
    vector<vector<long long>> left = valores(data, start, mid);  
    vector<vector<long long>> right = valores(data, mid + 1, end); 

    vector<vector<long long>> result(end - start + 1, vector<long long>(2, 0));
    for (int i = 0; i <= mid - start; i++) {
        result[i][0] = left[i][0];
        result[i][1] = left[i][1];
    }
    for (int i = 0; i <= end - mid - 1; i++) {
        result[mid - start + 1 + i][0] = right[i][0];
        result[mid - start + 1 + i][1] = right[i][1];
    }

    return result;
}*/

// Función para calcular el total de monedas de una máquina
vector<vector<long long>> monedas(vector<vector<long long>> valor)
{
    vector<vector<long long>> moneda(valor.size(), vector<long long>(2, 0));
    for(int i=0; i<valor.size(); i++)
    {
        moneda[i][0] = 3 * valor[i][0];
        moneda[i][1] = valor[i][1];
    }
    return moneda;
}

// Función para calcular el total de monedas de todas las máquinas
int total(vector<vector<long long>> monedas) {
    int tot = 0;
    for (int i = 0; i < monedas.size(); i++) {
        tot += monedas[i][0] + monedas[i][1];
    }
    
    return tot;
}

int main() {
    vector<vector<vector<long long>>> data;
    vector<Machine> machines;
    read_input(machines);

    vector<vector<long long>> valor = values(machines, 0, machines.size() - 1);
    for(int i = 0; i < valor.size(); i++) {
        cout << "Boton A: " << valor[i][0] << " Boton B: " << valor[i][1] << endl;
    }
    
    vector<vector<long long>> moneda = monedas(valor);
    for(int i = 0; i < moneda.size(); i++) {
        cout << "Moneda 3: " << moneda[i][0] << " Moneda 1: " << moneda[i][1] << endl;
    } 

    int tot = total(moneda);
    cout << "Total: " << tot << endl;

    return 0;
}
