#include <iostream>
using namespace std;

int main() {
    
    float medida = 0;
    char tipo = ' ';

    cout << "Conversão de unidades com if-else" << endl;
    cout << "Digite uma medida no padrão centímetros ou polegadas (ex. 25.7 c / 13.9 p):" << endl;
    cin >> medida >> tipo;
    if (tipo == 'c'){
        medida = medida/2.54;
        cout << "Sua unidade de medida convertida de centímetros para polegadas é " << medida << "\"" << endl;
    }else if (tipo == 'p'){
        medida = medida*2.54;
        cout << "Sua unidade de medida convertida de polegadas para centímetros é " << medida << "cm" << endl;
    }else{
        cout << "Unidade inválida";
    }
    

    // 1 polegada = 2,54 centímetros

    
    return 0;
}