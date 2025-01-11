#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std; 
int main(){
    
    ifstream fichero("fichero_dia3.txt");
    if (!fichero.is_open()) { 
        cerr << "No se pudo abrir el archivo" << endl; 
        return 1; 
    }

    stringstream buffer;
    buffer << fichero.rdbuf(); 
    string texto = buffer.str();

    regex exp("mul\\((\\d+,\\d+)\\)");
    smatch frase;
    auto it = texto.cbegin();
    string texto2;
    while(regex_search(it, texto.cend(), frase, exp)){
        texto2 += frase.str() + " ";
        it = frase[0].second;
    }

    regex num("\\d+");
    smatch res;
    vector<int> numeros;
    auto it2 = texto2.cbegin();
    
    while(regex_search(it2, texto2.cend(), res, num)){

        numeros.push_back(stoi(res.str()));
        it2 = res[0].second;
    }
    
    int suma = 0;
    for(int i = 0; i < numeros.size(); i+=2){
        
        int mult = 0;
        mult = numeros[i] * numeros[i+1];
        suma = suma + mult;

    }
    cout << "Suma: " << suma << endl;
    return 0;
}
