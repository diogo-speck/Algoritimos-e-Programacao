#include <iostream>
#include <string>
using namespace std;


struct Livro { 
    int codigo = -1; // por padrão livre
    string titulo; 
    string autor; 
    int ano; 
    bool disponivel;
};

// protótipos das funções
void cadastrarLivro(Livro (&estante)[10], string titulo, string autor, int codigo, int ano);
bool removerLivro(Livro (&estante)[10], int indice);
void exibirLivros(const Livro (&estante)[10]); 
void exibirLivro(const Livro (&estante)[10], int indice); 
int buscarLivro(const Livro (&estante)[10]);
bool emprestarLivro(Livro (&estante)[10], int indice); 
bool devolverLivro(Livro (&estante)[10], int indice); 
int totalDisponiveis(const Livro (&estante)[10]);


int main(){

    cout << "Controle de Livros de uma Biblioteca" << endl;

    Livro estante[10];
    int escolha = 1;
    string titulo, autor;
    int ano, codigo, indice;
    
    while (escolha!=0){
        cout << "\n1 - Cadastrar livro " << endl
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
            cin.ignore(); // limpa o buffer
            getline(cin, titulo);
            cout << "Insira o autor do livro: ";
            getline(cin, autor);
            cout << "Insira o código do livro: ";
            cin >> codigo;
            cout << "Insira o ano de publicação do livro: ";
            cin >> ano;
            cadastrarLivro(estante, titulo, autor, codigo, ano);
            break;
        case 2:
            indice = buscarLivro(estante);
            removerLivro(estante, indice);
            break;
        case 3:
            exibirLivros(estante);
            break;
        case 4:
            indice = buscarLivro(estante);
            exibirLivro(estante, indice);
            break;
        case 5:
            indice = buscarLivro(estante);
            if (emprestarLivro(estante, indice)){
                cout << "Livro emprestado" << endl;
            }else{
                cout << "Não foi possível emprestar o livro" << endl;
            }
            break;
        case 6:
            indice = buscarLivro(estante);
            if (devolverLivro(estante, indice)){
                cout << "Livro devolvido" << endl;
            }else{
                cout << "Não foi possível devolver o livro" << endl;
            }
            break;
        case 7:
            cout << "Quantidade de livros disponíveis: " << totalDisponiveis(estante) << endl;
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        
        default:
            cout << "Opção inválida" << endl;
        }
    }
    

    return 0;
}


// definições das funções
void cadastrarLivro(Livro (&estante)[10], string titulo, string autor, int codigo, int ano){
    bool achou = false;
    for (int i=0; i<10; i++){
        if (estante[i].codigo == -1){
            estante[i].codigo = codigo;
            estante[i].titulo = titulo;
            estante[i].autor = autor;
            estante[i].ano = ano;
            estante[i].disponivel = true;
            cout << "\nO livro '" << estante[i].titulo << "' foi cadastrado com código " << estante[i].codigo;
            achou = true;
            break;
        }
    }
    if (!achou){
        cout << "Estante cheia (10/10), remova algum livro para adicionar mais livros" << endl;
    }
} 

bool removerLivro(Livro (&estante)[10], int indice){
    /*
    A remoção será lógica: localize o livro pelo código e altere seu codigo para -1, 
    liberando novamente a posição.
    */
    if (indice != -1 && estante[indice].codigo != -1){
        estante[indice].codigo = -1;
        cout << "O livro '" << estante[indice].titulo << "' foi removido" << endl;
        estante[indice].titulo = "";
        estante[indice].autor = "";
        estante[indice].ano = 0;
        estante[indice].disponivel = true;
        return true;
    }
    cout << "Não foi possível remover o livro" << endl;
    return false;
}

void exibirLivros(const Livro (&estante)[10]){
    // A exibição deverá ignorar posições com codigo == -1
    for (int i=0; i<10; i++){
        if (estante[i].codigo != -1){
            cout << "(" << estante[i].codigo << ") '" << estante[i].titulo << "' - " << estante[i].autor << " - " << estante[i].ano << "' - Disponível: " << estante[i].disponivel << endl;
        }
    }
}

void exibirLivro(const Livro (&estante)[10], int indice){
    /*
    A consulta por código deverá apresentar os dados do livro ou informar que ele 
    não foi encontrado.
    */
    if (indice != -1 && estante[indice].codigo != -1){
        cout << "(" << estante[indice].codigo << ") '" << estante[indice].titulo << "' - " << estante[indice].autor << " - " << estante[indice].ano << "' - Disponível: " << estante[indice].disponivel << endl;
    }else{
        cout << "Não foi possível encontrar o livro" << endl;
    }
} 

int buscarLivro(const Livro (&estante)[10]){
    /*
    A função de busca deverá receber um código e retornar o índice do livro na estante 
    ou -1 caso ele não seja encontrado.
    */
    int codigo;
    cout << "Insira o código do livro: ";
    cin >> codigo;
   for (int i=0; i<10; i++){
        if (estante[i].codigo == codigo && estante[i].codigo != -1){
            return i;
        }
    }
    return -1;
}

bool emprestarLivro(Livro (&estante)[10], int indice){
    /*
    Um livro somente poderá ser emprestado se estiver cadastrado e disponível. 
    Após o empréstimo, disponivel = false
    */
    if (indice != -1 && estante[indice].disponivel && estante[indice].codigo != -1){
        estante[indice].disponivel = false;
        return true;
    }
    return false;
}

bool devolverLivro(Livro (&estante)[10], int indice){
    /*
    Um livro somente poderá ser devolvido se estiver cadastrado e emprestado. 
    Após a devolução, disponivel = true
    */
    if (indice != -1 && !estante[indice].disponivel && estante[indice].codigo != -1){
        estante[indice].disponivel = true;
        return true;
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
        if (estante[i].codigo != -1 && estante[i].disponivel){
            total++;
        }
    }
    return total;
}