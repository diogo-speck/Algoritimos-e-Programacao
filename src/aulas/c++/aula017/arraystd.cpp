#include <iostream>
#include <stdlib.h>
#include <array>
#include <vector>
using namespace std;

template <typename T, size_t N>
void imprimir(const array<T, N>& v);

int main(){

    /*
    containers, algoritmos e iteradores
    array<tipo, tamanho> nome;
    sort, find, count, begin, end
    at, empty, fill, front(1), back(último), size
    array<int,5>& v - referência
    array de arrays = matriz
    */

    printf("Oi");

    array <string, 7> lista{"Olá", "esse", "é", "um", "array", "de"};

    cout << "\n" << lista.at(0) << endl; //garantir que está in bound

    cout << "Tamanho: " << lista.size() << endl;

    // Range-based for 
    for (string txt : lista) {
    cout << txt << " ";
    }

    cout << endl << lista.front() << " ";
    lista.fill("texto");
    cout << lista.back() << endl;

    for (string n : lista) {
    cout << n << " ";
    }

    cout << "\nVazio: " << lista.empty() << endl;

    /*
    array<array<int, 3>, 3> matriz{};

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << "Valor [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}