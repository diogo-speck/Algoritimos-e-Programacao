#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

/*
ifstream (Input File Stream)
arquivo → programa
ofstream (Output File Stream)
programa → arquivo
fstream (File Stream)
arquivo programa
*/

int main(){

    // clear(sobreescreve tudo): ofstream variável("nome.tipo");

    string linha;

    ofstream arquivo("teste.txt");
    
    ofstream alterado("alterado.txt");

    if (!arquivo|| !alterado){ // equivalente a .fail()
        cout << "Erro ao abrir os arquivos" << endl;
        return 1;
    }


    for (int i=0; i<20; i++){
        arquivo << i+1 << endl;
    }
    
    arquivo.close();

    //istream& getline(istream& is, string& str);

    ifstream file("teste.txt");


    int c = 0;
    int condicao = 0; // Condição para apagar


    while (getline(file, linha)) {
        c++;
        if (c!=condicao){
            alterado << linha << endl;
            cout << linha << endl; //print
        }
    }

    file.close();
    alterado.close();

    ifstream file2("alterado.txt");
    ofstream arquivo2("teste.txt");

    while (getline(file2, linha)) {
        arquivo2 << linha << endl; // poderia usar getline(arquivo2, linha); ou ios::app
    }
    
    //file2.close();
    //arquivo2.close(); não necessário


    remove("alterado.txt");

    return 0;
}
