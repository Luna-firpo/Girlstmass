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
bool can_display_design(const string& design, const unordered_set<string>& patterns) {
    vector<bool> dp(design.length() + 1, false);
    dp[0] = true;

    for (size_t i = 1; i <= design.length(); ++i) {
        for (const auto& pattern : patterns) {
            if (i >= pattern.length() && dp[i - pattern.length()] && design.substr(i - pattern.length(), pattern.length()) == pattern) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[design.length()];
}

// Función para procesar un fragmento del archivo
void process_fragment(const vector<string>& fragment, const unordered_set<string>& patterns, int& possible_designs) {
    for (const auto& line : fragment) {
        if (can_display_design(line, patterns)) {
            ++possible_designs;
        }
    }
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    string line;
    unordered_set<string> patterns;

    // Leer los patrones disponibles
    if (getline(file, line)) {
        stringstream ss(trim(line));
        string pattern;
        while (getline(ss, pattern, ',')) {
            patterns.insert(trim(pattern));
        }
    }

    int possible_designs = 0;
    vector<string> fragment;
    const size_t FRAGMENT_SIZE = 1000;

    // Leer y procesar las líneas del archivo
    while (getline(file, line)) {
        line = trim(line);
        if (!line.empty()) {
            fragment.push_back(line);
        }

        if (fragment.size() >= FRAGMENT_SIZE) {
            process_fragment(fragment, patterns, possible_designs);
            fragment.clear();
        }
    }

    // Procesar cualquier línea restante
    if (!fragment.empty()) {
        process_fragment(fragment, patterns, possible_designs);
    }

    file.close();
    cout << "Número de diseños posibles: " << possible_designs << endl;

    return 0;
}
