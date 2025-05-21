#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Filter {
public:
    virtual vector<int> uvjet(vector<int> vec) final {
        vector<int> rezultat;
        for (int element : vec) {
            if (provjera(element)) {
                rezultat.push_back(element);
            }
        }
        return rezultat;
    }

    virtual bool provjera(int element) = 0;
};

class FilterVeciOd :public Filter {
public:
    int broj;
    FilterVeciOd(int b):broj(b){}
    bool provjera(int element) {
        return element > 5;
    }
};

class FilterManjiOd :public Filter {
public:
    int broj;
    FilterManjiOd(int br):broj(br){}
    bool provjera(int element) {
        return element < 5;
    }
};

ostream& operator<<(ostream& izlaz, const vector<int>& v) {
    for (int x : v) {
        izlaz << x << " ";
    }
    izlaz << endl;
    return izlaz;
}




int main() {
    vector<int> v = { 14, 3, 18, 5, 6, 10, 2, 8, 1, 7 };

    Filter* filter = new FilterVeciOd(5);        // propusti samo vrijednosti vece od 5
    vector<int> rezultat = filter->uvjet(v);
    cout << rezultat;        // ispisuje 14 18 6 10 8 7
    delete filter;

    filter = new FilterManjiOd(5);        // propusti samo vrijednosti manje od 5
    rezultat = filter->uvjet(v);
    cout << rezultat;        // ispisuje 3 2 1
    delete filter;

    return 0;
}
