#include <iostream>
#include <iomanip> // fixed e setprecision (formatação do número de casas decimais desejadas)
#include <string>
#include <clocale>
#include <random>
using namespace std;

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    cout << "Exemplo 1:" << endl;
    int idade = 0;
    float altura = 0;
    double salario = 0;
    char sexo = ' ';
    bool ativo = true;
    string nome;

    /*
    Para seeds NÃO aleatórias usa-se:
    default_random_engine gerador(123456); (exemplo)
    */

    random_device rd;
    default_random_engine gerador(rd());
    uniform_int_distribution<int> distribuicao(1621,10000); // intervalo fechado


    salario = distribuicao(gerador); // gera um salário aleatório
    cout << salario << endl;

    cout << "Digite seu nome: " << endl;
    getline(cin, nome);
    cout << "Digite seu sexo: " << endl;
    cin >> sexo;
    cout << "Digite sua idade (em anos): " << endl;
    cin >> idade;
    cout << "Digite sua altura (em metros): " << endl;
    cin >> altura;
    cout << "Digite seu salário (mensal): " << endl;
    cin >> salario;
    cout << "Se deseja encerrar sua conta digite \"0\": " << endl;
    cin >> ativo;
    ativo != 0 ? ativo = 1 : ativo = 0; // Condicional composta ternária ((expressão booleana) ? código 1 [if] : código 2 [else]; )
    // cout << ativo << endl;
    cout << fixed << setprecision(2); // formata 2 casas decimais depois da vírgula
    cout << "Seu nome é "+nome+", você tem "+ to_string(idade) +" anos de idade, se identifica com o sexo \"" << sexo << "\", tem " << altura << "m de altura, seu salário mensal é R$" << salario << " e você optou por deixar sua conta ";
    ativo != 0 ? cout << "ativa" : cout << "desativada";
    cout << endl;

    return 0;
}