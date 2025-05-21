#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;

class Zaposlenik {
protected:
	string ime;
	string ID;
public:
	Zaposlenik(string i, string id):ime(i),ID(id){}

	virtual double izracunajPlacu() const = 0;
	virtual void prikaziInfo() const {
		cout << ime << endl;
		cout << ID << endl;
	}

	virtual ~Zaposlenik(){}

};


class Menadzer : public Zaposlenik {
private:
	double bonus;
	int pocetna = 1000;
public:
	Menadzer(string i,string id,double b):Zaposlenik(i,id), bonus(b){
		if (bonus < 0) throw invalid_argument( "Bonus ne moze bit negaitvan.");
	}

	double izracunajPlacu() const override {
		return pocetna + bonus;
	}

	void prikaziInfo() const override {
		Zaposlenik::prikaziInfo();
		cout << "Placa: " << izracunajPlacu() << endl;
	}

	~Menadzer(){}
};

class Programer : public Zaposlenik {
private:
	int brSati;
	double satnica;
public:

	Programer(string i, string id, int brs, double st):Zaposlenik(i,id),brSati(brs),satnica(st){
		if (brSati < 0 || satnica<0) throw invalid_argument("Broj sati/satnica ne mogu biti negativni brojevi.");
	}
	double izracunajPlacu() const override {
		return brSati * satnica;
	}

	void prikaziInfo() const override {
		Zaposlenik::prikaziInfo();
		cout << "Placa: " << izracunajPlacu() << endl;
	}

	~Programer(){}
};

class Praktikant : public Zaposlenik {
private:
	int naknada = 400;
public:
	Praktikant(string i, string id):Zaposlenik(i,id){}

	double izracunajPlacu() const override {
		return naknada;
	}

	void prikaziInfo() const override {
		Zaposlenik::prikaziInfo();
		cout << "Placa: " << izracunajPlacu() << endl;
	}

	~Praktikant(){}
};


void Analiza(vector<Zaposlenik*>zaposlenici, int* brMen, int* brProg, int* brPrak,int* brZap,double* ukPlace) {
	*brMen = 0;
	*brProg = 0;
	*brPrak = 0;
	*brZap = 0;
	*ukPlace = 0;

	for (auto& z : zaposlenici) {
		if (dynamic_cast<Menadzer*>(z)) {
			(*brMen)++;
			(*brZap)++;
		}
		else if (dynamic_cast<Programer*>(z)) {
			(*brProg)++;
			(*brZap)++;
		}
		else if (dynamic_cast<Praktikant*>(z)) {
			(*brPrak)++;
			(*brZap)++;
		}
	}

	cout << "\nInformacije:" << endl;

	
	for (auto& z : zaposlenici) {
		*ukPlace += z->izracunajPlacu();
		z->prikaziInfo();
		cout << endl;
	}
	cout << "Broj Menadzera: " << *brMen << endl;
	cout << "Broj Programera: " << *brProg << endl;
	cout << "Broj Praktikanata: " << *brPrak << endl;
	cout << "Ukupni trosak na place: " << *ukPlace << endl;
}

int main() {
	vector<Zaposlenik*> zaposlenici;
	int brMen, brProg, brPrak, brZap;
	double ukPlace;
	int izbor;
	do {
		cout << "Dodaj zaposlenika " << endl;
		cout << "1. Menadzer\n2. Programer\n3. Praktikant\n0. Kraj unosa\nIzbor: ";
		cin >> izbor;

		string ime;
		string id;
		if (izbor >= 1 && izbor <= 3) {
			cout << "Ime: ";
			cin >> ws;
			getline(cin, ime);
			cout << "ID: ";
			getline(cin, id);
		}
		try {
			if (izbor == 1) {
				double bonus;
				cout << "Unesi bonus: ";
				cin >> bonus;
				zaposlenici.push_back(new Menadzer(ime, id, bonus));
			}

			else if (izbor == 2) {
				int brSati;
				double satnica;
				cout << "Unesi broj sati: ";
				cin >> brSati;
				cout << "Unesi satnicu: ";
				cin >> satnica;
				zaposlenici.push_back(new Programer(ime, id, brSati, satnica));
			}
			else if (izbor == 3) {
				zaposlenici.push_back(new Praktikant(ime, id));
			}
		}

		catch (const exception& e) {
			cout << "Greska: " << e.what()<<endl;
		}

	} while (izbor != 0);
	

	
	Analiza(zaposlenici, &brMen, &brProg, &brPrak, &brZap, &ukPlace);

	for (auto& z : zaposlenici) {
		delete z;
	}
	return 0;
}
