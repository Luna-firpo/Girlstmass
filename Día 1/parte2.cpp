/*
Day 1 AdventOfCode Part 2
Calcular las veces que se repite un número en una lista
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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

// Encontrar repeticiones de n en un vector v
int find_rep(int n, vector<int> &v){
    int count = 0; 
    for (int i = 0; i < v.size(); i++){
        if (v[i] == n){
            count++; 
        }
    }
    return count; 
}

// Encontrar valores de v1 que están en v2
vector<int> find_sim(vector<int> &v1, vector<int> &v2){
    vector<int> sim; 
    for (int i = 0; i < v1.size(); i++){
        if (find_rep(v1[i], v2) > 0){
            sim.push_back(v1[i]); 
        }
    }
    return sim; 
}

int main(){
    vector<int> v1, v2; 

    //leer archivo linea a linea y guardar en dos vectores
    read_file(v1, v2); 

    // Calcular el puntaje total de similitud
    int total_sim = 0; 

    for (int i = 0; i < v1.size(); i++){
        int value = v1[i]; 
        int rep = find_rep(value, v2); 
        total_sim += value * rep; 
    }

    // Imprimir resultado final
    cout << "Total similarity score: " << total_sim << endl; 

    return 0; 
}