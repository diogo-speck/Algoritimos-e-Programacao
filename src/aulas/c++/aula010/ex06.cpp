#include <iostream>
#include <random>
using namespace std;

int main() {
    
    random_device rd;
    default_random_engine gerador(rd());
    uniform_int_distribution<int> distribuicao(1,100);
    
    int m, n, num, c;

    cout << "Localizando vizinhos em uma matriz" << endl;
    cout << "Digite um valor para o M (quantidade de linhas) e N (quantidade de colunas) de uma matriz (ex. 3 3): " << endl;
    cin >> m >> n;
    
    int matriz [m][n];

    cout << "Matriz gerada:" << endl;
    for (int i=0; i<m;i++){
        for (int j=0; j<n; j++){
            matriz[i][j] = distribuicao(gerador);
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Digite um número para conferir suas ocorrências: " << endl;
    cin >> num;

    for (int i=0; i<m;i++){
        for (int j=0; j<n; j++){
            if (matriz[i][j]==num){
                c++;

                cout << num << " " << i <<"x" << j << ":" << endl;

                if (j>0){
                    cout << "O número da esquerda é " << matriz[i][j-1] << endl;
                }
                if (i>0){
                    cout << "O número acima é " << matriz[i-1][j] << endl;
                }
                if (j+1<n){
                    cout << "O número da direita é " << matriz[i][j+1] << endl;
                }
                if (i+1<m){
                    cout << "O número abaixo é " << matriz[i+1][j] << endl;
                }
                cout << endl;

            }
        }
        cout << endl;
    }
    cout << "O número " << num << " aparece " << c << " vez(es)" << endl;


    return 0;
}