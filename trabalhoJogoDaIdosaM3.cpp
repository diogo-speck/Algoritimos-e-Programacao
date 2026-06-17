#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace std;

int main()
{   
    char matriz [3][3] = {{' ',' ',' '},
                          {' ',' ',' '},
                          {' ',' ',' '}};
    
    bool venceu =  false;
    int linha, coluna, contagem = 0;
    char jogadorAtual= 'X';
    
    cout << "---> JOGO DA VELHA <---" << endl;
    
    while(!venceu&&contagem<9){
        cout << "\nVez do Jogador " << jogadorAtual << endl;
        cout << "Selecione a sua jogada (linha coluna de 1 a 3): "<< endl;
        cin >> linha >> coluna;
        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida, digite números de 1 a 3: " << endl;

            continue;
        }
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || matriz[linha-1][coluna-1] != ' '){
            cout << "Posição " << linha << "x" << coluna << " já escolhida" << endl;
            cout << "Selecione a sua jogada (linha coluna de 1 a 3): "<< endl;
            continue;
        }
        cout << "Coordenadas: " <<linha <<"x" << coluna << endl;
        matriz[linha - 1][coluna - 1] = jogadorAtual;
        
        for (int i =0; i<3; i++){
            cout << "\n";
            for (int j=0; j<3; j++){
                cout << "|" << matriz [i][j]<< "|";
            }
        }
        
        for (int i = 0; i<3; i++){ 
            if (matriz[i][0] == jogadorAtual && 
                matriz[i][1] == jogadorAtual && 
                matriz[i][2] == jogadorAtual){
                    venceu = true;
                }
            else if (matriz[0][i] == jogadorAtual && 
                    matriz[1][i] == jogadorAtual && 
                    matriz[2][i] == jogadorAtual){
                        venceu = true;   
                    }
        }
            
        if (matriz[0][0]==jogadorAtual && matriz[1][1]== jogadorAtual && matriz [2][2]==jogadorAtual){
            venceu = true;
        }
        if (matriz[2][0]==jogadorAtual && matriz[1][1]== jogadorAtual && matriz [0][2]==jogadorAtual){
            venceu = true; 
        }

        if (jogadorAtual == 'X' && contagem<8 && (!venceu)){
            jogadorAtual = 'O';
        }
        else if(jogadorAtual == 'O' && contagem<8 && (!venceu)){
            jogadorAtual = 'X';
        }
        contagem ++;
    }
    
    cout << "\nAcabou o jogo" << endl;
    for (int i =0; i<3; i++){
    cout << "\n";
        for (int j=0; j<3; j++){
            cout << "|" << matriz [i][j]<< "|";
        }
    }
    if (venceu){
        cout << "\nJogador " << jogadorAtual << " venceu" << endl;
    }
    else{
        cout << "\nDeu velha" << endl;
    }
       
    
    return 0;
}