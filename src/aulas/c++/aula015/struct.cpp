#include <iostream>
using namespace std;
/*
Comentários:
O std::vector é um container dinâmico da STL que elimina a limitação de tamanho fixo dos arrays.
*/

struct Produto // Public
{
    int codigo = 0;
    string nome;
    double preco = 0.0;
    int estoque = 0;
};

class Itens // Private
{
    string nome;
    int codigo = 0;
    double preco = 0.0;
    int estoque = 0;
    
    public:
    Itens(int codigo, string nome, double preco, int estoque):
        codigo(codigo),
            nome(nome),
            preco(preco),
            estoque(estoque)
        {
        }
        void imprimir() {
            cout << nome << " - R$ " << preco << " (id=" << codigo << ", "<< estoque <<" produtos restantes)" << endl;
        }
};


void imprimirProduto(const Produto&produto);

void imprimirProduto(const Itens&sacola);


int main(){

    Produto teclado{0,"Teclado",150.9,10};

    imprimirProduto(teclado);
    
    Itens sacola[2]{
        {1, "Mouse", 80.0, 10},
        {2, "Monitor", 900.0, 3}
    };

    for(Itens sacola : sacola){
        sacola.imprimir();
    }

    int vetor[2][3] = {{1, 2, 3}, {1, 2, 3}};
    cout << sizeof(vetor)/sizeof(vetor[0]) << endl;
    
    return 0;
}


void imprimirProduto(const Produto&produto){
    cout << produto.nome
    << " - R$ "
    << produto.preco
    << endl;
}