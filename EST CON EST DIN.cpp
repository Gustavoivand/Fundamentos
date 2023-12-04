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
alumno estudiante;
int i, s;
double promedio;
cout << "Escriba el nombre: ";
getline(cin, estudiante.dat.nombre);
cout << "Escriba la edad: ";
cin >> estudiante.dat.edad;
cin.ignore();
cout << "Escriba el curso: ";
getline(cin, estudiante.curso);
//Lectura la cantidad de notas
int n;
cout << "Ingrese cantidad notas: ";
cin >> n;
estudiante.notas = new int[n];
cin.ignore();
//Fin Lectura la cantidad de notas
cout << "Ingrese las notas\n";
for (i = 0; i < n; i++) {
cout << "Nota " << i + 1 << ": ";
cin >> estudiante.notas[i];
}
//Mostrando promedio
s = 0;
for (i = 0; i < n; i++)
s = s + estudiante.notas[i];
promedio = (float)s / n;
cout << "El alumno " << estudiante.dat.nombre << ", tiene promedio: " << round(promedio);
return 0;
}
