#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Objeto {
    int codigo;
    string nome;
    int qtd;
};

void jsar(fstream &arquivo);

int main(){

    fstream arquivo ("objetos.txt", ios::in | ios::out);
    jsar(arquivo);


    return 0;
}

void jsar(fstream &arquivo){
    string linha, nome, codigo, qtd;
    fstream arquivo2 ("objetos_backup.txt", ios::in | ios::out | ios::trunc);
    if (!arquivo.is_open()){
        cout << "O arquivo não foi aberto!" << endl;
    }else{
        arquivo.seekg(0, ios::beg);
        while(getline(arquivo, linha)){
            arquivo2 << linha << endl;
        }
        cout << "O arquivo foi aberto com sucesso!" << endl;
        arquivo.close();
        fstream arquivo ("objetos.txt", ios::out | ios::trunc);
        arquivo2.seekg(0, ios::beg);
        arquivo << "[\n\n";
        bool primeiro = true;
        while(getline(arquivo2, linha)){
            if(linha.empty()) continue;
            stringstream ss(linha);
            getline(ss, codigo, ';');
            getline(ss, nome, ';');
            getline(ss, qtd, ';');
            
            if (!primeiro) {
                arquivo << ",\n";
            }
            
            arquivo << "    {\"codigo\": " << stoi(codigo) << ", \"nome\": \"" << nome << "\", \"qtd\": " << stoi(qtd) << "}";
            
            primeiro = false;
            
        }
        arquivo << "\n\n]";

        cout << "O arquivo foi salvo com sucesso!" << endl;
    }
}