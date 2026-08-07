#include <iostream>
#include <typeinfo>
using namespace std;

//int valor = 10;

string retornaTexto(string texto){

    return texto;
}

void imprimirErro(string mensagem){
    cout << "\nErro: " << mensagem << endl;
}

bool confere(bool confirma);

int main(){

    string frase;
    bool verdadeiro = true;
    bool falso = false;
    //string valor = "1"; Printaria essa variável do escopo mais interno

    cout << "Digite um texto: ";
    cin >> frase;
    cout << "\nSeu texto: " << endl;
    cout << retornaTexto(frase);
    imprimirErro("Não tem erro");
    confere(falso);
    cout << confere(verdadeiro) << endl;

    return 0;
}

// Boas práticas definir depois do main
bool confere(bool confirma){
    if (confirma){
        return true;
    }else{
        return false;
    }
}