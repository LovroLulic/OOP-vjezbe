#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

class Knjiga {
public:
    string autor;
    string naziv;
    string ISBN;

    Knjiga(string a, string n, string i);
    ~Knjiga();

    void ispis();
};

class Knjiznica {
private:
    string adresa;
    string naziv;
    string kategorija;
    vector<Knjiga> knjige;

    bool provjerikategoriju(const string& kat);
    bool velikopocetnoslovo(const string& str);

public:
    void setNaziv(const string& n);
    void setAdresa(const string& a);
    void setKategoriju(const string& k);
    void dodajKnjigu1(Knjiga z);
    void dodajKnjigu2(Knjiga& z);
    void dodajKnjigu3(Knjiga* z);
    void ispisSvihKnjiga();
    Knjiga nadjiKnjigu1(string ISBN);
    Knjiga* nadjiKnjigu2(string ISBN);
    Knjiga& nadjiKnjigu3(string ISBN);
};

Knjiga::Knjiga(string a, string n, string i) : autor(a), naziv(n), ISBN(i) {
    cout << "Knjiga konstruktor pozvan" << endl;
}

Knjiga::~Knjiga() {
    cout << "Knjiga destruktor pozvan" << endl;
}

void Knjiga::ispis() {
    cout << "Autor: " << autor << endl;
    cout << "Naziv: " << naziv << endl;
    cout << "ISBN: " << ISBN << endl;
}

bool Knjiznica::provjerikategoriju(const string& kat) {
    return (kat == "djecja" || kat == "znanstvena" || kat == "citaonica" || kat == "opcenito");
}

bool Knjiznica::velikopocetnoslovo(const string& str) {
    return isupper(str[0]);
}

void Knjiznica::setNaziv(const string& n) {
    if (velikopocetnoslovo(n)) {
        naziv = n;
    }
    else {
        cout << "Naziv mora poceti velikim slovom!" << endl;
    }
}

void Knjiznica::setAdresa(const string& a) {
    adresa = a;
}

void Knjiznica::setKategoriju(const string& k) {
    if (provjerikategoriju(k)) {
        kategorija = k;
    }
    else {
        cout << "Kategorija nije ispravna!" << endl;
    }
}

void Knjiznica::dodajKnjigu1(Knjiga z) {
    knjige.push_back(z);
}

void Knjiznica::dodajKnjigu2(Knjiga& z) {
    knjige.push_back(z);
}

void Knjiznica::dodajKnjigu3(Knjiga* z) {
    knjige.push_back(*z);
}

void Knjiznica::ispisSvihKnjiga() {
    for (auto& k : knjige) {
        k.ispis();
        cout << endl;
    }
}

Knjiga Knjiznica::nadjiKnjigu1(string ISBN) {
    for (auto& k : knjige) {
        if (k.ISBN == ISBN) {
            return k;
        }
    }
    return Knjiga("Nepoznato", "Nepoznato", "Nepoznato");
}

Knjiga* Knjiznica::nadjiKnjigu2(string ISBN) {
    for (auto& k : knjige) {
        if (k.ISBN == ISBN) {
            return &k;
        }
    }
    return nullptr;
}

Knjiga& Knjiznica::nadjiKnjigu3(string ISBN) {
    for (auto& k : knjige) {
        if (k.ISBN == ISBN) {
            return k;
        }
    }
    cout << "Knjiga nije pronadena!";
    exit(1);
}

int main() {
    Knjiznica k;
    k.setNaziv("Knjiznica 1");
    k.setAdresa("Adresa 123");
    k.setKategoriju("djecja");

    Knjiga knjiga1("Autor 1", "Naziv 1", "ISBN1");
    Knjiga knjiga2("Autor 2", "Naziv 2", "ISBN2");
    Knjiga knjiga3("Autor 3", "Naziv 3", "ISBN3");

    k.dodajKnjigu1(knjiga1);
    k.dodajKnjigu2(knjiga2);
    k.dodajKnjigu3(&knjiga3);

    cout << "Prva izmjena" << endl;
    Knjiga kopija = k.nadjiKnjigu1("ISBN1");
    kopija.naziv = "Izmjenjen naziv";

    cout << "Druga izmjena" << endl;
    Knjiga* kopija2 = k.nadjiKnjigu2("ISBN2");
    if (kopija2) {
        kopija2->naziv = "Izmjenjen naziv 2";
    }

    cout << "Treca izmjena" << endl;
    Knjiga& kopija3 = k.nadjiKnjigu3("ISBN3");
    kopija3.naziv = "Izmjenjen naziv 3";

    cout << "\n\nSve knjige nakon izmjena:" << endl;
    k.ispisSvihKnjiga();

    return 0;
}
