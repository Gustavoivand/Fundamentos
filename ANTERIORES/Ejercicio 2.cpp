#include <iostream>

using namespace std;

int main() {

       int f, c;

       cout << "Escriba las dimensiones de la matriz\n";

       cout << "Filas: ";

       cin >> f;

       cout << "Columnas: ";

       cin >> c;

       //Construyendo las matrices

       int** m1 = new int* [f];

       for (int i = 0;i < f;i++)

             m1[i] = new int[c] {0};

       int** m2 = new int* [f];

       for (int i = 0;i < f;i++)

             m2[i] = new int[c] {0};

       int** m3 = new int* [f];

       for (int i = 0;i < f;i++)

             m3[i] = new int[c] {0};

       //Leyendo las matrices m1 y m2

       cout << "Leyendo m1\n";

       for (int i = 0;i < f;i++) {

             for (int j = 0;j < c;j++) {

                    cout <<"m1[" << i << "][" << j << "]: ";

                    cin >> m1[i][j];

             }

             cout << endl;

       }

       cout << "Leyendo m2\n";

       for (int i = 0;i < f;i++) {

             for (int j = 0;j < c;j++) {

                    cout << "m2[" << i << "][" << j << "]: ";

                    cin >> m2[i][j];

             }

             cout << endl;

       }

       // Sumando las matrices m1 y m2

       for (int i = 0;i < f;i++)

             for (int j = 0;j < c;j++)

                    m3[i][j] = m1[i][j] + m2[i][j];

       //Imprimir la matriz suma

             cout << "La suma es\n";

       for (int i = 0;i < f;i++) {

             for (int j = 0;j < c;j++) {

                    cout << m3[i][j] << " ";

             }

             cout << endl;

       }

}
