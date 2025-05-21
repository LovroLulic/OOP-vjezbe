#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Proizvod {
protected:
	string naziv;
	double cijena;
public:
	Proizvod(string n, double c) :naziv(n), cijena(c){}
	virtual double getKoefKvalitete() const = 0;
	virtual void print()const = 0;
	virtual ~Proizvod(){}
};

class LegoIgracka :public Proizvod {
public:
	int brKom;
	LegoIgracka(string n, double c, int brk):Proizvod(n,c),brKom(brk){}
	double getKoefKvalitete() const override {
		return brKom / cijena;
	}
	void print() const override {
		cout << "Lego igracka: " << naziv << ", cijena: " << cijena << ", broj komada: " << brKom << endl;
	}
	~LegoIgracka(){}
};

class Automobil :public Proizvod {
public:
	int god;
	double maxbrzina;
	Automobil(string n, double c, int g, double mb):Proizvod(n,c),god(g),maxbrzina(mb){}
	double getKoefKvalitete() const override {
		return 1.0 / (2015 - god) * maxbrzina / 100 * cijena / 100000.0;
	}
	void print() const override {
		cout << "Automobil: " << naziv << ", cijena: " << cijena << ", godina: " << god << ", max brzina: " << maxbrzina << endl;
	}
	~Automobil(){}
};


int main()
{
	vector<Proizvod*> vp = {
	new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = br. komada
	new Automobil("BMW", 51230, 2013, 207.34), //1. parametar = naziv, 2. parametar = cijena, 3. parametar = god. proizvodnje, 4. parametar = max brzina
	new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
	new Automobil("Yugo 45", 14500, 1988, 127.88),
	};


	Proizvod* max = vp[0];
	for (auto& p : vp) {
		if (p->getKoefKvalitete() > max->getKoefKvalitete()) {
			max = p;
		}
	}

	cout << "Proizvod s najvećim koeficijentom kvalitete:\n";
	max->print();
	cout << "Koeficijent: " << max->getKoefKvalitete() << endl;


	for (auto p : vp) delete p;

	return 0;
}
