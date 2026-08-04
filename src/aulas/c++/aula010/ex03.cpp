#include <iostream>
using namespace std;

int main() {
    
    int c=97;
    char letra = ' ';
    cout << "Tabela de caracteres com while" << endl;
    
    while(c<123){
        letra = c;
        cout << "Caractere: " << letra << " | Valor inteiro: " << c << endl;
        c++;
    }

    return 0;
}