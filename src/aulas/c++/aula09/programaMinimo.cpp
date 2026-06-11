/*
Linguagem compilada != máquina virtual do Java

#include <stdio.h> // import de biblioteca do java
// não precisa declarar o scanner
int main()
{
    printf("Hello World"); // extensão de C
    // string é minúscula
    

    return 0; // sempre tem que retornar algo
}
*/
#include <iostream> 
#include <locale>   // Biblioteca para configuração de locale
#include <clocale>  // Para usar setlocale()
#include <string> // para usar strings
#include <cmath> // equivalente ao java.math
using namespace std; // para não precisar usar std::

int main() {
    // Configura o locale para o padrão do sistema (ex.: português do Brasil)
    std::setlocale(LC_ALL, ""); // poderia ser std::setlocale(LC_ALL, "pt_BR.UTF-8");
    cout << "Hello World" << endl; // poderia usar std::cout<<"Hello World";
    
    int idade;
    string nome;
    cout << "Insira seu nome: " << endl;
    getline(cin, nome);
    cout << "Seu nome: " << nome << endl;
    cout << "Insira sua idade: ";
    cin >> idade;
    cout << "Sua idade: " << idade << endl;
    cout << "Sua idade ao quadrado: " << pow(idade,2) << endl;
    cout << "Tu deve ter existido por pelo menos " << int(idade/4) << " copas" << endl;
    if (idade>=18){
        cout << "Tu vive maior de idade" << endl;
    }
    else{
        cout << "Tu jamais tornou-se maior de idade" << endl;
    }

    double altura, peso, imc;
    cout << "\nAtividade 01 - IMC" << endl;
    cout << "Insira sua altura em metros (ex. 1.67): ";
    cin >> altura;
    cout << "Insira seu peso em KG (ex. 67): ";
    cin >> peso;
    imc = peso/pow(altura,2);
    cout << "Seu IMC: " << imc << " kg/m²"<< endl;
    if (imc<16){
        cout << "Magreza grave";
    }
    else if(imc>=16&&imc<17){
        cout << "Magreza moderada";
    }
    else if(imc>=17&&imc<18.5){
        cout << "Magreza leve";
    }
    else if(imc>=18.5&&imc<25){
        cout << "Sadio";
    }
    else if(imc>=25&&imc<30){
        cout << "Sobrepeso";
    }
    else if(imc>=30&&imc<35){
        cout << "Obesidade grau I";
    }
    else if(imc>=35&&imc<40){
        cout << "Obesidade grau II";
    }
    else if(imc>=40){
        cout << "Obesidade grau III";
    }
    else{
        cout << "Tu informou os dados de maneira errada";
    }
    
    int escolha;
    double v1,v2;
    
    cout << "\n\nAtividade 02 - Calculadora" << endl;
    do{
    cout << "\n=======MENU=======" << endl;
    cout << "1 - Soma" << endl;
    cout << "2 - Subtrair" << endl;
    cout << "3 - Multiplicar" << endl;
    cout << "4 - Dividir" << endl;
    cout << "5 - Sair" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    switch (escolha)
    {
    case 1:
        cout << "Digite o 1º valor: ";
        cin >> v1;
        cout << "Digite o 2º valor: ";
        cin >> v2;
        cout << "Resultado da soma dos seus valores: " << v1+v2 << endl;
        break;
    case 2:
        cout << "Digite o 1º valor: ";
        cin >> v1;
        cout << "Digite o 2º valor: ";
        cin >> v2;
        cout << "Resto dos seus valores: " << v1-v2 << endl;
        break;
    case 3:
        cout << "Digite o 1º valor: ";
        cin >> v1;
        cout << "Digite o 2º valor: ";
        cin >> v2;
        cout << "Produto dos seus valores: " << v1*v2 << endl;
        break;
    case 4:
        cout << "Digite o 1º valor: ";
        cin >> v1;
        cout << "Digite o 2º valor: ";
        cin >> v2;
        if(v2=0){
            cout << "Não é possível dividir por zero";
        }
        else{
            cout << "Quociente dos seus valores: " << v1/v2 << endl;
        }
        break;
    default:
        break;
    }
    }while(escolha!=5);

    return 0;
}

/*
cin e cout são equivalentes a leitura do scanner sc.next() e o Syop (ambos fazem parte da biblioteca <iostream>)

idade_minima = (idade_mais_velha / 2) + 7
idade_maxima = 2 * ((idade_mais_velha / 2) + 7)
idade_maxima_alt = 2 * ((2 * idade_mais_velha / 2) + 7)

*/