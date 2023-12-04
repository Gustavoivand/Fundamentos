//Ejercicio 1
#include<iostream>
using namespace std;
int main() {
      int *n, *f1, *f2, *i, *aux;
      n = new int();
      i = new int();
      aux = new int();
      cout << "Cuantos terminos desea ingresar: ";
      cin >> *n;
      cout << "Losterminos son:\n";
      f1 = new int(1);
      f2 = new int(1);
      cout << *f1 << "  ";
      cout << *f2 << "  ";
      for (*i = 3;*i <= *n;*i=*i+1) {
            *aux = *f2;
            *f2=*f1+*f2;
            *f1 = *aux;
            cout << *f2<<"  ";
      }
      return(0);
}
