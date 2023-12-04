//Pregunta 03 - PC3 2021-2
#include<iostream>
using namespace std;
void imprimirMatriz(int** A, int f, int c) {
      for (int i = 0; i < f; i++) {
            cout << "T(" << i + 1 << "):\t";
            for (int j = 0; j < c; j++) {
                  cout << A[i][j] << "\t";
            }
            cout << endl;
      }
}
void leerMatriz(int** A, int f, int c) {
      for (int j = 0; j < c; j++) {
            cout << "Almancen Nro " << j + 1 << endl;
            for (int i = 0; i < f; i++) {
                  cout << "Tipo (" << i + 1 << ") = ";
                  cin >> A[i][j];
            }
      }
}
void sumarFilas(int** A, int f, int c) {
      int s = 0;
      for (int i = 0; i < f; i++) {
            for (int j = 0; j < c; j++) {
                  s = s + A[i][j];
            }
            A[i][c] = s;
            s = 0;
      }
}
void sumarColumnas(int** A, int f, int c) {
      int s = 0;
      for (int j = 0; j <= c; j++) {
            for (int i = 0; i < f; i++) {
                  s = s + A[i][j];
            }
            A[f][j] = s;
            s = 0;
      }
}
int main() {
      int f, c;
      do{
            cout << "Numero de tipos: ";
            cin >> f;
      } while (f > 15);
      do {
            cout << "Numero de almacenes: ";
            cin >> c;
      } while (c > 20);
      f++;
      c++;
      int** A = new int* [f];
      for (int i = 0; i < f; i++)
            A[i] = new int[c] {};
      leerMatriz(A, f - 1, c - 1);
      sumarFilas(A, f - 1, c - 1);
      sumarColumnas(A, f - 1, c - 1);
      cout << "Matriz ingresada:\n";
      imprimirMatriz(A, f, c);
      //Liberar memoria
      for (int i = 0; i < f; i++)
            delete[] A[i];
      delete[] A;
      return 0;
}
