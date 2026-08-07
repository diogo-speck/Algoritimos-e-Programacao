#include <iostream>
#include <random>
using namespace std;

int gerarNumero();
int lerTentativa();
bool tentativaValida(int tentativa);
bool acertou(int numeroSorteado, int tentativa);
void informarDica(int numeroSorteado, int tentativa);
void exibirResultado(int quantidadeTentativas);

int main(){

    int n=0, numeroSorteado, tentativas=0;

    numeroSorteado = gerarNumero();
    //cout << numeroSorteado << endl;
    while(!acertou(numeroSorteado, n)){
        n = lerTentativa();
        if (!acertou(numeroSorteado, n)){
            informarDica(n, numeroSorteado);
        }
        tentativas++;
    }
    exibirResultado(tentativas);

    return 0;
}

int gerarNumero(){
    random_device rd;
    default_random_engine gerador(rd());
    uniform_int_distribution<int> distribuicao(1,100);
    int numeroSorteado = distribuicao(gerador);
    return numeroSorteado;
}

int lerTentativa(){
    int n;
    cout << "\nDigite o seu palpite: ";
    cin >> n;
    if (tentativaValida(n)!=0){
        return n;
    }
    else{
        cout << "\nTentativa inválida";
        return 0;
    }
}

bool tentativaValida(int tentativa){
    if (tentativa>0&&tentativa<101){
        return tentativa;
    }
    else{
        return 0;
    }
}

bool acertou(int numeroSorteado, int tentativa){
    if (numeroSorteado!=tentativa){
        return false;
    }else{
        return true;
    }
}

void informarDica(int numeroSorteado, int tentativa){
    if (numeroSorteado<tentativa){
        cout << "\nMais alto";
    }else{
        cout << "\nMais baixo";
    }
}

void exibirResultado(int quantidadeTentativas){
    cout << "Parabéns, você acertou em " << quantidadeTentativas << " tentativas";
}