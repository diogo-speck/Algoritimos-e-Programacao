/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>

int main()
{   
    
    char matriz [3][3] ={ {' ',' ',' '},
                         {' ',' ',' '},
                         {' ',' ',' '}};
    
    
    bool venceu = false;
    int linha, coluna;
    int jogadas =0;
    char jogadorAtual= 'X';
    
    cout << "---> JOGO DA VELHA <---" << endl;
    for (int i =0; i<3; i++){
        cout << "\n";
            for (int j=0; j<3; j++){
                cout << "|" << matriz [i][j]<< "|";
            }
    } cout<< endl;
    
    while (!venceu && jogadas<9){
    cout << "\nVez do Jogador "<<jogadorAtual << endl;
    cout << "Selecione a sua jogada: (linha e coluna, de 1 a 3) "<< endl;
    cin >> linha >> coluna;
    
    if(linha <1 || linha >3 || coluna < 1 || coluna >3){
        cout << "Coordenadas inválidas! Use números de 1 a 3." << endl;
        continue;
    }
    
    if(matriz[linha - 1][coluna - 1] != ' ') {
        cout<< "Essa casa ja foi jogada, ou, está fora dos padrões do jogo, escolha outra!" << endl;
        continue;
    } 
    
    cout << "Coordenadas: " <<linha <<"x" << coluna << endl;
    
    matriz[linha-1][coluna-1] = jogadorAtual;
    jogadas++;
    
      for (int i =0; i<3; i++){
        cout << "\n";
            for (int j=0; j<3; j++){
                cout << "|" << matriz [i][j]<< "|";
            }
    } cout<< endl;
    
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
        
        if(!venceu) {
            if (jogadorAtual == 'X'){
                jogadorAtual = 'O';
            } else
            jogadorAtual = 'X';
        }
        
    }
    
        cout << "\nAcabou o jogo!" << endl;
        for (int i =0; i<3; i++){
            cout << "\n";
            for (int j=0; j<3; j++){
                cout << "|" << matriz [i][j]<< "|";
            }
        }
        if (!venceu) {
            cout << "\n\nEMPATADO"<< endl;
        } else {
            cout << "\nJogador " <<jogadorAtual<<" foi o GRANDE VENCEDOR!" <<endl;
            exit(EXIT_SUCCESS);
            }
        return 0;
    }