#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>

int main()
{   
    int vez = 0;
    
    
    char matriz [3][3] ={ {' ',' ',' '},
                         {' ',' ',' '},
                         {' ',' ',' '}};
    
    int reveladas [3][3] ={ {'0','0','0'},
                         {'0','0','0'},
                         {'0','0','0'}};

    
    bool jogoEncerrou =  true;
    int linha, coluna;
    char escolha;
    
    cout << "---> JOGO DA VELHA <---" << endl;
    
    for (int i =0; i<9; i++){
    cout << "\nSelecione a sua jogada: (linha e coluna) "<< endl;
    cin >> linha >> coluna;
    cout << "Coordenadas: " <<linha <<"x" << coluna << endl;
    cout << "Escolha X ou O: ";
    cin >> escolha;
    matriz[linha - 1][coluna - 1] = escolha;
    reveladas[linha - 1][coluna - 1] = 1;
    
      for (int i =0; i<3; i++){
        cout << "\n";
            for (int j=0; j<3; j++){
                cout << "|" << matriz [i][j]<< "|";
            }
    }
    
    for (int i =0; i<3; i++){
        for (int j =0; j <3; j ++){
            if(reveladas[i][j] == 0) {
                jogoEncerrou == false;
            }
        }
    }
    
    }
        
        cout << "\nAcabou o jogo" << endl;
        for (int i =0; i<3; i++){
        cout << "\n";
            for (int j=0; j<3; j++){
                cout << "|" << matriz [i][j]<< "|";
            }
        }
        exit(EXIT_SUCCESS);
    
    return 0;
}