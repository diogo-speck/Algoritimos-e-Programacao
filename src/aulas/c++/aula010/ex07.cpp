#include <iostream>
#include <iomanip>
//#include <limits>
using namespace std;

int main() {
    
    int c = 1;
    long long graos = 1;
    // A soma total dos grãos se dá pela fórmula 1+2+4+8+⋯+2n−1=2n−1 (progressão geométrica de razão 2 iniciando em 1)


    cout << "O problema dos grãos de arroz" << endl;
    
    cout << "Quantidade mínima de casas para:\n" << endl;

    
    for (graos; graos<1000; graos = graos*2){
        cout << graos << " grãos | " << c << " | (" << 2*graos-1 << ")" << endl;
        c++;
    }
    cout << "\n1.000 grãos - " << c << "\n" << endl;
    
    
    for (graos; graos<1000000; graos = graos*2){
        cout << graos << " grãos | " << c << " | (" << 2*graos-1 << ")" << endl;
        c++;
    }
    cout << "\n1.000.000 grãos - " << c << "\n" << endl;
    
    
    for (; graos<1000000000; graos = graos*2){ // sem o graos; só com ; indica que não inicializa
        cout << graos << " grãos | " << c << " | (" << 2*graos-1 << ")" << endl;
        c++;
    }
    cout << "\n1.000.000.000 grãos - " << c << "\n" << endl;

    // Item 2 — Representação do tabuleiro

    double tabuleiro [8][8]; // Tem que ser double para a Notação Científica funcionar
    graos = 1;
    c = 1;
    int i=0,j=0;

    for (graos; c<65; graos = graos*2){
        //cout << graos << " grãos | " << c << " | (" << 2*graos-1 << ")" << endl;
        if (c==64){
            graos--; // Tirei 1 unidade para não dar Overflow
        }
        tabuleiro[i][j] = graos;
        c++;
        if ((j+1)%8==0){
            i = (i+1)%8;
        }
        j = (j+1)%8;
    }

    for (int i=0; i<size(tabuleiro); i++){
        for (int j=0; j<size(tabuleiro[0]); j++){ // Melhor para matrizes quadradas
            cout << " | " << scientific << setprecision(3) << tabuleiro[i][j] << " | "; // Notação científica com 4 casas decimais
        }
        cout << "\n" << endl;
    }

    /*cout << numeric_limits<long long int>::max();
        "Nove quintilhões, duzentos e vinte e três quatrilhões,
         trezentos e setenta e dois trilhões, trinta e seis bilhões,
         oitocentos e cinquenta e quatro milhões, setecentos e setenta e cinco mil, oitocentos e sete."
    */


    return 0;
}