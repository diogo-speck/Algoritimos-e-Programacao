#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>

int main()
{
    /*
    Functions cannot return functions or arrays and are private by default
    Memória de malloc deve ser liberada com free(), 
    enquanto new usa o operador delete
    */
    
    int x, y=5, z=5;
    x = y==z;
    std::cout << (x) << std::endl;
    
    int k[] = {100,200,300,400,500,600,700};
    int *t=k+2;
    
    std::cout << (*t) << std::endl;
    t=t+3;
    *t = *t + *(t - 2);
    std::cout << (*t) << std::endl;
    
    for (int i=1; i<=1; i++){
        std::cout << i++ << i;
    }
    
    union numero{
        int a;
        float b;
    };
    
    union numero num;
    num.a = 67; // vira lixo de memória porque é sobrescrita
    num.b = 3.14f; // somente 1 valor, mas ocupa 1 único espaço
    std::cout << (num.a) << std::endl << (num.b)  << std::endl;

    FILE *F = fopen("estudandoC.cpp", "r");
    
    if (F == NULL){
        std::cout << ("Não foi aberto") << std::endl;
    }else{
        std::cout << ("Foi aberto") << std::endl;
    }

    if (feof(F)){
        std::cout << ("Terminou") << std::endl;
    }else{
        std::cout << ("Ainda não terminou") << std::endl;
    }
    fclose(F);
    
    // Alocação dinâmica com malloc invés de new
    char *nome;
    nome = (char*) malloc(sizeof(char)*100); // bytes char = 1, int = 4...
    std::cout << ("Digite seu nome: ") << std::endl;
    // invés de std::getline mas pode dar buffer overflow
    fgets(nome, 100, stdin);
    std::cout << ("Seu nome: ") << nome << std::endl;
    //nome++;
    //std::cout << nome << std::endl;
    
    
    return 0;
}