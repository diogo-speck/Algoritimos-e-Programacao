#include <iostream>
using namespace std;

template <typename T, size_t N>
void imprimirVetorUni(const T (&vetor)[N]);

template <typename T, size_t M, size_t  N>
void imprimirVetorBi(const T (&vetor)[M][N]);

int main(){

    int linhas = 1, colunas = 1;
    cout << "Insira o tamanho do seu estacionamento (ex. 4 5): " << endl;
    cin >> linhas >> colunas;

    cout << endl;

    // Alocação dinâmica de ponteiro para ponteiro
    int **matriz = new int*[linhas];
    for(int i = 0; i < linhas; ++i) {
        matriz[i] = new int[colunas];
    }

    // Preenchendo a matriz
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            matriz[i][j] = 0;
        }
    }

    // Imprimindo a matriz
    for(int i = 0; i < linhas; ++i) {
        for(int j = 0; j < colunas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Liberando memória
    for(int i = 0; i < linhas; ++i) {
        delete[] matriz[i];
    }

    delete[] matriz;

    return 0;
}

template <typename T, size_t N>
void imprimirVetorUni(const T (&vetor)[N]){
    for(size_t i = 0; i < N; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

template <typename T, size_t M, size_t  N>
void imprimirVetorBi(const T (&vetor)[M][N]){
    for(size_t i = 0; i < N; i++){
        for (size_t j = 0; j < M; j++){
            cout << vetor[i][j] << " ";
        }
    cout << endl;
    }
}