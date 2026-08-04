#include <iostream>
using namespace std;

int main() {
    
    float medida = 0;
    char tipo = 'a';
    bool continua = true;

    cout << "Conversão de unidades com switch case" << endl;
    while (continua){
        cout << "\nDigite uma medida no padrão centímetros ou polegadas (ex. 25.7 c / 13.9 p):" << endl;
        cin >> medida >> tipo;
        switch (tipo)
        {
        case 'c':
            medida = medida/2.54;
            cout << "Sua unidade de medida convertida de centímetros para polegadas é " << medida << "\"" << endl;
            break;

        case 'p':
            medida = medida*2.54;
            cout << "Sua unidade de medida convertida de polegadas para centímetros é " << medida << "cm" << endl;
            break;
        
        default:
            cout << "Unidade inválida" << endl;
            continua = false;
        }
    }
    
    return 0;
}