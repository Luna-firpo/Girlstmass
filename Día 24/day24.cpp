#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <functional>
#include <tuple>
#include <bitset>

using namespace std;

unordered_map<string, int> known;
unordered_map<string, tuple<string, string, string>> formulas;

unordered_map<string, function<int(int, int)>> operators = {
    {"OR", [](int x, int y) { return x | y; }},
    {"AND", [](int x, int y) { return x & y; }},
    {"XOR", [](int x, int y) { return x ^ y; }}
};

int calc(const string& wire) {
    if (known.find(wire) != known.end()) return known[wire];
    auto [op, x, y] = formulas[wire];
    known[wire] = operators[op](calc(x), calc(y));
    return known[wire];
}

int main() {
    ifstream file("input.txt");
    string line;

    // Leer los valores conocidos
    cout << "Leyendo valores conocidos..." << endl;
    while (getline(file, line) && !line.empty()) {
        if (line.find(": ") != string::npos) {
            auto pos = line.find(": ");
            string x = line.substr(0, pos);
            try {
                int y = stoi(line.substr(pos + 2));
                known[x] = y;
            } catch (const invalid_argument& e) {
                cerr << "Error: '" << line.substr(pos + 2) << "' no es un número válido." << endl;
                return 1;
            } catch (const out_of_range& e) {
                cerr << "Error: El número en '" << line.substr(pos + 2) << "' está fuera de rango." << endl;
                return 1;
            }
        }
    }

    file.clear();
    file.seekg(0);

    // Leer las fórmulas
    cout << "Leyendo fórmulas..." << endl;
    while (getline(file, line)) {
        replace(line.begin(), line.end(), '-', ' ');
        replace(line.begin(), line.end(), '>', ' ');
        istringstream iss(line);
        string x, op, y, z;
        iss >> x >> op >> y >> z;
        formulas[z] = make_tuple(op, x, y);
    }

    cout << "Calculando valores..." << endl;
    vector<int> z;
    int i = 0;
    while (true) {
        string key = "z" + string(2 - to_string(i).length(), '0') + to_string(i);
        if (formulas.find(key) == formulas.end()) break;
        cout << "Calculando " << key << endl;
        z.push_back(calc(key));
        i++;
    }

    string result;
    for (auto it = z.rbegin(); it != z.rend(); ++it) {
        result += to_string(*it);
    }

    try {
        // Usa unsigned long long int para manejar grandes números binarios
        cout << "Resultado: " << result << endl;
        unsigned long long int decimalValue = bitset<64>(result).to_ullong();
        cout << decimalValue << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: '" << result << "' no es un número binario válido." << endl;
        return 1;
    } catch (const out_of_range& e) {
        cerr << "Error: El número binario en '" << result << "' está fuera de rango." << endl;
        return 1;
    }

    return 0;
}
