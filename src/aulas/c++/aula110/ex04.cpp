#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;


struct Veterinario {
    int codigo;
    string nome;
    string email;
    string especialidade;
};

void adicionarVet(fstream &arquivo, vector <Veterinario> &clinica);
void listarVet(const vector <Veterinario> &clinica);
void consultarVet(fstream &arquivo, vector <Veterinario> &clinica);
void modificarVet(fstream &arquivo, vector <Veterinario> &clinica);
void demitirVet(fstream &arquivo, vector <Veterinario> &clinica);
int buscarPosicao(const vector <Veterinario> &clinica, const int &codigo);
bool carregarVeterinarios(fstream &arquivo, vector <Veterinario> &clinica);
void salvarVeterinarios(fstream &arquivo, vector <Veterinario> &clinica);


int main() {

    cout << "04 - Controle de Veterinários — CRUD" << endl;

    fstream arquivo("veterinarios.txt", ios::in | ios::out | ios::app);

    vector <Veterinario> clinica;

    carregarVeterinarios(arquivo, clinica);

    int escolha = -1;

    while (escolha != 0){
        cout << "\n1 - Adicionar veterinário" << endl;
        cout << "2 - Listar todos os veterinários" << endl;
        cout << "3 - Consultar veterinário" << endl;
        cout << "4 - Modificar cadastro de um veterinário" << endl;
        cout << "5 - Demitir veterinário" << endl;
        cout << "6 - Deletar todos os veterinários" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cin.ignore();
        switch (escolha) {
            case 1:
                adicionarVet(arquivo, clinica);
                break;
            case 2:
                listarVet(clinica);
                break;
            case 3:
                consultarVet(arquivo, clinica);
                break;
            case 4:
                modificarVet(arquivo, clinica);
                break;
            case 5:
                demitirVet(arquivo, clinica);
                break;
            case 6:
                arquivo.close();
                arquivo.open("veterinarios.txt", ios::out | ios::trunc);
                arquivo.close();
                arquivo.open("veterinarios.txt", ios::in | ios::out | ios::app);
                break;
                case 0:
                cout << "\nSaindo..." << endl;
                break;
            default:
                cout << "\nOpção inválida!" << endl;
        }
    }


    return 0;
}


void adicionarVet(fstream &arquivo, vector <Veterinario> &clinica) {
    int maior = 1;
    string linha, nome, email, especialidade;
    cout << "Digite o nome do veterinário: " << endl;
    getline(cin, nome);
    cout << "Digite o email do veterinário: " << endl;
    getline(cin, email);
    cout << "Digite a especialidade do veterinário: " << endl;
    getline(cin, especialidade);
    if (!clinica.empty()){
        arquivo.clear();
        arquivo.seekg(0);
        for (auto v : clinica) {
            if (v.codigo >= maior) {
                maior = v.codigo+1;
            }
        }
    }
    arquivo.clear();
    arquivo << maior << ";" << nome << ";" << email << ";" << especialidade << "\n";
    if (carregarVeterinarios(arquivo, clinica)){
        cout << "Veterinário salvo" << endl;
    }
}

void listarVet(const vector <Veterinario> &clinica) {
    cout << "\nVeterinários: \n" << endl;
    for (auto v : clinica){
        cout << v.codigo << " - "
        << v.nome << " - "
        << v.email << " - "
        << v.especialidade << "\n";
    }
    cout << endl;
}

void consultarVet(fstream &arquivo, vector <Veterinario> &clinica) {
    int cod, i;
    cout << "Digite o código do veterinário: " << endl;
    cin >> cod;
    i = buscarPosicao(clinica, cod);
    if (i == -1){
        cout << "\nNenhum veterinário encontrado com esse código" << endl;
    }else{
        cout << clinica[i].codigo << " - "
        << clinica[i].nome << " - "
        << clinica[i].email << " - "
        << clinica[i].especialidade << "\n";
    }
}

void modificarVet(fstream &arquivo, vector <Veterinario> &clinica) {
    int cod, i;
    string linha, nome, email, especialidade;
    cout << "Digite o código do veterinário: " << endl;
    cin >> cod;
    i = buscarPosicao(clinica, cod);
    if (i == -1){
        cout << "\nNenhum veterinário encontrado com esse código" << endl;
    }else{
        cout << "Confirme o nome do veterinário: " << endl;
        cin.ignore();
        getline(cin, nome);
        cout << "Confirme o email do veterinário: " << endl;
        getline(cin, email);
        cout << "Confirme a especialidade do veterinário: " << endl;
        getline(cin, especialidade);
        arquivo.clear();
        clinica[i].nome = nome;
        clinica[i].email = email;
        clinica[i].especialidade = especialidade;
        salvarVeterinarios(arquivo, clinica);
        cout << "Veterinário alterado" << endl;
    }
}

void demitirVet(fstream &arquivo, vector <Veterinario> &clinica) {
    int cod, i;
    string linha, nome, email, especialidade;
    cout << "Digite o código do veterinário: " << endl;
    cin >> cod;
    i = buscarPosicao(clinica, cod);
    cin.ignore();
    if (i == -1){
        cout << "\nNenhum veterinário encontrado com esse código" << endl;
    }else{
        arquivo.clear();
        clinica.erase(clinica.begin()+i);
        salvarVeterinarios(arquivo, clinica);
        cout << "Veterinário demitido" << endl;
    }
}

int buscarPosicao(const vector <Veterinario> &clinica, const int &codigo) {
    int c = 0;
    for (auto v : clinica){
        if (v.codigo == codigo){
            return c;
        }
        c++;
    }
    return -1;
}

bool carregarVeterinarios(fstream &arquivo, vector <Veterinario> &clinica) {
    clinica.clear();
    arquivo.seekg(0, ios::beg);
    string linha, codigo, nome, email, especialidade;
    
    if (!arquivo.is_open()){
        return false;
    }else{
        while(getline(arquivo, linha)){
            stringstream ss(linha);
            getline(ss, codigo, ';');
            getline(ss, nome, ';');
            getline(ss, email, ';');
            getline(ss, especialidade, ';');
            clinica.push_back({stoi(codigo), nome, email, especialidade});
        }
        return true;
    }
}

void salvarVeterinarios(fstream &arquivo, vector <Veterinario> &clinica) {
    arquivo.close();
    arquivo.open("veterinarios.txt", ios::out | ios::trunc);
    arquivo.close();
    arquivo.open("veterinarios.txt", ios::in | ios::out | ios::app);
    for (int i = 0; i < clinica.size(); i++){
        arquivo << clinica[i].codigo << ";" << clinica[i].nome << ";" << clinica[i].email << ";" << clinica[i].especialidade << "\n";
    }
    cout << "\nArquivo sobrescrito" << endl;
}
