/* Día 1 Advent Of Code Parte 1
Suma de las diferencias entre dos listas ordenadas
Empleando la estrategia Divide y Venceras */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Merge function for MergeSort 
// Combina dos mitades ordenadas de un vector
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Tamaño de la primera mitad del vector
    int n2 = right - mid; // Tamaño de la segunda mitad del vector
    vector<int> L(n1), R(n2); // Vectores auxiliares para almacenar las mitades

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++; k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++; k++;
    }
}

// MergeSort function (Divide and Conquer)
// Calcula la suma de las diferencias entre dos listas ordenadas
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void read_file(vector<int>& v1, vector<int>& v2) {
    ifstream file("input.txt");
    string line, data;

    while (getline(file, line)) {
        stringstream ss(line);
        ss >> data;
        v1.push_back(stoi(data));
        ss >> data;
        v2.push_back(stoi(data));
    }
}


int main() {
    vector<int> v1, v2;

    // Read file and store values
    read_file(v1, v2);

    // Apply MergeSort (Divide and Conquer)
    mergeSort(v1, 0, v1.size() - 1);
    mergeSort(v2, 0, v2.size() - 1);

    // Compute sum of absolute differences
    int sum = 0;
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " " << v2[i] << " " << abs(v1[i] - v2[i]) << endl;
        sum += abs(v2[i] - v1[i]);
    }

    cout << sum << endl;
    return 0;
}
