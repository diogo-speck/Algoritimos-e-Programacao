#include <iostream>
using namespace std;

void exibirMenu(); 
char lerOpcao(); 
double lerNumero(); 
double somar(double a, double b); 
double subtrair(double a, double b); 
double multiplicar(double a, double b); 
bool divisaoValida(double divisor);
double dividir(double a, double b); 
void exibirResultado(double resultado);

int main(){

    double numero, resultado;
    char escolha = 'A';

    while(escolha!='S'){
        exibirMenu();
        escolha = lerOpcao();
        exibirResultado(resultado);
    }
    cout << "\nSaindo...";

    return 0;
}

void exibirMenu(){
    cout << "\nMenu"
    << "\n1 - Somar"
    << "\n2 - Subtrair"
    << "\n3 - Multiplicar"
    << "\n4 - Dividir"
    << "\nS - Sair"
    << "\nEscolha: ";
} 

char lerOpcao(){
    char c;
    cin >> c;
    double valor1, valor2;
    valor1 = lerNumero();
    valor2 = lerNumero();
    switch (c)
    {
    case 1:
        somar(valor1,valor2);
        return '1';
    case 2:
        subtrair(valor1,valor2);
        return '2';
    case 3:
        multiplicar(valor1,valor2);
        return '3';
        break;
    case 4:
        dividir(valor1,valor2);
        return '4';
    case 'S':
        return 'S';
    default:
        return '0';
    }
} 

double lerNumero(){
    double valor;
    cout << "\nDigite um número: ";
    cin >> valor;
    return valor;
} 

double somar(double a, double b){
    exibirResultado(a+b);
    return a+b;
} 
double subtrair(double a, double b){
    exibirResultado(a-b);
    return a-b;
}  
double multiplicar(double a, double b){
    exibirResultado(a*b);
    return a*b;
}  
bool divisaoValida(double divisor){
    if (divisor == 0){
        return false;
    }else{
        return true;
    }
}
double dividir(double a, double b){
    if (divisaoValida(b)){
        return a+b;
    }else{
        cout << "\nDivisão por 0";
        return 0;
    }
}  


void exibirResultado(double resultado){
    cout << "\nSeu resultado é: " << resultado;
} 