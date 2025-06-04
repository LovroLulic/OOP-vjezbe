#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<typename T>
class Niz {
    vector<T> niz;
public:
    Niz(const vector<T>& v) : niz(v) {}
    
    bool manje_od(const Niz& other) const {
        if (niz.empty() || other.niz.empty())
            return false; 
        for (const auto& x : niz) {
            for (const auto& y : other.niz) {
                if (!(x < y))
                    return false;
            }
        }
        return true;
    }
    const vector<T>& get_niz() const { return niz; }
};

template<typename T>
bool operator<(const Niz<T>& a, const Niz<T>& b) {
    return a.manje_od(b);
}

template<typename T>
bool operator>=(const Niz<T>& a, const Niz<T>& b) {
    return !(a < b);
}

template<typename T>
class Niz2 {
    vector<T> niz;
public:
    Niz2(const vector<T>& v) : niz(v) {}
    
    bool manje_od(const Niz2& other) const {
        if (niz.empty() || other.niz.empty())
            return false;
        for (const auto& x : niz) {
            for (const auto& y : other.niz) {
                if (!(x < y))
                    return false;
            }
        }
        return true;
    }
    
    bool operator<(const Niz2& other) const {
        return manje_od(other);
    }
};

int main() {
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 11, 0, 13 };
    Niz<int> p1(v1);
    Niz<int> p2(v2);
    cout << (p1 < p2) << endl;
    cout << (p1 >= p2) << endl;
    Niz2<int> q1(v1);
    Niz2<int> q2(v2);
    cout << (q1 < q2) << endl;
    return 0;
}
