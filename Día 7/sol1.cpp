/* Advent Of Code Día 7
Parte 1 */

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Función recursiva para evaluar todas las combinaciones de operadores
bool evaluate_tree(const vector<long long>& nums, int index, long long current_result, long long target) {
    // Caso base: hemos procesado todos los números
    if (index == nums.size()) {
        return current_result == target; // Comprobar si el resultado coincide con el objetivo
    }

    // Avanzar en el árbol con dos ramas: suma y multiplicación
    return evaluate_tree(nums, index + 1, current_result + nums[index], target) ||
           evaluate_tree(nums, index + 1, current_result * nums[index], target);
}

// Función para verificar si una ecuación es válida
bool is_valid_equation(const vector<long long>& nums, long long target) {
    // Llamada inicial a la función recursiva con el primer número
    return evaluate_tree(nums, 1, nums[0], target);
}

int main() {
    string filename = "input.txt";
    ifstream file(filename);
    string line;
    long long total_sum = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        vector<long long> nums;
        long long target;

        // Leer el valor objetivo
        getline(ss, temp, ':');
        target = stoll(temp);

        // Leer los números
        while (ss >> temp) {
            nums.push_back(stoll(temp));
        }

        // Verificar si la ecuación es válida
        if (is_valid_equation(nums, target)) {
            total_sum += target; // Sumar el valor objetivo si es válido
        }
    }

    file.close();

    // Imprimir el resultado final
    cout << "Total de calibración: " << total_sum << endl;
    return 0;
}
