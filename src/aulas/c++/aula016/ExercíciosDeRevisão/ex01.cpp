#include <iostream>
using namespace std;

// protótipos das funções
double lerValor(); 
bool valorValido(double valor); 
double calcularCombustivel(double distancia, double consumoMedio); 
double calcularCustoCombustivel(double quantidadeCombustivel, double precoLitro); 
double calcularCustoPorPessoa(double custoTotal, int quantidadePessoas); 
void exibirResultado(double combustivel, double custoTotal, double custoPorPessoa);

int main(){

    cout << "Calculadora de Viagem" << endl;

    double distancia = 0;
    double cmedio = 0;
    double preco = 0;
    int pessoas = 0;
    double combustivel = 0;
    double total = 0;
    double cpp = 0;

    cout << "Distância em quilômetros" << endl;
    while (!valorValido(distancia)){
        distancia = lerValor();
    }
    //cout << distancia << endl;
    cout << "Consumo Médio em quilômetros por litro" << endl;
    while (!valorValido(cmedio)){
        cmedio = lerValor();
    }
    cout << "Preço do litro do combustível" << endl;
    while (!valorValido(preco)){
        preco = lerValor();
    }
    cout << "Quantidade de Pessoas" << endl;
    while (!valorValido(pessoas)){
        pessoas = int(lerValor());
    }

    combustivel = calcularCombustivel(distancia, cmedio);
    total = calcularCustoCombustivel(combustivel, preco);
    cpp = calcularCustoPorPessoa(total, pessoas);

    exibirResultado(combustivel, total, cpp);


    return 0;
}


// definições das funções

double lerValor(){
    double valor;
    cout << "Insira um valor: ";
    cin >> valor;
    return valor;
} 

bool valorValido(double valor){
    if (valor>0){
        return true;
    }else{
        cout << "Precisa ser maior que 0!" << endl;
        return false;
    }
}

double calcularCombustivel(double distancia, double consumoMedio){
    return distancia / consumoMedio;
}

double calcularCustoCombustivel(double quantidadeCombustivel, double precoLitro){
    return quantidadeCombustivel * precoLitro;
} 

double calcularCustoPorPessoa(double custoTotal, int quantidadePessoas){
    return custoTotal / quantidadePessoas;
}

void exibirResultado(double combustivel, double custoTotal, double custoPorPessoa){
    cout << "O combustível necessário para a viagem será de ";
    printf("%.2f\n", combustivel);

    cout << "Esse combustível custará R$";
    printf("%.2f\n", custoTotal);

    cout << "Cada pessoa deverá pagar R$";
    printf("%.2f", custoPorPessoa);
}