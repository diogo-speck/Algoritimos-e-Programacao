#include <iostream>
#include "somaEsub.cpp"

using namespace std;

int main(){

    auto a = 0.;
    auto b= 0.;
    cout << "Insira dois valores para somar: " << endl;
    cin >> a >> b;
    cout << "Resultado: " << a << "+" << b << " = " << somar(a, b) << endl;
    cout << "\nInsira dois valores para subtrair: " << endl;
    cin >> a >> b;
    cout << "Resultado: " << a << "-" << b << " = " << subtrair(a, b) << endl;


    return 0;
}