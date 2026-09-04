#include <iostream>
using namespace std;

// protótipos das funções
void preencherTemperaturas(double (&temperaturas)[7]); // não constante
void exibirTemperaturas(const double (&temperaturas)[7]); 
double calcularMedia(const double (&temperaturas)[7]); 
double maiorTemperatura(const double (&temperaturas)[7]); 
double menorTemperatura(const double (&temperaturas)[7]); 
void corrigirTemperatura(double (&temperaturas)[7]); // não constante
int contarAcima(const double (&temperaturas)[7], int dia);

int main(){

    cout << "Controle e Análise de Temperaturas" << endl;

    double temperaturas[7] = {-300,-300,-300,-300,-300,-300,-300}; // 0: Sab - 1: Dom - 2: Seg ... 6: Sex
    preencherTemperaturas(temperaturas);
    exibirTemperaturas(temperaturas);
    cout << "Média das 7 temperaturas registradas: " << calcularMedia(temperaturas) << endl;
    cout << "Maior temperatura das 7 temperaturas registradas: " << maiorTemperatura(temperaturas) << endl;
    corrigirTemperatura(temperaturas);
    int dia = 0;
    cout << "\nQual o dia que você quer conferir os valores acima? " << endl;
    cin >> dia;
    cout << "Valores acima do dia "<< dia << ": " << contarAcima(temperaturas, dia) << endl;

    
    return 0;
}


// definições das funções
void preencherTemperaturas(double (&temperaturas)[7]){
    for (int i=0; i<7; i++){
        cout << "Qual foi a temperatura no ";
        switch (i)
        {
        case 0:
            cout << "sábado: ";
            break;
        case 1:
            cout << "domingo: ";
            break;
        case 2:
            cout << "segunda-feira: ";
            break;
        case 3:
            cout << "terça-feira: ";
            break;
        case 4:
            cout << "quarta-feira: ";
            break;
        case 5:
            cout << "quinta-feira: ";
            break;
        case 6:
            cout << "sexta-feira: ";
            break;
        default:
            break;
        }
        //entre -273 e 5596
        cin >> temperaturas[i];
        while (temperaturas[i]<-273||temperaturas[i]>5596){
            cout << "\nTemperatura inválida, insira outra: ";
            cin >> temperaturas[i];            
        }
    }
}

void exibirTemperaturas(const double (&temperaturas)[7]){
    for (int i=0; i<7; i++){
        cout << "Temperatura de ";
        switch (i)
        {
        case 0:
            cout << "sábado: ";
            break;
        case 1:
            cout << "domingo: ";
            break;
        case 2:
            cout << "segunda-feira: ";
            break;
        case 3:
            cout << "terça-feira: ";
            break;
        case 4:
            cout << "quarta-feira: ";
            break;
        case 5:
            cout << "quinta-feira: ";
            break;
        case 6:
            cout << "sexta-feira: ";
            break;
        default:
            break;
        }
        cout << temperaturas[i] << "ºC\n";
    }
}

double calcularMedia(const double (&temperaturas)[7]){
    double media = 0;
    for (int i=0; i<7; i++){
        media+=temperaturas[i];
    }
    return media/7;
}

double maiorTemperatura(const double (&temperaturas)[7]){
    double maior = temperaturas[0];
    for (int i=0; i<7; i++){
        if (temperaturas[i]>=maior){
            maior = temperaturas[i];
        }
    }
    return maior;
}

double menorTemperatura(const double (&temperaturas)[7]){
    double menor = temperaturas[0];
    for (int i=0; i<7; i++){
        if (temperaturas[i]<=menor){
            menor = temperaturas[i];
        }
    }
    return menor;
}

void corrigirTemperatura(double (&temperaturas)[7]){
    int dia = 0;
    cout << "Deseja corrigir qual dia? ";
    cin >> dia;
    for (int i=0; i<7; i++){
        if (dia == i){
            cout << "A temperatura era " << temperaturas[i] << "ºC, insira o novo valor: ";
            //entre -273 e 5596
            cin >> temperaturas[i];
            while (temperaturas[i]<-273||temperaturas[i]>5596){
                cout << "\nTemperatura inválida, insira outra: ";
                cin >> temperaturas[i];            
            }
            cout << "Valor alterado para " << temperaturas[i] << "ºC";
        }
    }
}

int contarAcima(const double (&temperaturas)[7], int dia){
    int contador = 0;
    for (int i=0; i<7; i++){
        if (dia == i){
            for(int j=0; j<7; j++){
                if (temperaturas[j]>temperaturas[i]){
                    contador++;
                }
            }
        }
    }
    return contador;
}