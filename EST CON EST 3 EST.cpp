#include <iostream>
#include<string>
#include <cmath>
using namespace std;
struct datos
{
string nombre;
 int edad;
};
struct alumno {
 datos dat;
 string curso;
int* notas; //Declaramos como puntero
};
int main() {
//Introduciendo datos
const int ne = 4;
alumno estudiante[ne];
int i, s;
double promedio;

for (int j = 0; j < ne; j++) {
	cout << "Escriba el nombre "<<j+1<<": ";
 	getline(cin, estudiante[j].dat.nombre);
 	cout << "Escriba la edad " << j + 1 << ": ";
 	cin >> estudiante[j].dat.edad;
 	cin.ignore();
 	cout << "Escriba el curso " << j + 1 << ": ";
 	getline(cin, estudiante[j].curso);
 	//Lectura la cantidad de notas
	int n;
	cout << "Ingrese cantidad notas: ";
	cin >> n;
	estudiante[j].notas = new int[n];
	cin.ignore();
	//Fin Lectura la cantidad de notas
	cout << "Ingrese las notas\n";
	for (i = 0; i < n; i++) {
		cout << "Nota " << i + 1 << ": ";
		cin >> estudiante[j].notas[i];
		}
	//Mostrando promedio
	s = 0;
	for (i = 0; i < n; i++){
		s = s + estudiante[j].notas[i];
		promedio = (float)s / n;
		cout << "El alumno " << estudiante[j].dat.nombre << ", tiene promedio: " << round(promedio);
		cout << "\n------------------\n";
		cin.ignore();
		}
	}
return 0;
}
