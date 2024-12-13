/* Day 1 AdventOfCode Part 1
Ejemplo básico 
Suma de las diferencias entre dos listas ordenadas
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std; 

void read_file(vector<int> &v1, vector<int> &v2){
    ifstream file("input.txt"); 
    string line, data; 

    while (getline(file, line)){
        stringstream ss(line); // Convertir string a int
        ss >> data; 
        v1.push_back(stoi(data)); 
        ss >> data; 
        v2.push_back(stoi(data)); 
    }
}

int main(){
    vector<int> v1, v2; 

    //leer archivo linea a linea y guardar en dos vectores
    read_file(v1, v2); 

    //Ordenar los vectores
    sort(v1.begin(), v1.end()); 
    sort(v2.begin(), v2.end()); 

    // Sumar las diferencias entre los elementos de los vectores
    int sum = 0; 
    for (int i = 0; i < v1.size(); i++){
        cout << v1[i] << " " << v2[i] << abs(v1[i] - v2[i]) << endl; 
        sum += abs(v2[i] - v1[i]);
    }

    cout << sum << endl; 
    return 0; 
}
