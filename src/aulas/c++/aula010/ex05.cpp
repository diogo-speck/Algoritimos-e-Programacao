#include <iostream>
using namespace std;

int main() {

    bool primo = true;
    int tamanho = 0, indice = 0;
    int* vetor;

    cout << "Números primos em um vetor" << endl;
    
    for (int k=0; k<2;k++){
        for (int i=2;i<101;i++){
            for (int j=2; j<i;j++){
                if (i%j==0){ // não precisa de && i!=j porque j<i já não inclui
                    primo = false;
                    break;
                }
            }
            if (primo){
                if (k==1){
                    vetor[indice] = i;
                    indice++;
                }else{
                    tamanho++;
                }
                //cout << i << " ";
            }
            primo = true;
        }
        if (k==0){
            //cout << tamanho << endl;
            vetor = new int[tamanho];
        }
        //cout << tamanho << endl;

    }
    cout << "Números primos de 1 a 100 armazenados no vetor: " << endl;

    for (int i=0; i<tamanho;i++){
        cout << vetor[i] << " ";
    }

    cout << endl;

    cout << "Primos encontrados: " << tamanho;

    delete[] vetor;
    return 0;
}