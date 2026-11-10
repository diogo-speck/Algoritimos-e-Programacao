#include <iostream>
#include <fstream>
#include "single_include\nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;

int main(){

    json animal =
        {
        {"codigo", 2},
        {"nome", "Bombom"},
        {"raca", "Shitzu"},
        {"peso", 5}
        };
        
    string jason = animal.dump(4);

        cout << jason << endl;


    fstream arquivo("animal.json", ios::out);

    arquivo << jason << endl;;


    return 0;
}