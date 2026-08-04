/*
Linguagem compilada != máquina virtual do Java

#include <stdio.h> é o import de biblioteca do java
não precisa declarar o scanner

int main() é padrão de toda aplicação em C++ (pode ser void main() mas é recomendado usar int main())
printf("Hello World"); // extensão de C
    
return 0; // sempre tem que retornar algo
*/
#include <iostream>
#include <locale>   // Biblioteca para configuração de locale
#include <clocale>  // Para usar setlocale()
#include <string> // para usar strings (string é minúscula em C++)
#include <cmath> // equivalente ao java.math
#include <cstdlib> // para usar rand() e srand()
#include <ctime> // para usar time() para o rand()
using namespace std; // para não precisar usar std::

int main() {
    // Configura o locale para o padrão do sistema (ex.: português do Brasil)
    std::setlocale(LC_ALL, "pt_BR.UTF-8"); // "" padrão do sistema
    std::cout<<"Oi user" << endl;
    
    int idade;
    string nome;
    cout << "Insira seu nome: ";
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
        if(v2==0){
            cout << "Não é possível dividir por zero" << endl;
        }
        else{
            cout << "Quociente dos seus valores: " << (v1/v2) << endl;
        }
        break;
    default:
            cout << "Escolha inválida" << endl;
        break;
    }
    }while(escolha!=5);

    cout << "\nAtividade 03 - Algarismo randômico" << endl;
    srand(time(0)); // Semente para gerar números diferentes a cada execução
    int numero_secreto = rand() % 100 + 1; // Gera um número entre 1 e 100
    cout << "Tente adivinhar o número secreto entre 1 e 100!" << endl;
    int tentativa;
    do {
        cout << "Digite sua tentativa: ";
        cin >> tentativa;
        if (tentativa < numero_secreto) {
            cout << "Mais alto! Tente novamente." << endl;
        } else if (tentativa > numero_secreto) {
            cout << "Mais baixo! Tente novamente." << endl;
        } else {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
        }
    } while (tentativa != numero_secreto);
    cout << "O número secreto era: " << numero_secreto << endl;

    cout << "\nAtividade 04 - Média de N valores" << endl;
    int n;
    cout << "Quantos números você quer inserir? ";
    cin >> n;
    double soma = 0, valor;
    for (int i = 0; i < n; i++) {
        cout << "Digite o " << (i + 1) << "º valor: ";
        cin >> valor;
        soma += valor;
    }
    double media = soma / n;
    cout << "A média dos valores inseridos é: " << media << endl;

    cout << "\nAtividade 05 - Invertendo vetor 7x1 aleatório" << endl;
    cout << "Vetor original:" << endl;
    const int tamanho = 7; // Tamanho invariável
    int vetor[tamanho]; // Declaração do vetor
    // Preenchendo o vetor com números aleatórios entre 1 e 100
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100 + 1;
        cout << vetor[i] << " ";
    }
    cout << "\nVetor invertido:" << endl;
    // Invertendo o vetor
    for (int i = 0; i < tamanho/2; i++) {
        int temp = vetor[i]; // Armazena o valor atual para troca
        vetor[i] = vetor[tamanho - 1 - i]; // Atribui o valor do elemento oposto
        vetor[tamanho - 1 - i] = temp; // Completa a troca
    }
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }

    cout << "\n\nAtividade 06 - Matriz Identidade de ordem n" << endl;
    int ordem = 0;
    cout << "Digite a ordem da matriz identidade: ";
    cin >> ordem;
    // Criando a matriz identidade
    int matriz[ordem][ordem]; // Declaração da matriz
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            if (i == j) {
                matriz[i][j] = 1; // Elementos da diagonal principal são 1
            } else {
                matriz[i][j] = 0; // Demais elementos são 0
            }
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
cin e cout são equivalentes a leitura do scanner sc.next() e o Syop (ambos fazem parte da biblioteca <iostream>)

idade_minima = (idade_mais_velha / 2) + 7
idade_maxima = 2 * ((idade_mais_velha / 2) + 7)
idade_maxima_alt = 2 * ((2 * idade_mais_velha / 2) + 7)

*/