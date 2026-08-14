#include <iostream>
#include <cctype>

using namespace std;

void exibirEstacionamento(const int (&estacionamento)[4][5]);
bool vagaValida(int vaga);
bool ocuparVaga(int vaga, int (&estacionamento)[4][5]);
bool liberarVaga(int vaga, int (&estacionamento)[4][5]);
int contarVagasLivres(const int (&estacionamento)[4][5]); // v1
int contarVagasLivres(int vaga, char fileira, const int (&estacionamento)[4][5]); // v2 (fileiras)

int main()
{
    bool ativo = true;
    int vaga;
    char fileira;
    cout << "Controle de Vagas de um Estacionamento" << endl;
    //cin.get(); Pede enter para o user
    int estacionamento[4][5];

    for (int i=0; i<4; i++){
        for (int j=0; j<5; j++){
            estacionamento[i][j] = 0;
        }
    }


    while(ativo){

        int escolha = 0;

        cout << "\nFuncionalidades: " << endl;
        cout << "1 - Visualizar o estacionamento" << endl;
        cout << "2 - Ocupar uma vaga" << endl;
        cout << "3 - Liberar uma vaga" << endl;
        cout << "4 - Consultar a quantidade total de vagas livres" << endl;
        cout << "5 - Consultar a quantidade de vagas livres em uma determinada fileira" << endl;
        cout << "6 - Sair do programa" << endl;
        cout << "Escolha: ";

        cin >> escolha;

        switch(escolha){
            case 1:
                exibirEstacionamento(estacionamento);
                break;
            case 2:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga)){
                    ocuparVaga(vaga, estacionamento);
                }else{
                    cout << "Vaga inválida" << endl;
                }
                break;
            case 3:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga)){
                    liberarVaga(vaga, estacionamento);
                }else{
                    cout << "Vaga inválida" << endl;
                }
                break;
            case 4:
                cout << "Vagas livres no estacionamento: " << contarVagasLivres(estacionamento) << endl;
                break;
            case 5:
                cout << "Digite a fileira (ex. c1 para a coluna 1): ";
                cin >> fileira >> vaga;
                fileira = tolower(fileira);
                if (fileira == 'c'){ // Coluna
                    vaga*=4;
                }else if (fileira == 'l'){ // Linha
                    vaga*=5;
                }else{
                    vaga=25;
                }
                if (vagaValida(vaga)){
                    cout << "Vagas livres na fileira: " << contarVagasLivres(vaga, fileira, estacionamento) << endl;
                }else{
                    cout << "Vaga inválida" << endl;
                }
                break;
            case 6:
                cout << "Saindo..." << endl;
                ativo = false;
                break;
            default:
                cout << "Opção inválida" << endl;
                break;
        }
    }

    return 0;
}

void exibirEstacionamento(const int (&estacionamento)[4][5]){
    for (int i=0; i<4; i++){
        for (int j=0; j<5; j++){
            cout << estacionamento[i][j] << " ";
        }
        cout << endl;
    }

}

bool vagaValida(int vaga){
    return vaga>0&&vaga<21;
}

bool ocuparVaga(int vaga, int (&estacionamento)[4][5]){
    int linha = (vaga- 1) / 5;
    int coluna = (vaga- 1) % 5;
    
    if (estacionamento[linha][coluna] == 0){
        estacionamento[linha][coluna] = 1;
        cout << "Você ocupou a vaga " << vaga << endl;
        return true;
    }else{
        cout << "Vaga " << vaga << " já ocupada!" << endl;
    }
    return false;
}

bool liberarVaga(int vaga, int (&estacionamento)[4][5]){
    int linha = (vaga- 1) / 5;
    int coluna = (vaga- 1) % 5;
    
    if (estacionamento[linha][coluna] == 1){
        cout << "Você liberou a vaga " << vaga << endl;
        estacionamento[linha][coluna] = 0;
        return true;
    }else{
        cout << "Vaga " << vaga << " já estava liberada!" << endl;
    }
    return false;
}

int contarVagasLivres(const int (&estacionamento)[4][5]){ //v1
    int contador=0;
    for (int i=0; i<4; i++){
        for (int j=0; j<5; j++){
            if (estacionamento[i][j] == 0){
                contador++;
            }
        }
    }
    return contador;
}

int contarVagasLivres(int vaga, char fileira, const int (&estacionamento)[4][5]){ // v2 (fileiras)
    int contador=0;
    if (fileira == 'c'){ // Coluna
        fileira = (vaga/4)-1;
        for (int i=0; i<4; i++){
            for (int j=0; j<5; j++){
                if (j == fileira && estacionamento[i][j]==0){
                    contador++;
                }
            }
        }
    }else{ // Linha
        fileira = (vaga/5)-1;
        for (int i=0; i<4; i++){
            for (int j=0; j<5; j++){
                if (i == fileira && estacionamento[i][j]==0){
                    contador++;
                }
            }
        }
    }
    
    return contador;
}