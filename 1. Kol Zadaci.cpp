#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

//class Kompleksni
//{
//public:
//	double re, im;
//};
//
//double Modul(Kompleksni z)
//{
//	return pow(z.re * z.re + z.im * z.im,0.5);
//}
//
//void Sortiraj(Kompleksni* p, int brel) {
//	for (int i = 0; i < brel - 1; i++) {
//		for (int j = 0; j < brel - 1-i; j++) {
//			if (Modul(p[j]) > Modul(p[j + 1])) {
//				Kompleksni tmp = p[j];
//				p[j] = p[j + 1];
//				p[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//
//bool usporedi(Kompleksni a, Kompleksni b) {
//	return Modul(a) < Modul(b);
//}
//
//
//int main() {
//	vector<Kompleksni> niz;
//
//	int brel;
//
//	cout << "Unesite broj kompleksnih brojeva: ";
//	cin >> brel;
//
//	/*Kompleksni* p = new Kompleksni[brel];
//
//	for (int i = 0; i < brel; i++)
//	{
//		cout << "Unesite " << i + 1 << ".re: ";
//		cin >> p[i].re;
//		cout << "Unesite " << i + 1 << ".im: ";
//		cin >> p[i].im;
//	}*/
//
//	for (int i = 0; i < brel; i++)
//	{
//		Kompleksni z;
//		cout << "Unesite " << niz.size()+1 << ".re: ";
//		cin >> z.re;
//		cout << "Unesite " << niz.size()+1 << ".im: ";
//		cin >> z.im;
//		niz.push_back(z);
//	}
//
//	sort(niz.begin(), niz.end(), usporedi);
//
//	/*Sortiraj(p, brel);
//	for (int i = 0; i < brel; i++)
//	{
//		cout << "Z(" << p[i].re << ((p[i].im>0) ? "+":"")<< p[i].im<<"i)=" << Modul(p[i]) << endl;
//	}*/
//
//	for (int i = 0; i < brel; i++) {
//		cout << "Z(" << niz[i].re << ((niz[i].im > 0) ? "+" : "") << niz[i].im << "i)=" << Modul(niz[i]) << endl;
//	}
//
//
//
//	
//}
 
 
 
 
 

//class Student {
//public:
//	string ime, jmbag;
//	Student(string i, string j) : ime(i), jmbag(j) {}
//};
//
//class Bodovi {
//public:
//	Student student;
//	int bodovi;
//	Bodovi(Student s, int b) : student(s), bodovi(b) {};
//};
//
//class Kolegij {
//public:
//	string naziv;
//	vector<Bodovi> bodovi;
//	Kolegij(string n, vector<Bodovi> b) : naziv(n), bodovi(b) {}
//
//
//	
//};
//
//bool usporedi(Bodovi a, Bodovi b) {
//	return a.bodovi < b.bodovi;
//}
//
//
//ostream& operator<<(ostream& izlaz, const Bodovi& b) {
//	izlaz << b.student.ime << " " << b.student.jmbag << " " << b.bodovi;
//	return izlaz;
//}
//
//
//int main() {
//	vector<Bodovi> OOPBodovi{
//		Bodovi(Student("Ivana Ivic", "0246002475"), 25),
//		Bodovi(Student("Ivica Ivanovic", "0246005654"), 20),
//		Bodovi(Student("Marko Markic", "0246004234"), 32)
//	};
//	Kolegij OOP("Objektno orijentirano programiranje", OOPBodovi);
//
//	sort(OOP.bodovi.begin(), OOP.bodovi.end(), usporedi);
//
//
//	cout << "Bodovi na kolegiju " << OOP.naziv << ":" << endl;
//
//	for (int i = 0; i < OOP.bodovi.size(); i++) {
//		cout << OOP.bodovi[i] << endl;
//	}
//	/* Ispišite bodove svih studenata na ‘OOP’ kolegiju sortirane po broju bodova Npr.;
//	   Ivica Ivanovic  0246005654      20
//	   Ivana Ivic      0246002475      25
//	   Marko Markic    0246004234      32 */
//	return 0;
//}
 
 
 
 
 
 

//class Stanar {
//public:
//	string ime;
//	int godine;
//	Stanar(string i, int g) : ime(i), godine(g) {}
//};
//
//class Stan {
//public:
//	vector<Stanar>stanari;
//	int broj;
//
//	void DodajStanara(vector<Stanar>stanri);
//};
//
//void Stan::DodajStanara(vector<Stanar>stanri) {
//	for (int i = 0; i < stanri.size(); i++) {
//		this->stanari.push_back(stanri[i]);
//	}
//	broj = stanari.size();
//}
//
//class Zgrada {
//public:
//	vector<Stan>stanovi;
//	void AnalizaStanova(vector<Zgrada>zgrada, int* samci, int* najstariji,int*Brojstanova,int*skupa);
//};
//
//void Zgrada::AnalizaStanova(vector<Zgrada>zgrada, int* samci, int* najstariji, int*Brojstanova, int*skupa) {
//	
//	for (int i = 0; i < zgrada.size(); i++) {
//		for (int j = 0; j < zgrada[i].stanovi.size(); j++) {
//			if (zgrada[i].stanovi[j].stanari.size() == 1) {
//				(*samci)++;
//			}
//			else {
//				(*skupa)++;
//			}
//			for (int k = 0; k < zgrada[i].stanovi[j].stanari.size(); k++) {
//				if (zgrada[i].stanovi[j].stanari[k].godine > *najstariji) {
//					*najstariji = zgrada[i].stanovi[j].stanari[k].godine;
//				}
//			}
//			*Brojstanova = zgrada[i].stanovi.size();
//		}
//	}
//}
//
//int main() {
//	Stan S;
//
//	vector<Stanar> stanari = { Stanar("Ante", 30), Stanar("Ivica", 25) };
//
//	S.DodajStanara(stanari);
//
//	Stan S2;
//	vector<Stanar> stanari2 = { Stanar("Marko", 40) };
//	S2.DodajStanara(stanari2);
//
//	Stan S3;
//	vector<Stanar> stanari3 = { Stanar("Ana", 20), Stanar("Maja", 22) };
//	S3.DodajStanara(stanari3);
//
//	Zgrada Z;
//	Z.stanovi.push_back(S);
//	Z.stanovi.push_back(S2);
//	Z.stanovi.push_back(S3);
//	int samci = 0;
//	int najstariji = 0;
//	int Brojstanova = 0;
//	int skupa = 0;
//	Z.AnalizaStanova(vector<Zgrada>{Z}, & samci, & najstariji,&Brojstanova,&skupa);
//
//	cout << "Broj samaca: " << samci << endl;
//	cout << "Broj stanova sa vise od jednog stanara: " << skupa << endl;
//	cout << "Najstariji stanar ima: " << najstariji << " godina." << endl;
//	cout << "Broj stanova: " << Brojstanova << endl;
//	
//
//	return 0;
//}







//class Osoba {
//private:
//	string ime;
//	string prezime;
//	int godinarodenja;
//public:
//	bool provjeriime(string i) {
//		return (isupper(i[0]));
//	}
//	bool provjeriprezime(string p) {
//		return (isupper(p[0]));
//	}
//
//	bool provjerigodine(int g) {
//		return (g > 1900 && g < 2025);
//	}
//
//
//	string formatirajIme(string s) {
//		toupper(s[0]);
//		for (int i = 1; i < s.length(); ++i) {
//			tolower(s[i]);
//		}
//	}
//	void setIme(string i) {
//		if (provjeriime(i))  {
//			ime = i;
//		}
//		else {
//			cout<<"Ime mora pocinjati velikim slovom."<<endl;
//		}
//	}
//
//	void setPrezime(string p) {
//		if (provjeriprezime(p)) {
//			prezime = p;
//		}
//		else {
//			cout << "Prezime mora pocinjati velikim slovom." << endl;
//		}
//	}
//
//	void setGodina(int g) {
//		if (provjerigodine(g)) {
//			godinarodenja = g;
//		}
//		else {
//			cout << "Godina rodenja mora biti izmedju 1900 i 2025." << endl;
//		}
//	}
//
//	string getIme() const {
//		return ime;
//	}
//	string getPrezime() const {
//		return prezime;
//	}
//	int getGodina() const {
//		return godinarodenja;
//	}
//};
//
//
//Osoba najstarijaOsoba(vector<Osoba>& osobe, string* najstarijiIme, string* najstarijiPrezime) {
//	int najstarijibroj = 0;
//	for (int i = 0; i < osobe.size(); i++) {
//		if (osobe[i].getGodina() < osobe[najstarijibroj].getGodina()) {
//			*najstarijiIme = osobe[i].getIme();
//			*najstarijiPrezime = osobe[i].getPrezime();
//			najstarijibroj = i;
//		}
//	}
//
//	return osobe[najstarijibroj];
//}
//
//
//int main() {
//	vector<Osoba>osobe(2);
//
//	for (int i = 0; i < osobe.size(); i++) {
//		string tmpIme, tmpPrezime;
//		int tmpGodina;
//		cout << "Unesite ime "<<i+1<<". osobe: ";
//		cin >> tmpIme;
//		osobe[i].setIme(tmpIme);
//		cout << "Unesite prezime " << i + 1 << ". osobe: ";
//		cin >> tmpPrezime;
//		osobe[i].setPrezime(tmpPrezime);
//		cout << "Unesite godinu rodenja " << i + 1 << ". osobe: ";
//		cin >> tmpGodina;
//		osobe[i].setGodina(tmpGodina);
//
//	}
//
//
//	string najstarijiIme = "";
//	string najstarijiPrezime = "";
//
//	Osoba najstariji = najstarijaOsoba(osobe, &najstarijiIme, &najstarijiPrezime);
//	cout << "Najstarija osoba je: " << najstarijiIme << " "<<najstarijiPrezime;
//	cout << " i rodena je " << najstariji.getGodina() <<". godine"<< endl;
//
//	return 0;
//}





//class Student {
//public:
//	string ime, jmbag;
//	Student(string i, string j) : ime(i), jmbag(j) {}
//};
//
//
//class Ucionica {
//public:
//    vector<Student*> student;
//
//
//    Ucionica() = default;
//
//	//Kopirni konstruktor
//	Ucionica(const Ucionica& druga) {
//		for (int i = 0; i < druga.student.size(); i++) {
//			student.push_back(new Student(*druga.student[i]));
//		}
//	}
//
//	//Operator Pridruzivanja
//	Ucionica& operator=(Ucionica& druga) {
//		if (this != &druga) {
//			for (int i = 0; i < student.size(); i++) {
//				delete student[i];
//			}
//			student.clear();
//			for (int i = 0; i < druga.student.size(); i++) {
//				student.push_back(new Student(*druga.student[i]));
//			}
//		}
//
//
//		return *this;
//	}
//
//	//Konstruktor Prijenosa
//	Ucionica(Ucionica&& druga) {
//		student = move(druga.student);
//		druga.student.clear();
//	
//	}
//
//	//Operator prijenosa
//	Ucionica& operator=(Ucionica&& druga) {
//		if (this != &druga) {
//			for (int i = 0; i < student.size(); i++) {
//				delete student[i];
//			}
//			student.clear();
//			student = move(druga.student);
//			druga.student.clear();
//		}
//	
//		return *this;
//	}
//
//    ~Ucionica() {
//		for (int i = 0; i < student.size(); i++) {
//			delete student[i]; // Delete each dynamically allocated Student object
//		}
//		student.clear(); // Clear the vector
//        
//    }
//};
//
//
//int main() {
//    // Create a Ucionica object and add students
//    Ucionica u1;
//    u1.student.push_back(new Student("Ivana", "001"));
//    u1.student.push_back(new Student("Marko", "002"));
//
//    // Test Copy Constructor
//    cout << "Testing Copy Constructor:" << endl;
//    Ucionica u2 = u1; // Copy constructor
//    for (int i = 0; i < u2.student.size(); i++) {
//        cout << "Student in u2: " << u2.student[i]->ime << " " << u2.student[i]->jmbag << endl;
//    }
//
//    // Modify the original object to ensure deep copy
//    u1.student[0]->ime = "Ana";
//    cout << "After modifying u1, u2 remains unchanged:" << endl;
//    for (size_t i = 0; i < u2.student.size(); i++) {
//        cout << "Student in u2: " << u2.student[i]->ime << " " << u2.student[i]->jmbag << endl;
//    }
//
//    // Test Copy Assignment Operator
//    cout << "\nTesting Copy Assignment Operator:" << endl;
//    Ucionica u3;
//    u3 = u2; // Copy assignment
//    for (int i = 0; i < u3.student.size(); i++) {
//        cout << "Student in u3: " << u3.student[i]->ime << " " << u3.student[i]->jmbag << endl;
//    }
//
//    // Test Move Constructor
//    cout << "\nTesting Move Constructor:" << endl;
//    Ucionica u4 = move(u1); // Move constructor
//    for (int i = 0; i < u4.student.size(); i++) {
//        cout << "Student in u4: " << u4.student[i]->ime << " " << u4.student[i]->jmbag << endl;
//    }
//    cout << "u1 should now be empty (moved): " << u1.student.size() << " students." << endl;
//
//    // Test Move Assignment Operator
//    cout << "\nTesting Move Assignment Operator:" << endl;
//    Ucionica u5;
//    u5 = move(u2); // Move assignment
//    for (int i = 0; i < u5.student.size(); i++) {
//        cout << "Student in u5: " << u5.student[i]->ime << " " << u5.student[i]->jmbag << endl;
//    }
//    cout << "u2 should now be empty (moved): " << u2.student.size() << " students." << endl;
//
//    
//
//    return 0;
//}





//class Slika {
//public:
//    double cijena;
//	
//    Slika(double c) : cijena(c) {
//		brojSlika++;
//		ukupnaCijena += c;
//	}
//
//
//	static double ProsjecnaCijena() {
//		if (brojSlika == 0) return 0;
//		return ukupnaCijena / brojSlika;
//	}
//	
//private:
//	static int brojSlika;
//	static double ukupnaCijena;
//};
//
//int Slika::brojSlika = 0;
//double Slika::ukupnaCijena = 0;
//
//int main() {
//    Slika Slika1(2000); // 2000 eura
//    Slika Slika2(3000); // 3000 eura
//    Slika Slika3(1800); // 1800 eura
//    cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
//    return 0;
//}





class Operacija {
public:
    short a, b;
    char znak;
    Operacija(short a, short b, char znak) : a(a), b(b), znak(znak) {};

    short rezultat() {
        short rez=0;
        if (znak == '+') {
            rez = a + b;
        }
        else if (znak == '-') {
            rez = a - b;
        }
        else if (znak == '*') {
            rez = a * b;
        }
        else if (znak == '/') {
            if (b == 0) {
				throw a;
            }
            else {
                rez = a / b;
            }
        }
        
        if (a > 0 && b > 0 && rez < 0) {
            throw "Integer overflow!";
        }
        return rez;


    }
};



int main() {
    short a, b;
    cin >> a >> b;
    try {
        cout << Operacija(a, b, '+').rezultat() << endl;
        cout << Operacija(a, b, '-').rezultat() << endl;
        cout << Operacija(a, b, '*').rezultat() << endl;
        cout << Operacija(a, b, '/').rezultat() << endl;
    }
    catch (short n) {
        cout << "Broj " << n << " se ne moze dijeliti s 0!\n";
    }
    catch (const char* s) {
        cout << s;
    }
    return 0;
}