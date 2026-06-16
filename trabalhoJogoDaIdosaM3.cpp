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
    int linha, coluna, contagem = 0;
    char jogadorAtual= 'X';
    
    cout << "---> JOGO DA VELHA <---" << endl;
    
    while(!venceu&&contagem<9){
        cout << "\nVez do Jogador " << jogadorAtual << endl;
        cout << "Selecione a sua jogada (linha coluna de 1 a 3): "<< endl;
        cin >> linha >> coluna;
        while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || reveladas[linha-1][coluna-1] != 0){
            cin.clear(); // limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // descarta o resto da linha
            cout << "Posição " << linha << "x" << coluna << " inválida ou já escolhida" << endl;
            cout << "Selecione a sua jogada (linha coluna de 1 a 3): "<< endl;
            cin >> linha >> coluna;
        }
        cout << "Coordenadas: " <<linha <<"x" << coluna << endl;
        matriz[linha - 1][coluna - 1] = jogadorAtual;
        reveladas[linha - 1][coluna - 1] = 1;
        contagem ++;

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

        if (jogadorAtual == 'X' && contagem<9 && (!venceu)){
            jogadorAtual = 'O';
        }
        else if(jogadorAtual == 'O' && contagem<9 && (!venceu)){
            jogadorAtual = 'X';
        }
        
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