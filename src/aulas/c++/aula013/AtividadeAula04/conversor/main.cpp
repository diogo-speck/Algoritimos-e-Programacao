#include <iostream>
#include "conversoes.h"
#include "conversoes.hpp"
using namespace std;

int main(){

    // (0 °C × 9/5) + 32 = 32 °F
    double temp, dist;

    cout << "Digite um valor para converter de Celsius para Fahrenheit: " << endl;
    cin >> temp;
    cout << "Sua temperatura em Fahrenheit: " << celsiusParaFahrenheit(temp) << endl;
    cout << "Digite um valor para converter de Fahrenheit para Celsius: " << endl;
    cin >> temp;
    cout << "Sua temperatura em Celsius: " << fahrenheitParaCelsius(temp) << endl;

    cout << "Digite um valor para converter de Centímetros para Polegadas: " << endl;
    cin >> dist;
    cout << "Seu valor em Polegadas: " << centimetrosParaPolegadas(dist) << endl;
    cout << "Digite um valor para converter de Polegadas para Centímetros: " << endl;
    cin >> dist;
    cout << "Seu valor em Centímetros: " << polegadasParaCentimetros(dist) << endl;

    cout << "Digite um valor para converter de Quilômetros para Milhas: " << endl;
    cin >> dist;
    cout << "Seu valor em Milhas: " << quilometrosParaMilhas(dist) << endl;
    cout << "Digite um valor para converter Milhas para Quilômetros: " << endl;
    cin >> dist;
    cout << "Seu valor em Quilômetros: " << milhasParaQuilometros(dist) << endl;

    return 0;
}