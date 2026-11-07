#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>

using namespace std;


void adicionarDespesa(fstream &arquivo, vector<tuple<string, double>> &despesas);
void listarDespesas(const vector<tuple<string, double>> &despesas);
void totalDespesas(const vector<tuple<string, double>> &despesas);


int main(){

    cout << "03 - Controle de Despesas Pessoais" << endl;

    tuple<string, double> item;

    vector<tuple<string, double>> despesas;

    fstream arquivo("despesas.txt", ios::in | ios::out | ios::app);

    double valor;
    string nome;
    int escolha = -1;

    if (!arquivo){
        cout << "Falha ao abrir o arquivo!" << endl;
        return 1;
    }

    while(escolha!=0){

        while (arquivo >> nome >> valor){
            item = make_tuple(nome, valor);
            despesas.push_back(item);
        }

        arquivo.clear();

        cout << "\n1 - Adicionar despesa" << endl;
        cout << "2 - Listar despesas" << endl;
        cout << "3 - Calcular total das despesas" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cin.ignore();
        if (escolha == 1){
            adicionarDespesa(arquivo, despesas);
        }else if (escolha == 2){
            listarDespesas(despesas);
        }else if (escolha == 3){
            totalDespesas(despesas);
        }else if (escolha != 0){
            cout << "Escolha inválida" << endl;
        }
    }
    cout << "Saindo..." << endl;

    return 0;
}


void adicionarDespesa(fstream &arquivo, vector<tuple<string, double>> &despesas){
    double valor;
    string nome;
    cout << "\nQual o tipo da despesa? " << endl;
    getline(cin, nome);
    cout << "Qual o valor da despesa? " << endl;
    cin >> valor;
    cin.ignore();
    arquivo << nome << " " << valor << "\n";
    //despesas.push_back(make_tuple(nome, valor)); redundante ao while no começo
    cout << "\nDespesa adicionada" << endl;
}

void listarDespesas(const vector<tuple<string, double>> &despesas){
    cout << "\nDespesas (Tipo/Valor):\n" << endl;
    for (auto item : despesas){
        cout << get<0>(item) << " " << get<1>(item) << endl;
    }

    if (despesas.empty()){
        cout << "Nenhuma despesa" << endl;
    }
}

void totalDespesas(const vector<tuple<string, double>> &despesas){
    double total = 0;
    for (auto item : despesas){
        total+=get<1>(item);
    }
    cout << "\nTotal das Despesas: " << total << endl;
}
