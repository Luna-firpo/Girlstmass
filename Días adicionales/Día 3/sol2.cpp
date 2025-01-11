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
    
    regex exp("(don't\\(\\))|(do\\(\\))|(mul\\(\\d+,\\d+\\))");
    smatch pal;
    auto it = texto.cbegin();
    string palabra;
    bool habilitar = true;
    vector<int> numeros;
    while(regex_search(it, texto.cend(), pal, exp)){
        palabra = pal.str();
        if(palabra == "don't()"){
            habilitar = false;
        }else if(palabra == "do()"){
            habilitar = true;
        }else if((habilitar== true) & (palabra == "mul()") == 0) {                                // si está en la pos 0 empieza por mul y estaría habilitado
            regex num("\\d+");
            smatch res;
            
            auto it2 = palabra.cbegin();
    
            while(regex_search(it2, palabra.cend(), res, num)){
                numeros.push_back(stoi(res.str()));
                it2 = res[0].second;
            }
        }
        it = pal[0].second;
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
