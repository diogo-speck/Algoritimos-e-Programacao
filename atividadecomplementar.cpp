/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    bool acertou = false;
    bool tem = false;
    int vidas = 6;
    int conferir = 0;
    char palavra [5] = {'T','E','R','M','O'};
    char escondidas [5] = {'_','_','_','_','_'};
    char tentativa;
    
    string forca[7];
    forca[6] =
    " +---+\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "=========\n";

    forca[5] =
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "     |\n"
    "     |\n"
    "     |\n"
    "=========\n";

    forca[4] =
    " +---+\n"
    " |   |\n"
    " O   |\n"
    " |   |\n"
    "     |\n"
    "     |\n"
    "=========\n";

    forca[3] =
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|   |\n"
    "     |\n"
    "     |\n"
    "=========\n";

    forca[2] =
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "     |\n"
    "     |\n"
    "=========\n";

    forca[1] =
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/    |\n"
    "     |\n"
    "=========\n";

    forca[0] =
    " +---+\n"
    " |   |\n"
    " O   |\n"
    "/|\\  |\n"
    "/ \\  |\n"
    "     |\n"
    "=========\n";
    
    cout<<"Bem vindo ao jogo da Forca";
    while(!acertou&&vidas>0){
        tem = false;
        cout<<"\nDigite uma letra: "<<endl;
        cin>>tentativa;
        for (int i=0;i<5;i++){
            if (tentativa == palavra[i]){
                escondidas[i] = palavra[i];
                tem = true;
                cout<<"Você acertou a letra na posição "<<i+1<<endl;
            }
        }
        if (!tem){
            vidas --;
            cout<<"Você NÃO acertou a letra"<<endl;
        }
        
        for (int i=0;i<5;i++){
            if (escondidas[i] == '_'){
                acertou = false;
            }
            else{
                acertou = true;
            }
        }
        for(int i=0;i<5;i++){
            cout<<escondidas[i]<<" ";
        }
        
        cout<<"\nVocê tem "<<vidas<<" vidas\n"<<endl;
        cout<<forca[vidas]<<endl;
    }
    cout<<"\nA palavra era ";
    for(int i=0;i<5;i++){
            cout<<palavra[i];
        }
    if (acertou){
        cout<<"\nVocê GANHOU";
    }
    else{
        cout<<"\nVocê PERDEU";
    }
    
    return 0;
}