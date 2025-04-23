#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cmath>
#define PI 3.14159265358979323846
using namespace std;

class Bubble
{
public:
	string boja;
	float radijus;
	Bubble(string b, float r);
	~Bubble();

	float getObujam() const;

	Bubble operator+(const Bubble& drugi) const;
	Bubble operator-(const Bubble& drugi) const;
	bool operator==(const Bubble& drugi) const;
	friend ostream& operator<<(ostream& os, const Bubble& b);


private:

};

Bubble::Bubble(string b, float r) :boja(b), radijus(r)
{
	cout << "Konstruktor klase Bubble" << endl;
}

Bubble::~Bubble()
{
	cout << "Destruktor klase Bubble" << endl;
}

float Bubble::getObujam() const
{
	return (4.0 / 3.0) * PI * pow(radijus, 3);
}

Bubble Bubble::operator+(const Bubble& drugi) const {
	float volumenA = this->getObujam();
	float volumenB = drugi.getObujam();

	float noviVolumen = volumenA + volumenB;

	string novaBoja = (volumenA > volumenB) ? this->boja : drugi.boja;

	float noviRadijus = pow((3 * noviVolumen) / (4 * PI), 1.0 / 3.0);

	return Bubble(novaBoja, noviRadijus);
}

Bubble Bubble::operator-(const Bubble& drugi) const {
	float volumenA = this->getObujam();
	float volumenB = drugi.getObujam();

	if (volumenA <= volumenB)
	{
		return *this;
	}

	float noviVolumen = volumenA - volumenB;

	float noviRadijus = pow((3 * noviVolumen) / (4 * PI), 1.0 / 3.0);

	return Bubble(this->boja, noviRadijus);
}

bool Bubble::operator==(const Bubble& drugi) const {
	
	return (this->boja == drugi.boja && (fabs(this->radijus - drugi.radijus) <= 0.0001));
}

ostream& operator<<(ostream& os, const Bubble& b) {
	os << b.boja << ": " << b.radijus;
	return os;
}


int main()
{
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat ce novi bubble obujma 6275.27
	cout << x<<endl; //blue: 11.44
	Bubble y = x + c;
	cout << y<<endl; //green: 20.12

	Bubble z = y - x;
	cout << z<<endl; //green: 18.8

	if (z == c)
	cout << "OK" << endl; //OK


	return 0;
}
