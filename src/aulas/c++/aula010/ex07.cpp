#include <iostream>
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

    // Todo Item 2 — Representação do tabuleiro


    return 0;
}