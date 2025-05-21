#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

class Osoba {
protected:
    string ime, prezime;
    double osnovica;
public:
    Osoba(string i, string p, double o) : ime(i), prezime(p), osnovica(o) {}
    virtual double izracunPlace() const = 0;
    virtual void ispis() const = 0;
    virtual ~Osoba() {}
};

class Igrac : public Osoba {
private:
    int golovi, asistencije;
public:
    Igrac(string i, string p, double o) : Osoba(i, p, o), golovi(0), asistencije(0) {}
    
    void dodajGolove(int brojGolova) { 
        golovi += brojGolova; 
    }
    
    void dodajAsistencije(int brojAsistencija) { 
        asistencije += brojAsistencija; 
    }
    
    double izracunPlace() const {
        double bonus = (golovi / 10) * 0.1 * osnovica + (asistencije / 5) * 0.1 * osnovica;
        return osnovica + bonus;
    }
    
    void ispis() const {
        cout << ime << " " << prezime << " - golova: " << golovi << ", asistencija: " << asistencije << endl;
    }
};

class Trener : public Osoba {
private:
    int pobjede, remiji, porazi;
public:
    Trener(string i, string p, double o) : Osoba(i, p, o), pobjede(0), remiji(0), porazi(0) {}
    
    void dodajPobjede(int brojPobjeda) { 
        pobjede += brojPobjeda; 
    }
    
    void dodajRemi(int brojRemija) { 
        remiji += brojRemija; 
    }
   
    void dodajIzgubljene(int brojPoraza) { 
        porazi += brojPoraza; 
    }
   
    double izracunPlace() const {
        double bonus = (pobjede / 5) * 0.1 * osnovica + (remiji / 10) * 0.1 * osnovica;
        double oduzimanje = (porazi / 8) * 0.1 * osnovica;
        return osnovica + bonus - oduzimanje;
    }
    
    void ispis() const {
        cout << ime << " " << prezime << " - Omjer (W/D/L): " << pobjede << " / " << remiji << " / " << porazi << endl;
    }
};

int main()
{
	
    Igrac i("Luka", "Modric", 100000); // Ime, prezime, osnovica plaće
    i.dodajGolove(7);
    i.dodajAsistencije(12);
    i.ispis(); // Luka Modric - golova: 7, asistencija: 12
    cout << "Placa: " << i.izracunPlace() << endl; // Placa: 120000

    Igrac i2("C", "Ronaldo", 234505);
    i2.dodajGolove(57);
    i2.dodajAsistencije(32);
    i2.ispis(); // C Ronaldo - Golova : 57, Asistencije : 32.
    cout << "Placa: " << i2.izracunPlace() << endl; // Placa : 492461

    Trener t1("Hose", "Murinjo", 143009); // Ime, prezime, osnovica plaće
    t1.dodajPobjede(88); // Dodati broj pobjeda (W)
    t1.dodajRemi(12); // Dodati broj neriješenih utakmica (D)
    t1.dodajIzgubljene(0); // Dodati broj izgubljenih (L)
    t1.ispis(); // Hose Murinjo - Omjer (W/D/L): 88 / 12 / 0
    cout << "Placa: " << t1.izracunPlace() << endl; // Placa: 400425

    t1.dodajPobjede(11);
    t1.dodajIzgubljene(47);
    t1.ispis(); // Hose Murinjo - Omjer (W/D/L): 99 / 12 / 47
    cout << "Placa: " << t1.izracunPlace() << endl; // Placa: 357523

    return 0;
}
