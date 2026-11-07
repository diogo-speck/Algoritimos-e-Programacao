#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void calcularMedia(fstream &arquivo, vector <double> &notas);
void maiorNota(fstream &arquivo, vector <double> &notas);
void menorNota(fstream &arquivo, vector <double> &notas);
void mais7(fstream &arquivo, vector <double> &notas);

int main(){
    cout << "02 - Análise de notas\n" << endl;
    //ifstream, vector, funções, cálculos e percorrimento de coleções
    vector <double> notas;
    int escolha = -1;
    double valor;

    fstream arquivo("notas.txt", ios::in); // só escrita

    if (!arquivo.is_open()) {
        cout << "Arquivo não está aberto!" << endl;
        return 1;
    }

    if (notas.empty()){
        cout << "Notas salvas no arquivo: " << endl;
            while (arquivo >> valor){
                notas.push_back(valor);
                cout << valor << endl;
        }
        cout << "\n(" << notas.size() << " notas)" << endl;
    }

    while(escolha!=0){
        cout << "\n1 - Calcular Média Aritmética" << endl;
        cout << "2 - Maior nota" << endl;
        cout << "3 - Menor nota" << endl;
        cout << "4 - Quantidade de notas >= 7" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;
        cin.ignore();
        if (escolha == 1){
            calcularMedia(arquivo, notas);
        }else if (escolha == 2){
            maiorNota(arquivo, notas);
        }else if (escolha == 3){
            menorNota(arquivo, notas);
        }else if (escolha == 4){
            mais7(arquivo, notas);
        }else if (escolha != 0){
            cout << "Escolha inválida" << endl;
        }
    }
    
    cout << "Saindo..." << endl;
    arquivo.close();

    return 0;
}


void calcularMedia(fstream &arquivo, vector <double> &notas){
    double total = 0.0, valor;
    try
    {
        for (double valor : notas) {
            total += valor;
        }
        cout << "Média Aritmética: " << total/notas.size() << endl;
    }
    catch(exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void maiorNota(fstream &arquivo, vector <double> &notas){
    double valor;
    bool valido = false;
    double maior = numeric_limits<double>::lowest();
    arquivo.clear();
    arquivo.seekg(0);
    for (double valor : notas) {
        if (valor > maior) {
            valido = true;
            maior = valor;
        }
    }
    if (valido){
        cout << "Maior nota: " << maior << endl;
    }else{
        cout << "Nenhum valor válido encontrado" << endl;
    }
}

void menorNota(fstream &arquivo, vector <double> &notas){
    double valor;
    bool valido = false;
    double menor = numeric_limits<double>::max();
    arquivo.clear();
    arquivo.seekg(0);
    for (double valor : notas) {
        if (valor < menor) {
            valido = true;
            menor = valor;
        }
    }
    if (valido){
        cout << "Menor nota: " << menor << endl;
    }else{
        cout << "Nenhum valor válido encontrado" << endl;
    }
}

void mais7(fstream &arquivo, vector <double> &notas){
    double c = 0, valor;
    bool valido = false;
    arquivo.clear();
    arquivo.seekg(0);
    try
    {
        for (double valor : notas) {
            if (valor >= 7) {
                c++;
        }
    }
        cout << "Notas maiores ou iguais que 7.0: " << c << endl;
    }
    catch(exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}