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

    fstream arquivo("participantes.txt", ios::in | ios::out | ios::app);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    while(escolha!=0){
        cout << "\n1 - Cadastrar participante" << endl;
        cout << "2 - Listar participantes" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;
        cin.ignore();
        if (escolha == 1){
            cadastrarNome(arquivo);
            cout << "\nNome cadastrado" << endl;
        }else if (escolha == 2){
            cout << endl;
            listarNomes(arquivo);
        }else if (escolha != 0){
            cout << "\nEscolha inválida" << endl;
        }
    }
    
    cout << "\nSaindo..." << endl;
    arquivo.close();

    return 0;
}


void cadastrarNome(fstream &arquivo){
    string nome;
    arquivo.clear();
    arquivo.seekp(0, ios::end);
    cout << "Digite o nome para cadastrar: " << endl;
    getline(cin, nome);
    arquivo << nome << endl;
    arquivo.flush();
}

void listarNomes(fstream &arquivo){
    string linha;

    arquivo.clear();
    arquivo.seekg(0, ios::beg);
    while (getline(arquivo, linha)){
        cout << linha << endl;
    }
}