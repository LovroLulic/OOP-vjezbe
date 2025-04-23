#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Slika
{
public:
    float cijena;
    Slika(float c);
    ~Slika();

    static double ProsjecnaCijena();

private:
    static float brojac;
    static float suma;
};


float Slika::brojac = 0;
float Slika::suma = 0;

Slika::Slika(float c) : cijena(c)
{
    cout << "Konstruktor" << endl;
    brojac++;
    suma += c;
}

Slika::~Slika()
{
    cout << "Destruktor" << endl;
}

double Slika::ProsjecnaCijena()
{
    return suma / brojac;
}

int main()
{
    Slika Slika1(2000); // 2000 eura
    Slika Slika2(3000); // 3000 eura
    Slika Slika3(1800); // 1800 eura

    cout << Slika::ProsjecnaCijena() << " eura" << endl; // 2266.67 eura

    return 0;
}
