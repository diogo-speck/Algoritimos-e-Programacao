#include <iostream>

int main (){
    /*
    Recebe um input do user de 13 dígitos e calcula o dígito verificador pra ver se é um código válido
    3 primeiros dígitos para o país ex. 789 ou 790 para o Brasil
    4-12 identificação da empresa/produto
    último dígito verificador utiliza a Separação e Pesos:
    Pegamos os 12 primeiros números e os multiplicamos da esquerda para a direita, 
    alternando os pesos entre 3 e 1
    ex. 78912345678() -> x 1,3,1,3,1..3 -> += total -> (10-(total%10))%10
    */

    char a='0',b='0',c='0',d='0',e ='0',f='0',g='0',h='0',i='0',j='0',k='0',l ='0',verifica = '0';
    int total=0, certo = 0;
    bool valido = 0;

    std::cout << "Digite o cod. de barra (somente os 13 primeiros): ";
    std::cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l >> verifica;
    
    total = int(a-48)*1+int(b-48)*3+int(c-48)*1+int(d-48)*3+int(e-48)*1+int(f-48)*3+int(g-48)*1+int(h-48)*3+int(i-48)*1+int(j-48)*3+int(k-48)*1+int(l-48)*3;
    certo = (10-(total%10))%10;
    valido = certo==(verifica-48);

    std::cout << "\n" << total << " " << verifica << " " << certo << "\n";

    std::cout << "\nCod. de barra correto (0 para falso e 1 para verdadeiro): " << valido << "\n";

    std::cout << "\nCod. de barra corrigido: " << a<<b<<c<<d<<e<<f<<g<<h<<i<<j<<k<<l<<certo << "\n";

    return 0;
}