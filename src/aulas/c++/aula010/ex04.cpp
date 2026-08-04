#include <iostream>
#include <iomanip> // Necessário para std::setw e std::setfill
using namespace std;

int main() {

    cout << "Quadrados dos números com for" << endl;
    
    for (int c = 0; c <101; c++){
        cout << setw(3) << setfill(' ') << c << " - " << setw(5) << setfill(' ') << c*c << endl;
    }

    return 0;
}