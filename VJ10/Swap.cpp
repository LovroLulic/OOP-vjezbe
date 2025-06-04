#include <iostream>
#include <vector>
using namespace std;


template <typename T>
void ZamijeniVektora(vector<T>& a, vector<T>& b) {
    swap(a, b);  
}

int main() {
    
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {10, 20, 30};
    
    ZamijeniVektora(v1, v2);  
    
    
    cout << "v1: ";
    for (int x : v1) cout << x << " ";
    
    cout << "\nv2: ";
    for (int x : v2) cout << x << " ";
    
    return 0;
}
