#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>

int main()
{   
    char matriz [3][3] = {{' ',' ',' '},
                          {' ',' ',' '},
                          {' ',' ',' '}};
    
    int reveladas [3][3] = {{0,0,0},
                            {0,0,0},
                            {0,0,0}};

    
    bool venceu =  false;
    int linha, coluna, turno = 0, contagem = 0;
    char jogadorAtual= 'X';
    
    cout << "---> JOGO DA VELHA <---" << endl;
    
    while(!venceu&&contagem<9){
        cout << "\nVez do Jogador " << jogadorAtual << endl;
        cout << "Selecione a sua jogada (linha coluna de 1 a 3): "<< endl;
        cin >> linha >> coluna;
        while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || reveladas[linha-1][coluna-1] != 0){
            cout << "Posição " << linha << "x" << coluna << " inválida ou já escolhida" << endl;
            cout << "Selecione a sua jogada (linha coluna de 1 a 3): "<< endl;
            cin >> linha >> coluna;
        }
        cout << "Coordenadas: " <<linha <<"x" << coluna << endl;
        matriz[linha - 1][coluna - 1] = jogadorAtual;
        reveladas[linha - 1][coluna - 1] = 1;

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
            }
                
            for (int j = 0; j<3; j++){ 
                if (matriz[0][j] == jogadorAtual && 
                    matriz[1][j] == jogadorAtual && 
                    matriz[2][j] == jogadorAtual){
                    venceu = true;
                    
                    
                }
            }
            
            if (matriz[0][0]==jogadorAtual && matriz[1][1]== jogadorAtual && matriz [2][2]==jogadorAtual){
                venceu = true;
                
                
            }
            if (matriz[2][0]==jogadorAtual && matriz[1][1]== jogadorAtual && matriz [0][2]==jogadorAtual){
                venceu = true;
                
                
            }

        if (turno == 0 && contagem<8 && (!venceu)){
            jogadorAtual = 'O';
            turno ++;
        }
        else if(turno != 0 && contagem<8 && (!venceu)){
            jogadorAtual = 'X';
            turno --;
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