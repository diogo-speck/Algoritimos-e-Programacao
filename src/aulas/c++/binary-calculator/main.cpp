#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string decToBinary(int n);
int binaryToDec(string num);

int main(){
    cout << "Enter the first number (must be 8 digits or less)" << endl;
    string num1 = "";
    cin >> num1;
    cout << "Enter the second number (must be 8 digits or less)" << endl;
    string num2 = "";
    cin >> num2;
    cout << "what do u wanna do now lol" << endl << "1. sum" << endl << "2. subtract" << endl << "3. multiply" << endl << "4. divide" << endl << "5. quit" << endl;
    int choice = 0;
    cin >> choice;
    if(choice == 1) {
        int resultado = binaryToDec(num1) + binaryToDec(num2);
        cout << decToBinary(resultado) << endl;
    } else if(choice == 2) {
        int resultado = binaryToDec(num1) - binaryToDec(num2);
        cout << decToBinary(resultado) << endl;
    } else if(choice == 3) {
        int resultado = binaryToDec(num1) * binaryToDec(num2);
        cout << decToBinary(resultado) << endl;
    } else if (choice == 4) {
        int resultado = binaryToDec(num1) / binaryToDec(num2);
        cout << decToBinary(resultado) << endl;
    } else if (choice == 5) {
        cout << "bye" << endl;
    }
}

string decToBinary(int n) {
    string bin = " ";
    while (n > 0) {
        int bit = n%2; // "To convert a decimal number to binary, repeatedly divide it by 2 and record the remainders. Reading these remainders in reverse gives the binary representation."
        bin.push_back('0' + bit);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int binaryToDec(string num) {
    int dec_value = 0;
    int base = 1;

    // bin to dec
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
