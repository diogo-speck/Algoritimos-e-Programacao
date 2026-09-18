#include <iostream>
#include <array>
using namespace std;

int main(){

    cout << "MATRIZ COM STD::ARRAY" << endl;

    array<array<int, 3>, 3> matriz{};

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << "Valor [" << i+1 << "][" << j+1 << "]: ";
            cin >> matriz[i][j];
        }
    }

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[0].size(); j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}