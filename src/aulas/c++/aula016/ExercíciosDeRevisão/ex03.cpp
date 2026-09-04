#include <iostream>
using namespace std;

// protótipos das funções
void cadastrarLivro(Livro (&estante)[10], string titulo, string autor, int codigo, int ano);
bool removerLivro(Livro (&estante)[10], int codigo);
void exibirLivro(const Livro (&estante)[10]); 
void exibirLivros(const Livro (&estante)[10], int codigo); 
int buscarLivro(const Livro (&estante)[10], int codigo);
bool emprestarLivro(Livro (&estante)[10], int codigo); 
bool devolverLivro(Livro (&estante)[10], int codigo); 
int totalDisponiveis(const Livro (&estante)[10]);


int main(){

    cout << "Controle de Livros de uma Biblioteca" << endl;

    Livro estante[10];
    int escolha = 1;
    string titulo, autor;
    int ano, codigo;
    
    while (escolha!=0){
        cout << "1 - Cadastrar livro " << endl
            << "2 - Remover livro " << endl
            << "3 - Exibir livros " << endl
            << "4 - Exibir livro por código " << endl
            << "5 - Emprestar livro " << endl
            << "6 - Devolver livro " << endl
            << "7 - Total de livros disponíveis " << endl
            << "0 - Sair" << endl
            << "Escolha: ";
        cin >> escolha;
        switch (escolha)
        {
        case 1:
            cout << "Insira o título do livro: ";
            cin >> titulo;
            cout << "Insira o autor do livro: ";
            cin >> autor;
            cout << "Insira o código do livro: ";
            cin >> codigo;
            cout << "Insira o ano de publicação do livro: ";
            cin >> ano;
            cadastrarLivro(estante, titulo, autor, codigo, ano);
            break;
        case 2:
            codigo = buscarLivro(estante, codigo);
            removerLivro(estante, codigo);
            break;
        case 3:
            exibirLivro(estante);
            break;
        case 4:
            codigo = buscarLivro(estante, codigo);
            removerLivro(estante, codigo);
            break;
        case 5:
            codigo = buscarLivro(estante, codigo);
            if (emprestarLivro(estante, codigo)){
                cout << "Livro emprestado" << endl;
            }else{
                cout << "Não foi possível emprestar o livro" << endl;
            }
            break;
        case 6:
            codigo = buscarLivro(estante, codigo);
            if (devolverLivro(estante, codigo)){
                cout << "Livro devolvido" << endl;
            }else{
                cout << "Não foi possível devolver o livro" << endl;
            }
            break;
        case 7:
            cout << "Quantidade de livros cadastrados: " << totalDisponiveis(estante) << endl;
            break;
        
        default:
            cout << "Opção inválida" << endl;
        }
    }
    
    

    return 0;
}


// definições das funções
struct Livro { 
    int codigo = -1; // por padrão livre
    string titulo; 
    string autor; 
    int ano; 
    bool disponivel = true; // por padrão livre
};

void cadastrarLivro(Livro (&estante)[10], string titulo, string autor, int codigo, int ano){
    for (int i=0; i<10; i++){
        if (estante[i].codigo == -1){
            estante[i].codigo = codigo;
            estante[i].titulo = titulo;
            estante[i].autor = autor;
            estante[i].ano = ano;
            cout << "O livro '" << estante[i].titulo << "' foi cadastrado com código " << estante[i].codigo;
        }
    }
} 

bool removerLivro(Livro (&estante)[10], int codigo){
    /*
    A remoção será lógica: localize o livro pelo código e altere seu codigo para -1, 
    liberando novamente a posição.
    */
   for (int i=0; i<10; i++){
        if (estante[i].codigo == codigo && codigo != -1){
            estante[i].codigo = -1;
            cout << "O livro '" << estante[i].titulo << "' foi removido" << endl;
            return true;
        }
    }
    cout << "Não foi possível remover o livro" << endl;
    return false;
}

void exibirLivro(const Livro (&estante)[10]){
    // A exibição deverá ignorar posições com codigo == -1
    for (int i=0; i<10; i++){
        if (estante[i].codigo != -1){
            cout << "(" << estante[i].codigo << ") '" << estante[i].titulo << "' - " << estante[i].autor << " - " << estante[i].ano << "' - Disonível: " << estante[i].disponivel << endl;
        }
    }
}

void exibirLivros(const Livro (&estante)[10], int codigo){
    /*
    A consulta por código deverá apresentar os dados do livro ou informar que ele 
    não foi encontrado.
    */
   bool achou = false;
   for (int i=0; i<10; i++){
        if (estante[i].codigo == codigo){
            cout << "(" << estante[i].codigo << ") '" << estante[i].titulo << "' - " << estante[i].autor << " - " << estante[i].ano << "' - Disonível: " << estante[i].disponivel << endl;
            achou = true;
        }
    }
    if (!achou){
        cout << "Não foi possível encontrar o livro" << endl;
    }
} 

int buscarLivro(const Livro (&estante)[10], int codigo){
    /*
    A função de busca deverá receber um código e retornar o índice do livro na estante 
    ou -1 caso ele não seja encontrado.
    */
    cout << "Insira o código do livro: ";
    cin >> codigo;
   for (int i=0; i<10; i++){
        if (estante[i].codigo == codigo && codigo != -1){
            return i;
        }
    }
    return -1;
}

bool emprestarLivro(Livro (&estante)[10], int codigo){
    /*
    Um livro somente poderá ser emprestado se estiver cadastrado e disponível. 
    Após o empréstimo, disponivel = false
    */
   for (int i=0; i<10; i++){
        if (estante[i].codigo == codigo && estante[i].disponivel){
            estante[i].disponivel = false;
            return true;
        }
    }
    return false;
}

bool devolverLivro(Livro (&estante)[10], int codigo){
    /*
    Um livro somente poderá ser devolvido se estiver cadastrado e emprestado. 
    Após a devolução, disponivel = true
    */
   for (int i=0; i<10; i++){
        if (estante[i].codigo == codigo && estante[i].disponivel){
            estante[i].disponivel = true;
            return true;
        }
    }
    return false;
}

int totalDisponiveis(const Livro (&estante)[10]){
    /*
    O total de livros disponíveis deverá considerar somente livros cadastrados 
    (codigo != -1) com disponivel == true.
    */
   int total = 0;
   for (int i=0; i<10; i++){
        if (estante[i].codigo != -1){
            total++;
        }
    }
    return total;
}