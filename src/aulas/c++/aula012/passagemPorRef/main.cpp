#include <iostream>

using namespace std;

double soma(double a, double b=0);
int soma(int a, int b=0, int c=0);
void exibirNome(const string& nome);

int main()
{
    system("cls");

    double v1 = 1;
    // Function Overloading
    cout << soma(v1) << endl;

    string nome = "Diogo Speck";
    exibirNome("Thomas Turbo");
    cout << "Nome original: " << nome << endl;


    return 0;
}

double soma(double a, double b){
    return a+b;
}

int soma(int a, int b, int c){
    return a+b+c;
}

void exibirNome(const string& nome){
    cout << "Nome: " << nome << endl;
}