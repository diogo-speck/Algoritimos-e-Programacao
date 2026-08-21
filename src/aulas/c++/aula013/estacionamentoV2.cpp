#include <iostream>
#include <cctype>

using namespace std;

template <typename T>
void exibirEstacionamento(int ** (&estacionamento), T (&m), T (&n));

template <typename T>
bool vagaValida(T vaga, T (&m), T (&n));

template <typename T>
bool ocuparVaga(T vaga, int ** (&estacionamento), T (&m), T (&n));

template <typename T>
bool liberarVaga(T vaga, int ** (&estacionamento), T (&m), T (&n));

template <typename T>
int contarVagasLivres(int ** (&estacionamento), T (&m), T (&n)); // v1

template <typename T>
int contarVagasLivres(T vaga, int ** (&estacionamento), T (&m), T (&n)); // v2 (linha)

int main()
{
    bool ativo = true;
    int vaga, m=1, n=1;
    cout << "Controle de Vagas de um Estacionamento" << endl;

    cout << "Insira o tamanho do seu estacionamento (ex. 4 5): " << endl;
    cin >> m >> n;

    cout << endl;

    // Alocação dinâmica de ponteiro para ponteiro
    int **estacionamento = new int*[m];
    for(int i = 0; i < m; ++i) {
        estacionamento[i] = new int[n];
    }

    // Preenchendo a estacionamento
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            estacionamento[i][j] = 0;
        }
    }

    /*
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << estacionamento[i][j] << " ";
        }
        cout << endl;
    }
    */


    while(ativo){

        int escolha = 0;

        cout << "\nFuncionalidades: " << endl;
        cout << "1 - Visualizar o estacionamento" << endl;
        cout << "2 - Ocupar uma vaga" << endl;
        cout << "3 - Liberar uma vaga" << endl;
        cout << "4 - Consultar a quantidade total de vagas livres" << endl;
        cout << "5 - Consultar a quantidade de vagas livres na linha de uma vaga" << endl;
        cout << "6 - Sair do programa" << endl;
        cout << "Escolha: ";

        cin >> escolha;

        switch(escolha){
            case 1:
                exibirEstacionamento(estacionamento, m, n);
                break;
            case 2:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga, m, n)){
                    ocuparVaga(vaga, estacionamento, m, n);
                }else{
                    cout << "Vaga inválida" << endl;
                }
                break;
            case 3:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga, m, n)){
                    liberarVaga(vaga, estacionamento, m, n);
                }else{
                    cout << "Vaga inválida" << endl;
                }
                break;
            case 4:
                cout << "Vagas livres no estacionamento: " << contarVagasLivres(estacionamento, m, n) << endl;
                break;
            case 5:
                cout << "Digite a vaga: ";
                cin >> vaga;
                if (vagaValida(vaga, m, n)){
                    cout << "Vagas livres na linha: " << contarVagasLivres(vaga, estacionamento, m, n) << endl;
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

    // Liberando memória
    for(int i = 0; i < m; ++i) {
        delete[] estacionamento[i];
    }

    delete[] estacionamento;

    return 0;
}


template <typename T>
void exibirEstacionamento(int ** (&estacionamento), T (&m), T (&n)){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << estacionamento[i][j] << " ";
        }
        cout << endl;
    }

}

template <typename T>
bool vagaValida(T vaga, T (&m), T (&n)){
    return vaga>0&&vaga<=m*n;
}

template <typename T>
bool ocuparVaga(T vaga, int ** (&estacionamento), T (&m), T (&n)){
    int linha = (vaga- 1) / m;
    int coluna = (vaga- 1) % n;
    
    if (estacionamento[linha][coluna] == 0){
        estacionamento[linha][coluna] = 1;
        cout << "Você ocupou a vaga " << vaga << endl;
        return true;
    }else{
        cout << "Vaga " << vaga << " já ocupada!" << endl;
    }
    return false;
}

template <typename T>
bool liberarVaga(T vaga, int ** (&estacionamento), T (&m), T (&n)){
    int linha = (vaga- 1) / m;
    int coluna = (vaga- 1) % n;
    
    if (estacionamento[linha][coluna] == 1){
        cout << "Você liberou a vaga " << vaga << endl;
        estacionamento[linha][coluna] = 0;
        return true;
    }else{
        cout << "Vaga " << vaga << " já estava liberada!" << endl;
    }
    return false;
}

template <typename T>
int contarVagasLivres(int ** (&estacionamento), T (&m), T (&n)){ //v1
    int contador=0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (estacionamento[i][j] == 0){
                contador++;
            }
        }
    }
    return contador;
}

template <typename T> // Refazer
int contarVagasLivres(T vaga, int ** (&estacionamento), T (&m), T (&n)){ // v2 (linha)
    int linha = (vaga - 1) / n;
    int contador = 0;

    for (int j = 0; j < n; j++) {
        if (estacionamento[linha][j] == 0) {
            contador++;
        }
    }

    // Se a própria vaga estiver livre
    if (estacionamento[linha][(vaga - 1) % n] == 0) {
        contador++;
    }
    if (estacionamento[linha][(vaga - 1) % n] == 1) {
        contador--;
    }

    return contador;
}