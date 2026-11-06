#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void cadastrarNome(fstream &arquivo);
void listarNomes(fstream &arquivo);

int main(){
    cout << "01 - Lista de participantes" << endl;
    //getline(), string, ofstream, ifstream e ios::app
    int escolha = -1;

    fstream arquivo("participantes.txt", ios::in | ios::out);


    while(escolha!=0){
        cout << "\n1 - Cadastrar participante" << endl;
        cout << "2 - Listar participantes" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;
        cin.ignore();
        if (escolha == 1){
            cadastrarNome(arquivo);
        }else if (escolha == 2){
            listarNomes(arquivo);
        }else{
            cout << "Escolha inválida" << endl;
        }
    }
    
    cout << "Saindo..." << endl;
    arquivo.close();

    return 0;
}


void cadastrarNome(fstream &arquivo){
    string nome;
    cout << "Digite o nome para cadastrar: " << endl;
    getline(cin, nome);
    arquivo << nome << endl;
}

void listarNomes(fstream &arquivo){
    string linha;
    
    while (getline(arquivo, linha)){
        cout << linha << endl;
    }
}