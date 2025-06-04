#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> brojevi = {1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42};
    int increment = 3;

    
    auto dodaj = [increment](int &broj) {
        broj += increment;
    };

    
    for (int &broj : brojevi) {
        dodaj(broj);
    }

    
    for (int i = 0; i < brojevi.size(); i++) {
        cout << brojevi[i];
        if (i != brojevi.size() - 1) {
            cout << ", ";
        }
    }

    return 0;
}
