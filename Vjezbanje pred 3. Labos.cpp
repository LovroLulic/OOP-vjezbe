#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class MyClass
{
private:
	float* cijena;
	int* kolicina;
public:
	MyClass(float c, int k);
	~MyClass();

	MyClass(const MyClass& kopija);
	MyClass& operator=(const MyClass& A);
	MyClass(MyClass&& temp);
	MyClass& operator=(MyClass&& temp2);

	
	
	
	
	
	
	
	void setCijena(float c) {
		*cijena = c;
	}
	void setKolicina(int k) {
		*kolicina = k;
	}

	float* getCijena() const {
		return cijena;
	}

	int* getKolicina() const {
		return kolicina;
	}

	void ispisi();
};

MyClass::MyClass(float c, int k) {
	cijena = new float(c);
	kolicina = new int(k);
	cout << "Konstruktor" << endl;
}

MyClass::~MyClass() {
	delete cijena;
	delete kolicina;
	cout << "Destruktor" << endl;
}

MyClass::MyClass(const MyClass& kopija) {
	cijena = new float(*kopija.cijena);
	kolicina = new int(*kopija.kolicina);
	cout << "Kopirajuci konstruktor" << endl;
}

MyClass& MyClass::operator=(const MyClass& A) {
	if (this == &A) {
		return *this;
	}
	delete cijena;
	delete kolicina;

	cijena = new float(*A.cijena);
	kolicina = new int(*A.kolicina);
	cout << "Operator =" << endl;
	return *this;
}

MyClass::MyClass(MyClass&& temp) {
	cijena = temp.cijena;
	kolicina = temp.kolicina;
	temp.cijena = nullptr;
	temp.kolicina = nullptr;
	cout << "Konstruktor prijenosa" << endl;
}

MyClass& MyClass::operator=(MyClass&& temp2) {
	if (this == &temp2) {
		return *this;
	}
	delete cijena;
	delete kolicina;
	cijena = temp2.cijena;
	kolicina = temp2.kolicina;
	temp2.cijena = nullptr;
	temp2.kolicina = nullptr;
	cout << "Operator = prijenosa" << endl;
	return *this;
}

void MyClass::ispisi() {
	if (cijena && kolicina) {
		cout << "Cijena: " << *cijena << endl;
		cout << "Kolicina: " << *kolicina << endl;
	}
	else {
		cout << "Cijena: nullptr" << endl;
		cout << "Kolicina: nullptr" << endl;
	}
}
int main() {
	MyClass klasa(0.0, 0);
	float cijenaunos;
	int kolicinaunos;
	cout << "Unesite cijenu i kolicinu: ";
	cin >> cijenaunos >> kolicinaunos;
	klasa.setCijena(cijenaunos);
	klasa.setKolicina(kolicinaunos);
	klasa.ispisi();

	MyClass klasa2 = klasa;
	klasa2.ispisi();

	MyClass klasa3(1.0, 1);
	klasa3 = klasa;
	klasa3.ispisi();

	MyClass klasa4 = move(klasa);
	klasa4.ispisi();

	MyClass klasa5(2.0, 2);
	klasa5 = move(klasa2);
	klasa5.ispisi();

	cout << "Address of klasa: " << &klasa << endl;
	cout << "Address of klasa2: " << &klasa2 << endl;
	cout << "Address of klasa3: " << &klasa3 << endl;
	cout << "Address of klasa4: " << &klasa4 << endl;
	cout << "Address of klasa5: " << &klasa5 << endl;
	cout << "Address of klasa.cijena: " << klasa.getCijena() << endl;
	cout << "Address of klasa2.cijena: " << klasa2.getCijena() << endl;
	cout << "Address of klasa3.cijena: " << klasa3.getCijena() << endl;
	cout << "Address of klasa4.cijena: " << klasa4.getCijena() << endl;
	cout << "Address of klasa5.cijena: " << klasa5.getCijena() << endl;
	cout << "Address of klasa.kolicina: " << klasa.getKolicina() << endl;
	cout << "Address of klasa2.kolicina: " << klasa2.getKolicina() << endl;
	cout << "Address of klasa3.kolicina: " << klasa3.getKolicina() << endl;
	cout << "Address of klasa4.kolicina: " << klasa4.getKolicina() << endl;
	cout << "Address of klasa5.kolicina: " << klasa5.getKolicina() << endl;

	cout << "\n\n";
	klasa.ispisi(); //bit ce null jer je klasa premjestena
	cout << "\n\n";
	klasa2.ispisi(); //bit ce null jer je klasa premjestena

	return 0;
}

