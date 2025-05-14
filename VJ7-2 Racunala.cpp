#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

class Racunalo {
protected:
    string os;
public:
    Racunalo(string operativniSistem) : os(operativniSistem) {}
    virtual string getOS() const { 
        return os; 
    }
    virtual ~Racunalo() {}
};


class Tablet : public Racunalo {
public:
    Tablet(string operativniSistem) : Racunalo(operativniSistem) {}
};


class Laptop : public Racunalo {
public:
    Laptop(string operativniSistem) : Racunalo(operativniSistem) {}
};


void AnalizaUcionice(const vector<Racunalo*>& ucionica, int* brTableta, int* brLaptopa, int* brAndroida, int* brWindowsa, int* brLinuxa) {
    *brTableta = 0;
    *brLaptopa = 0;
    *brAndroida = 0;
    *brWindowsa = 0;
    *brLinuxa = 0;

    for (auto& racunalo : ucionica) {
        if (dynamic_cast<Tablet*>(racunalo)) {
            (*brTableta)++;
        }
        else if (dynamic_cast<Laptop*>(racunalo)) {
            (*brLaptopa)++;
        }

        string os = racunalo->getOS();
        if (os == "Android") {
            (*brAndroida)++;
        }
        else if (os == "Windows") {
            (*brWindowsa)++;
        }
        else if (os == "Linux") {
            (*brLinuxa)++;
        }
    }
}


int main() {
    int brTableta, brLaptopa;
    int brAndroida, brWindowsa, brLinuxa;

    Tablet Acer("Android"), Prestigio("Windows");
    Laptop Dell("Linux"), IBM("Windows"), Toshiba("Windows");

    vector<Racunalo*> Ucionica1 = { &Acer, &Prestigio, &Dell, &IBM, &Toshiba };
    AnalizaUcionice(Ucionica1, &brTableta, &brLaptopa, &brAndroida, &brWindowsa, &brLinuxa);

    
    cout << "U ucionici se nalazi " << Ucionica1.size() << " racunala" << endl;
    cout << "Broj tablet racunala: " << brTableta << endl;
    cout << "Broj laptop racunala: " << brLaptopa << endl;
    cout << "Android OS: " << brAndroida << endl;
    cout << "Windows OS: " << brWindowsa << endl;
    cout << "Linux OS: " << brLinuxa << endl;

    return 0;
}
