/*
5. Desenvolva e explique um exemplo para cada uma das situações abaixo: 
• Uma função que exiba uma mensagem na tela; 
• Uma função que receba dois números e apresente a soma; 
• Uma função que receba dois números e retorne o maior valor. 
*/

#include <iostream>
using namespace std;

string texto() // Função que exibe uma mensagem na tela; 
{
    return "Hello World"; 
}

int soma(int x, int y){ // Função que recebe dois números e apresenta a soma;
    return x+y;
}

bool maior(int x, int y){ // Função que receba dois números e retorne se o 1º valor é maior que o 2º valor;
    if(x>y){
        return true; // true = 1
    }
    else{
        return false; // false = 0
    }
}

int main()
{
    cout << texto() << endl; // Precisa printar a função sem parâmetros com retorno se quiser que ela mostre algo no terminal, além de usar um () para chamar a função
    cout << soma(1,2) << endl; // Função com parâmetros com retorno
    int v1,v2;
    cout << "Insira um valor inteiro para ver se ele é maior que outro valor: " << endl;
    cin >> v1;
    cout << "Insira o outro valor inteiro: " << endl;
    cin >> v2;
    cout << maior(v1,v2) << endl;
    if (maior(v1,v2)){
        cout << "V1>V2" << endl;
    }
    else{
        cout << "V1<=V2" << endl;
    }

    return 0;
}