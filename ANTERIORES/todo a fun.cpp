#include <iostream>
#include <string>
using namespace std;
struct articulo {
string nombre;
int codigo;
};
void leerarticulo(articulo compra[], int n) {//articulo* compra
 for (int i = 0; i < n; i++) {
cin.ignore();
  cout << "Nombre del articulo " << i + 1 << ": ";
  getline(cin, compra[i].nombre);
  cout << "Codigo del articulo " << i + 1 << ": ";
  cin >> compra[i].codigo;
 }
}
void mostrararticulo(articulo compra[], int n) {//articulo* compra
 for (int i = 0; i < n; i++) {
cout << "Nombre del articulo " << i + 1 << ": " << compra[i].nombre << endl;
  cout << "Codigo del articulo " << i + 1 << ": " << compra[i].codigo << endl;
 }
}
int main() {
 int n;
 cout << "Ingrese cantidad de articulos: ";
 cin >> n;
 articulo* compra = new articulo[n];
 cout << "**********Introduciendo datos**********\n";
 leerarticulo(compra, n);
 cout << "**********Mostrando datos**********\n";
 mostrararticulo(compra, n);
 return 0;
}
