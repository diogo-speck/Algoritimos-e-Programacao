#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int c=97;
    char letra = ' ';
    cout << "Tabela de caracteres com while" << endl;
    
    while(c<123){
        letra = c;
        cout << "Caractere: " << letra << " | Valor inteiro: " << setw(3) << setfill('0') <<c << endl;
        c++;
    }

    return 0;
}