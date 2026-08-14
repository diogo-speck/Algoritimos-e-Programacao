#include <iostream>

using namespace std;

void exibirEstacionamento();
bool vagaValida(int vaga);
bool ocuparVaga(int vaga);
bool liberarVaga(int vaga);
int contarVagasLivres(); // v1
int contarVagasLivres(); // v2 (fileiras)

int main()
{
    bool ativo = true;
    int vaga, linha, coluna;
    cout << "Controle de Vagas de um Estacionamento" << endl;
    cin.get(); // Pede enter para o user
    int estacionamento[4][5]{};

    // linha = (vaga- 1) / 5;
    // coluna = (vaga- 1) % 5;

    while(ativo){

        int escolha = 0;

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

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

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

void exibirEstacionamento(){
    for (int i; i<4; i++){
        for (int j; j<5; j++){
            cout << estacionamento[4][5];
        }
        cout << endl;
    }

}
bool vagaValida(int vaga);
bool ocuparVaga(int vaga);
bool liberarVaga(int vaga);
int contarVagasLivres(); // v1
int contarVagasLivres(); // v2 (fileiras)
