#include <iostream>
using namespace std;

template <typename T>
void imprimirVetor(int * (&vetor), T (&linhas));

template <typename T>
void imprimirVetor(int ** (&matriz), T (&linhas), T (&colunas));

int maiorValor(int * (&vetor), int (&linhas));

int maiorValor(int ** (&matriz), int (&linhas), int (&colunas));


int main(){

    int linhas = 1, colunas = 1;
    cout << "Insira o tamanho do seu array/matriz (ex. 4 5): " << endl;
    cin >> linhas >> colunas;

    if (colunas <= 1){
        colunas = 1;
    }

    
    int *vetor;
    vetor = new int[linhas];
    for(int i = 0; i < linhas; ++i) {
        vetor[i] = 0;
    }
    

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

    cout << endl;

    if (colunas == 1){
        imprimirVetor(vetor, linhas);
        cout << "Maior valor: " << maiorValor(vetor, linhas) << endl;
    }
    else{
        imprimirVetor(matriz, linhas, colunas);
        cout << "Maior valor: " << maiorValor(matriz, linhas, colunas) << endl;
    }

    
    




    // Liberando memória
    for(int i = 0; i < linhas; ++i) {
        delete[] matriz[i];
    }

    delete[] matriz;
    delete[] vetor;

    return 0;
}

template <typename T>
void imprimirVetor(int * (&vetor), T (&linhas)){
    for(T i = 0; i < linhas; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

template <typename T>
void imprimirVetor(int ** (&matriz), T (&linhas), T (&colunas)){
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            cout << matriz[i][j] << " ";
        }
    cout << endl;
    }
}


int maiorValor(int * (&vetor), int (&linhas)){
    int maior = vetor[0];
    for(int i = 0; i < linhas; i++){
        if (vetor[i]>maior){
            maior = vetor[i];
        }
    }
    return maior;
}

int maiorValor(int ** (&matriz), int (&linhas), int (&colunas)){
    int maior = matriz[0][0];
    for(int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (matriz[i][j]>maior){
                maior = matriz[i][j];
            }
        }
    }
    return maior;
}