#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 99;
    
  
    auto zamijeni = [](int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    };
    
    zamijeni(a, b);  
    
    cout << a << " " << b << endl;  // Ispis: 99 10
    
    return 0;
}
