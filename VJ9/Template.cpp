#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template<class T>
class Komparator
{
public:
    Komparator() {}
    ~Komparator() {}

    bool vece_ili_jednako(T a, T b) {
        return a >= b;
    }
};

template<class T2>
class Komparator2
{
public:
    Komparator2() {}
    ~Komparator2() {}

    bool vece_ili_jednako(T2 a, T2 b) {
        return a <= b;
    }
};

template<typename P, typename Comparator>
int usporedi(const vector<P>& v, Comparator &k) {
    for (int i = 1;i < v.size();i++) {
        if (!k.vece_ili_jednako(v[i - 1], v[i])) {
            return 0;
        }
    }
    return 1;
}


int main() {

    vector<int> v = { 12, 2, 1 };
    Komparator2<int> komparator;

    bool r = usporedi<int>(v, komparator);

    cout << "rezultat: " << r << endl;  // treba ispisati 1
}



