#include <iostream> 
#include <string>
using namespace std;

class Zrno {
public:
    string boja;
    float promjer;

    Zrno() {}
};

class Pijesak {
public:
    int kolicina;
    Zrno* zrno;

    
    Pijesak(int _kolicina) : kolicina(_kolicina) {
        zrno = new Zrno[kolicina];
    }

    
    ~Pijesak() {
        delete[] zrno;
    }

    // Kopirni konstruktor
    Pijesak(const Pijesak& A) : kolicina(A.kolicina) {
        zrno = new Zrno[kolicina];
        for (int i = 0; i < kolicina; i++) {
            zrno[i] = A.zrno[i];
        }
    }

    // Kopirni operator pridruživanja
    Pijesak& operator=(const Pijesak& A) {
        if (this != &A) {
            delete[] zrno; // oèisti staru memoriju

            kolicina = A.kolicina;
            zrno = new Zrno[kolicina];
            for (int i = 0; i < kolicina; i++) {
                zrno[i] = A.zrno[i];
            }
        }
        return *this;
    }

    // Konstruktor prijenosa
    Pijesak(Pijesak&& privremeni) {
        kolicina = privremeni.kolicina;
        zrno = privremeni.zrno;

        privremeni.zrno = NULL;
        privremeni.kolicina = NULL;
    }

    // Operator pridruživanja (prijenos)
    Pijesak& operator=(Pijesak&& privremeni) {
        if (this != &privremeni) {
            delete[] zrno;

            kolicina = privremeni.kolicina;
            zrno = privremeni.zrno;

            privremeni.zrno = NULL;
            privremeni.kolicina = NULL;
        }
        return *this;
    }
};

int main() {
    Pijesak igraliste(1000000);
    cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

    // Kopirni konstruktor
    Pijesak kopija = igraliste;
    cout << "Kopija ima " << kopija.kolicina << " zrna pijeska.\n";

    // Operator pridruživanja 
    Pijesak drugi(1);
    drugi = igraliste;
    cout << "Drugi ima " << drugi.kolicina << " zrna pijeska.\n";

    // Konstruktor prijenosa
    Pijesak premjesteni = move(igraliste);
    cout << "Premjesteni ima " << premjesteni.kolicina << " zrna pijeska.\n";

    // Operator pridruživanja prijenos
    Pijesak treci(1);
    treci = move(kopija);
    cout << "Treci ima " << treci.kolicina << " zrna pijeska.\n";

    return 0;
}
