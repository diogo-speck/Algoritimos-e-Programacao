#include <iostream>
#include "varegista.hpp"
using namespace std;

int main(){

    Produto produtos[5]{
        {23, "Arroz", 3.49},
        {35, "Feijão", 4.29},
        {13, "Farinha", 6.99},
        {97, "Batata", 2.49},
        {67, "Vodka Russa (teor 90% alcool)", 349.99},
    };

    imprimirProduto(produtos[4]);
    imprimirProdutos(produtos, 5);
    calcularMediaPrecos(produtos, 5);

    int codigo;
    cout << "Digite um código de produto para procurar: ";
    cin >> codigo;
    cout << buscarProduto(produtos, 5, codigo);

    return 0;
}