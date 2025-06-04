#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Proizvod {
private:
    string naziv;
    int kolicina;
    double cijena;
public:
    Proizvod(string n, int k, double c) : naziv(n), kolicina(k), cijena(c) {}
    
    string getNaziv() const { return naziv; }
    int getKolicina() const { return kolicina; }
    double getCijena() const { return cijena; }
};

vector<Proizvod*> nadji(vector<Proizvod>& v, bool (*uvjet)(Proizvod*)) {
    vector<Proizvod*> rezultat;
    for (auto& p : v) {
        if (uvjet(&p)) {
            rezultat.push_back(&p);
        }
    }
    return rezultat;
}

int main() {
    vector<Proizvod> v = { 
        Proizvod("Mobitel", 22, 1760.5),
        Proizvod("TV", 24, 2017.0),
        Proizvod("Tablet", 85, 3155.65),
        Proizvod("Laptop", 7, 9200) 
    };

   
    auto uvjet = [](Proizvod* s) { return s->getCijena() > 1000; };
    
    vector<Proizvod*> r = nadji(v, uvjet);

  
    for (Proizvod* p : r) {
        cout << p->getNaziv() << " " << p->getKolicina() << " " << p->getCijena() << endl;
    }

    return 0;
}
