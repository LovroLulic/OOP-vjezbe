#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Red {
private:
    vector<T> elementi;
    int BrojElementa;

public:
    Red() : BrojElementa(0) {}

    
    void Dodaj(T noviElement) {
        elementi.push_back(noviElement);
        BrojElementa++;
    }

    
    void Brisi() {
        if (BrojElementa > 0) {
            elementi.erase(elementi.end()-1);  
            BrojElementa--;
        }
        else {
            cout << "Red je prazan!" << endl;
        }
    }

    int DajBrojElementa() const {
        return BrojElementa;
    }

   
    void Ispisi() const {
        cout << "Red:";
        for (const auto& el : elementi) {
            cout << el << " ";
        }
    }
};

int main() {
    Red<int> red;  

    red.Dodaj("2");
    red.Dodaj("4");
    red.Dodaj("6");

    red.Ispisi();
    cout << "Broj elemenata: " << red.DajBrojElementa() << endl;

    red.Brisi(); 
    red.Ispisi();
    cout << "Sada ima: " << red.DajBrojElementa() << " elementa" << endl;

    return 0;
}
