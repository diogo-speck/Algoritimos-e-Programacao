#pragma once
#include <iostream>
#include <string>

struct Produto {
    int codigo;
    std::string nome;
    double preco;
    int quantidade;
};

void imprimirProduto(const Produto& produto);
double calcularValorEstoque(const Produto& produto);
void adicionarEstoque(Produto& produto, int qtd);
bool removerEstoque(Produto& produto, int qtd);


void imprimirProduto(const Produto& produto){
    std::cout << "(" << produto.codigo << ") - " << produto.nome << ": R$" << produto.preco << " (" << produto.quantidade << " em estoque)" << std::endl;
}

double calcularValorEstoque(const Produto& produto){
    return produto.preco*produto.quantidade;
}

void adicionarEstoque(Produto& produto, int qtd){
    if (qtd > 0){
        produto.quantidade+=qtd;
        std::cout << qtd << "x Produtos adicionados" << std::endl;
    }else{
        std::cout << "Quantidade inválida" << std::endl;
    }
}

bool removerEstoque(Produto& produto, int qtd){
    if (produto.quantidade-qtd>=0){
        produto.quantidade-=qtd;
        std::cout << qtd << "x Produtos removidos" << std::endl;
        return true;
    }else{
        std::cout << "Quantidade inválida ou estoque insuficiente" << std::endl;
        return false;
    }
}