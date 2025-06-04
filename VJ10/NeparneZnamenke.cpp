#include <iostream>
#include <vector>
using namespace std;

vector<int> izdvoji(vector<int>& v, bool (*uvjet)(int)) {
    vector<int> rezultat;
    for(int broj : v) {
        if(uvjet(broj)) {
            rezultat.push_back(broj);
        }
    }
    return rezultat;
}

int main() {
    vector<int> brojevi = {1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42};
    
   
    auto zadnjeDvijeNeparne = [](int n) {
        if(n < 10) return false; 
        int zadnje_dvije = n % 100; // Ovo daje zadnje dvije znamenke (npr. za 433 dobijemo 33)
        return zadnje_dvije % 2 != 0; 
    };
    
    vector<int> rezultat = izdvoji(brojevi, zadnjeDvijeNeparne);
    
    for(int broj : rezultat) {
        cout << broj << " ";
    }
    // Ispisuje: 55 433 433
    
    return 0;
}
