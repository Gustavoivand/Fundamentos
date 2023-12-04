#include <iostream>
#include <string>
using namespace std;
struct articulo {
 string nombre;
 int codigo;
};
void leerarticulo(articulo* pArticulo) {
cout << "Nombre del articulo: ";
getline(cin, pArticulo->nombre);
cout << "Codigo del articulo: ";
cin >> pArticulo->codigo;
}
void mostrararticulo(articulo* Articulo) {
cout << "Nombre del articulo:" << Articulo->nombre << endl;
cout << "Codigo del articulo: " << Articulo->codigo << endl;
}
int main() {
articulo* pArt = new articulo;
leerarticulo(pArt);
mostrararticulo(pArt);
return 0;
}
