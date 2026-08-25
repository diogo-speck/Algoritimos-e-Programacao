#include "mercadinho.hpp"
using namespace std;

int main(){

    Produto a1{1, "Arroz", 5.49, 20};
    imprimirProduto(a1);
    calcularValorEstoque(a1);
    removerEstoque(a1, 5);
    removerEstoque(a1, 50);
    adicionarEstoque(a1, 15);
    imprimirProduto(a1);

    return 0;
}