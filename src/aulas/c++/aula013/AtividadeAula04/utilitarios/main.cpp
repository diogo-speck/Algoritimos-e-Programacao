#include <iostream>
#include "utils.h"
using namespace std;

int main(){

    auto valor=0, minimo=0, maximo=0, a=0, b=0;
    string esta = "";
    cout << "Digite um valor, um mínimo e um máximo de um intervalo: " << endl;
    cin >> valor >> minimo >> maximo;
    if (estaentre(valor, minimo, maximo)==false){
        esta += " não";
        cout << "O valor " << valor << " foi limitado para " << limitar(valor, minimo, maximo) << endl;        
    }else{
        cout << "O valor " << valor << " não foi limitado" << endl;
    }
    cout << "O valor " << valor << esta << " está dentro do intervalo [" << minimo << "," << maximo << "]" << endl;
    cout << "Digite 2 novos valores: " << endl;
    cin >> a >> b;
    cout << "O maior valor é " << maior(a, b) << endl;
    cout << "O menor valor é " << menor(a, b) << endl;
    trocar(a,b);
    cout << "Agora " << a << " é " << b << " e " << b << " é " << a << endl;
    
    return 0;
}