// 3.cpp

#include <iostream>
using namespace std;

void distribuir(int* ar1, int* ar2, int m, int n);
void imprimirVector(int* vector, const int m);

int main(){
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(*ar1);
    int n = sizeof(ar2) / sizeof(*ar2);
    distribuir(ar1, ar2, m, n);
 
    cout << "Resultado: " << endl;
    cout << "Primer Vector: " << endl;
    imprimirVector(ar1, m);
    cout << "Segundo Vector: " << endl;
    imprimirVector(ar2, n);
    return 0;
}


void distribuir(int* ar1, int* ar2, int m, int n){
    for (int i = n - 1; i >= 0; i--){
		int j, last = *(ar1 + m - 1);
        for (j = m - 2; j >= 0 && *(ar1 + j) > *(ar2 + i); j--)
            *(ar1 + j + 1) = *(ar1 + j );

        if (j != m - 2 || last > *(ar2 + i)){
            *(ar1 + j + 1) = *(ar2 + i);
            *(ar2 + i) = last;
        }
        
    }
}


void imprimirVector(int* vector, const int m){
	for (int i = 0; i < m; i++)
        cout << *(vector + i) << " ";
    cout << endl;
}
