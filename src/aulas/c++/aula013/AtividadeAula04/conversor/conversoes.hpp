#pragma once
#include "conversoes.h"

double celsiusParaFahrenheit(double valor){
    return valor*9/5+32;
}
double fahrenheitParaCelsius(double valor){
    return (valor-32)*5/9;
}

double centimetrosParaPolegadas(double valor){
    return valor/2.54;
}
double polegadasParaCentimetros(double valor){
    return valor*2.54;
}

double quilometrosParaMilhas(double valor){
    return valor/1.609;
}
double milhasParaQuilometros(double valor){
    return valor*1.609;
}