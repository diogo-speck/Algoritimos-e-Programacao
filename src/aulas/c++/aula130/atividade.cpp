#include <iostream>
#include <fstream>
#include "single_include\nlohmann\json.hpp"

using namespace std;


struct Despesa{ 
    int id; 
    string data; 
    string descricao; 
    string categoria; 
    double valor; 
};

void carregarDespesas(); // Recuperar os registros do arquivo. 
void salvarDespesas(); // Reescrever o arquivo com os registros do vector. 
void gerarProximoId(); // Determinar o próximo identificador. 
void adicionarDespesa(); // Cadastrar uma nova despesa. 
void listarDespesas(); // Apresentar todas as despesas. 
void buscarPosicao(); // Localizar uma despesa pelo ID.
void excluirDespesa(); // Remover uma despesa.


int main(){

    /*
        Padrão de saída: 
        1 - 05/11/2026 - Almoco - Alimentacao - R$ 35.90 
        2 - 05/11/2026 - Combustivel - Transporte - R$ 120.00 
        3 - 06/11/2026 - Medicamentos - Saude - R$ 48.50 
        4 - 07/11/2026 - Cinema - Lazer - R$ 32.00
    */

    cout << "Controle de Despesas Pessoais --- TXT, CSV e JSON" << endl;

    cout <<"\n===== CONTROLE DE DESPESAS =====" <<
    "\n1 - Adicionar despesa" <<
    "\n2 - Listar despesas" <<
    "\n3 - Excluir despesa" <<
    "\n0 - Sair" <<
    "\nOpcao:" << endl;


    return 0;
}