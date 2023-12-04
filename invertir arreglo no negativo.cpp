// 2.cpp

#include <iostream>
#include <iomanip>
using namespace std;
void invertir(int* p);

int main() {
    int arr1[5] = {2,3,5,7,0};
    int arr2[10] = {5,7,9,11,15,17,19,-1};
    invertir(arr1);
    invertir(arr2);
}

void invertir(int* p) {
    int n = 0;
    while (true) {
        if (*p++ <= 0) break;
        ++n;
    }
    p = p - 2; // haciendo que p apunte al ultimo no nulo
    cout << "Longitud:" << setw(3) << n << endl;
    cout << "Arreglo invertido:";
    for (int j = 0; j < n; ++j) {
        cout << setw(4) << *p--;
    }
    cout << endl;
}
