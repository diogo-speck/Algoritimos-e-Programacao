#include <iostream>

using namespace std;

void exibirEstacionamento(const int (&estacionamento)[4][5]);
bool vagaValida(int vaga, const int (&estacionamento)[4][5]);
bool ocuparVaga(int vaga, int (&estacionamento)[4][5]);
bool liberarVaga(int vaga, int (&estacionamento)[4][5]);
int contarVagasLivres(const int (&estacionamento)[4][5]); // v1
int contarVagasLivres(int vaga, const int (&estacionamento)[4][5]); // v2 (fileiras)

int main()
{
    bool ativo = true;
    int vaga, linha, coluna, contador=0;
    cout << "Controle de Vagas de um Estacionamento" << endl;
    //cin.get(); Pede enter para o user
    int estacionamento[4][5]{};


    for (int i; i<4; i++){
        for (int j; j<5; j++){
            estacionamento[i][j] = 0;
            cout << estacionamento[i][j] << " ";
        }
        cout << endl;
    }

    while(ativo){

        int escolha = 0, vaga;

        cout << "Funcionalidades: " << endl;
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
                if (vagaValida(vaga, estacionamento)){
                    ocuparVaga(vaga, estacionamento);
                }else{
                    cout << "Vaga inv�lida" << endl;
                }
                break;
            case 3:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga, estacionamento)){
                    liberarVaga(vaga, estacionamento);
                }else{
                    cout << "Vaga inv�lida" << endl;
                }
                break;
            case 4:
                cout << "Vagas livres no estacionamento: " << contarVagasLivres(estacionamento) << endl;
                break;
            case 5:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga, estacionamento)){
                    cout << "Vagas livres adjacentes: " << contarVagasLivres(vaga, estacionamento) << endl;
                }else{
                    cout << "Vaga inv�lida" << endl;
                }
                break;
            case 6:
                cout << "Saindo..." << endl;
                ativo = false;
                break;
            default:
                cout << "Op��o inv�lida" << endl;
                break;
        }
    }

    return 0;
}

void exibirEstacionamento(const int (&estacionamento)[4][5]){
    for (int i; i<4; i++){
        for (int j; j<5; j++){
            cout << estacionamento[i][j] << " ";
        }
        cout << endl;
    }

}

bool vagaValida(int vaga, const int (&estacionamento)[4][5]){
    if (vaga>0&&vaga<21){
        return true;
    }else{
        return false;
    }
}

bool ocuparVaga(int vaga, int (&estacionamento)[4][5]){
    vaga--;
    for (int i; i<4; i++){
        for (int j; j<5; j++){
            if (vaga == 0){
                if (estacionamento[i][j] == 0){
                    estacionamento[i][j] == 1;
                    cout << "Voc� ocupou a vaga " << vaga << endl;
                    return true;
                }else{
                    cout << "Vaga " << vaga << " j� ocupada!" << endl;
                    return false;
            }
            }else{
                vaga--;
            }
        }
    }
}

/*
    linha = (vaga- 1) / 5;
    coluna = (vaga- 1) % 5;
*/

bool liberarVaga(int vaga, int (&estacionamento)[4][5]){
    vaga--;
    for (int i; i<4; i++){
        for (int j; j<5; j++){
            if (vaga == 0){
                if (estacionamento[i][j] == 0){
                    cout << "Vaga " << vaga << " j� estava liberada!" << endl;
                    return true;
                }else{
                    cout << "Voc� liberou a vaga " << vaga << endl;
                    estacionamento[i][j] == 0;
                    return false;
            }
            }else{
                vaga--;
            }
        }
    }
}

int contarVagasLivres(const int (&estacionamento)[4][5]){ //v1
    int contador=0;
    for (int i; i<4; i++){
        for (int j; j<5; j++){
            if (estacionamento[i][j] == 0){
                contador++;
            }
        }
    }
    return contador;
}

int contarVagasLivres(int vaga, const int (&estacionamento)[4][5]){ // v2 (fileiras)
    int contador=0, linha, coluna;
    for (int i; i<4; i++){
        for (int j; j<5; j++){
            if (vaga == 0){
                linha = i;
                coluna = j;
            }else{
                vaga--;
            }
        }
    }

    for (int i; i<4; i++){
        for (int j; j<5; j++){
            if (i==linha || j==coluna){
                contador++;
            }
        }
    }

    return contador;
}