#include <iostream>
#include <string>
using namespace std;
struct Libro
{
	string titulo;
	string anio;
	string autor;
	string paginas;
};

void leerlibro(Libro* book, int n) {
 for (int i = 0; i < n; i++) {
	cin.ignore();
  	cout << "Titulo Libro " << i + 1 << ": ";
  	getline(cin, book[i].titulo);
  	cout << "Anio Libro " << i + 1 << ": ";
  	getline(cin, book[i].anio);
  	cout << "Autor Libro " << i + 1 << ": ";
  	getline(cin, book[i].autor);
  	cout << "cantidad de paginas de Libro " << i + 1 << ": ";
  	getline(cin, book[i].paginas);

 }
}
void mostrarlibro(Libro book[], int n) {
 for (int i = 0; i < n; i++) {
	cout << "Titulo del libro " << i + 1 << ": " << book[i].titulo << endl;
  	cout << "Anio del libro " << i + 1 << ": " << book[i].anio << endl;
  	cout << "Autor del libro " << i + 1 << ": " << book[i].autor << endl;
  	cout << "N° paginas del libro " << i + 1 << ": " << book[i].paginas << endl;
 }
}
void buscarlibroautor(Libro book[], int n,string autores) {//articulo* compra
 for (int i = 0; i < n; i++) {
 	if(book[i].autor==autores){
 		cout << "Titulo del libro " << i + 1 << ": " << book[i].titulo << endl;
  		cout << "Anio del libro " << i + 1 << ": " << book[i].anio << endl;
  		cout << "Autor del libro " << i + 1 << ": " << book[i].autor << endl;
  		cout << "N° paginas del libro " << i + 1 << ": " << book[i].paginas << endl;
	 }

 }
}

int main() {
 int n;
 cout << "Ingrese cantidad de libros: ";
 cin >> n;
 Libro* book = new Libro[n];
 cout << "**********Introduciendo datos**********\n";
 leerlibro(book, n);
 cout << "**********Mostrando datos**********\n";
 mostrarlibro(book, n);
 cout << "**********Buscar un libro por autor**********\n";
string autores;
 cout<<"Ingrese autor: ";
 
 getline(cin, autores);
 buscarlibroautor(book,n,autores);
 return 0;
}
