#include "cadastro.hpp"
using namespace std;

int main(){

    Aluno a1 {"Diogo", 438437, 8.7, 7.9};
    imprimirAluno(a1);
    cout << "A média é: " << calcularMedia(a1) << endl;


    return 0;
}