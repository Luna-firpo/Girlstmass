#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <sstream>

using namespace std;

// Función para eliminar espacios al principio y al final de una cadena
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

// Función que determina si se puede mostrar un diseño usando los patrones disponibles
bool can_display_design(const string& diseño, const unordered_set<string>& patrones) {
    vector<bool> dp(diseño.length() + 1, false);
    dp[0] = true;

    for (size_t i = 1; i <= diseño.length(); ++i) {
        for (const auto& pat : patrones) {
            if (i >= pat.length() && dp[i - pat.length()] && diseño.substr(i - pat.length(), pat.length()) == pat) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[diseño.length()];
}

// Función para procesar un fragmento del archivo
void fragmento(const vector<string>& frag, const unordered_set<string>& patron, int& posible_disenyo) {
    for (const auto& linea : frag) {
        if (can_display_design(linea, patron)) {
            posible_disenyo++;
        }
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "No se puede abrir el archivo." << endl;
        return 1;
    }

    string linea;
    unordered_set<string> patrones;

    // Leer los patrones disponibles
    if (getline(file, linea)) {
        stringstream ss(trim(linea));
        string patr;
        while (getline(ss, patr, ',')) {
            patrones.insert(trim(patr));
        }
    }

    int pos_disenyo = 0;
    vector<string> fragment;
    const size_t FRAGMENT_SIZE = 1000;

    // Leer y procesar las líneas del archivo
    while (getline(file, linea)) {
        linea = trim(linea);
        if (!linea.empty()) {
            fragment.push_back(linea);
        }

        if (fragment.size() >= FRAGMENT_SIZE) {
            fragmento(fragment, patrones, pos_disenyo);
            fragment.clear();
        }
    }

    // Procesar cualquier línea restante
    if (!fragment.empty()) {
        fragmento(fragment, patrones, pos_disenyo);
    }

    file.close();
    cout << "Número de diseños posibles: " << pos_disenyo << endl;

    return 0;
}
