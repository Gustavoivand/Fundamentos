//Pregunta 01 - PC3 2021-2
#include<iostream>
using namespace std;
void lectura(int* v, int n, string mensaje) {
      for (int i = 0;i < n;i++) {
             cout << mensaje << "[" << i << "]: ";
             cin >> *(v+i);
      }
}
void imprimir(int* v1, int* v2, int n) {
      for (int i = 0;i < n; i++) {
             cout << *(v1 + i) << "\t" << *(v2 + i) << endl;
      }
}

void intercambiar(int* x, int* y) {
      int aux = *x;
      *x = *y;
      *y = aux;
}

void ordQuickSort(int* v,int inicio,int fin) {
      int cen, pivote,i,j;
      cen = (inicio + fin) / 2;
      pivote = *(v+cen);
      i = inicio;
      j = fin;
      while (i <= j) {
             while (*(v + i) < pivote) i++;
             while (*(v + j) > pivote) j--;
             if (i <= j) {
                   intercambiar((v + i), (v + j));
                   i++;
                   j--;
             }
      }
      if (inicio < j)
             ordQuickSort(v, inicio, j);
      if(i<fin)
             ordQuickSort(v, i, fin);
}

int main()
{
      int n;
      cout << "Ingrese el tamaño de los arreglos: ";
      cin >> n;
      int* ayudante = new int[n];
      int* regalo = new int[n];
      lectura(ayudante, n, "Ingrese la estatura del ayudante");
      lectura(regalo, n, "Ingrese el peso del regalo");
      ordQuickSort(ayudante, 0, n - 1);
      ordQuickSort(regalo, 0, n - 1);
      cout << "El reporte de los pares(ayudante, regalo) es:\n";
      imprimir(ayudante, regalo, n);
      return 0;
}

