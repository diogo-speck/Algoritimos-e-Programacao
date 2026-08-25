#pragma once
#include <iostream>
#include <string>

struct Produto {
    int codigo;
    std::string nome;
    double preco;
};


void imprimirProduto(const Produto& p);
void imprimirProdutos(const Produto produtos[],int tamanho);
double calcularMediaPrecos(const Produto produtos[],int tamanho);
int buscarProduto(const Produto produtos[],int tamanho, int codigo);


void imprimirProduto(const Produto& p){
    std::cout << "(" << p.codigo << ") - " << p.nome << ": R$" << p.preco << std::endl;
}

void imprimirProdutos(const Produto produtos[],int tamanho){
    for(int i = 0; i<tamanho; i++){
        std::cout << "(" << produtos[i].codigo << ") - " << produtos[i].nome << ": R$" << produtos[i].preco << std::endl;
    }
}

double calcularMediaPrecos(const Produto produtos[],int tamanho){
    double media = 0;
    for(int i = 0; i<tamanho; i++){
        media=+ produtos[i].preco;
    }
    return media;
}

int buscarProduto(const Produto produtos[],int tamanho, int codigo){
    int i =0;
    for(int i = 0; i<tamanho; i++){
        if (codigo == produtos[i].codigo){
            std::cout << "Produto encontrado: " << "(" << produtos[i].codigo << ") - " << produtos[i].nome << ": R$" << produtos[i].preco << std::endl;
            return i;
        }
    }
    std::cout << "Produto NÃO encontrado";
    return -1;
}