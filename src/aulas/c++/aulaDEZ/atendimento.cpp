#include <iostream>
#include <deque>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std;
using namespace chrono;


struct Pessoa { 
    int codigo;
    string nome;
    system_clock::time_point entrou_em;
    system_clock::time_point chamado_em;
};

void exibirHorario(chrono::system_clock::time_point horario);

void inserirNormal(deque<Pessoa>& fila, const int& proximoCodigo, const string& nome);
void inserirPrioritario(deque<Pessoa>& fila, const int& proximoCodigo, const string& nome);
void chamarProximo(deque<Pessoa>& fila, vector<Pessoa>& historico);
void removerUltimo(deque<Pessoa>& fila);
void exibirFila(const deque<Pessoa>& fila);
void exibirHistorico(const vector<Pessoa>& historico);


int main(){

    deque<Pessoa> fila; 
    vector<Pessoa> historico;

    int escolha = -1;
    int codigo = 1;
    string nome;

    while (escolha != 0){
        cout << "\n1 - Inserir pessoa" << endl;
        cout << "2 - Inserir pessoa prioritária" << endl;
        cout << "3 - Chamar próxima pessoa" << endl;
        cout << "4 - Remover última pessoa da fila" << endl;
        cout << "5 - Exibir fila de atendimento" << endl;
        cout << "6 - Exibir histórico de chamados" << endl;
        cout << "7 - Informar quantidades" << endl;
        cout << "0 - Encerrar" << endl;
        cout << "\nEscolha uma opção: " << endl;
        cin >> escolha;

        switch (escolha)
        {
        case 0:
            cout << "\nTchau!" << endl;
            break;
        case 1:
            cout << "Insira o nome da pessoa: ";
            getline(cin >> ws, nome);
            cout << nome << endl;
            //cin.ignore();
            inserirNormal(fila, codigo, nome);
            codigo++;
            cout << "Pessoa adicionada" << endl;
            break;
        case 2:
            cout << "Insira o nome da pessoa com prioridade: ";
            getline(cin >> ws, nome);
            cout << nome << endl;
            inserirPrioritario(fila, codigo, nome);
            codigo++;
            cout << "Pessoa com prioridade adicionada" << endl;
            break;
        case 3:
            cout << "Próximo!" << endl;
            chamarProximo(fila, historico);
            break;
        case 4:
            cout << "Corrigindo a última pessoa..." << endl;
            removerUltimo(fila);
            break;
        case 5:
            cout << "Próximos: " << endl;
            exibirFila(fila);
            break;
        case 6:
            cout << "Históricos: " << endl;
            exibirHistorico(historico);
            break;
        case 7:
            cout << "Pessoas aguardando na fila: " << fila.size() << endl;
            cout << "Pessoas já chamadas: " << historico.size() << endl;
            break;
        default:
            cout << "\nOpção Inválida!" << endl;
            break;
        }
    }

    return 0;
}


void exibirHorario(chrono::system_clock::time_point horario){ 
    time_t tempo =  chrono::system_clock::to_time_t(horario); 
    cout << put_time(localtime(&tempo), "%H:%M:%S"); 
}

void inserirNormal(deque<Pessoa>& fila, const int& proximoCodigo, const string& nome){
    Pessoa pessoa{
        proximoCodigo,
        nome,
        system_clock::now()
    };
    fila.push_back(pessoa);
}

void inserirPrioritario(deque<Pessoa>& fila, const int& proximoCodigo, const string& nome){
    Pessoa pessoa{
        proximoCodigo,
        nome,
        system_clock::now()
    };
    fila.push_front(pessoa);
}

void chamarProximo(deque<Pessoa>& fila, vector<Pessoa>& historico){
    if (fila.empty()) {
        cout << "Fila está vazia!" << endl;
    } else {
        fila.front().chamado_em = system_clock::now();
        cout << fila.front().codigo << " " << fila.front().nome << " ";
        exibirHorario(fila.front().chamado_em);
        cout << endl;
        historico.push_back(fila.front());
        fila.pop_front();
    }
}

void removerUltimo(deque<Pessoa>& fila){
    if (fila.empty()) {
        cout << "Fila está vazia!" << endl;
    } else {
        cout << fila.back().codigo << " " << fila.back().nome << " " << endl;
        fila.pop_back();
    }
}

void exibirFila(const deque<Pessoa>& fila){
    for(auto i = 0; i < fila.size(); i++) {
        cout << "\nPosição na fila: " << i + 1 << endl;
        cout << fila[i].codigo << endl;
        cout << fila[i].nome << endl;
        exibirHorario(fila.front().entrou_em);
        cout << endl;
    }
}

void exibirHistorico(const vector<Pessoa>& historico){
    for(auto i = 0; i < historico.size(); i++) {
        cout << "\nPosição na fila: " << i + 1 << endl;
        cout << historico[i].codigo << endl;
        cout << historico[i].nome << endl;
        exibirHorario(historico.front().entrou_em);
        cout << endl;
        exibirHorario(historico.front().chamado_em);
        cout << endl;
    }
}