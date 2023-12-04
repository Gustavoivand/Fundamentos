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
 int cantNotas;
 int* notas; //Declaramos como puntero
};
void leerDatos(alumno& pupilo) {
 int i;
 cout << "Escriba el nombre: ";
 getline(cin, pupilo.dat.nombre);
 cout << "Escriba la edad: ";
 cin >> pupilo.dat.edad;
 cin.ignore();
 cout << "Escriba el curso: ";
 getline(cin, pupilo.curso);
 //Lectura la cantidad de notas
 int n;
 cout << "Ingrese cantidad notas: ";
 cin >> n;
 pupilo.cantNotas = n;
 pupilo.notas = new int[n];
cin.ignore();
 //Fin Lectura la cantidad de notas
 cout << "Ingrese las notas:" << endl;
 for (i = 0; i < n; i++) {
cout << "Nota " << i + 1 << ": ";
cin >> pupilo.notas[i];
}
cin.ignore();
}
void mostrarDatos(alumno& pupilo) {
 int i;
 float s;
float promedio;
int n = pupilo.cantNotas;
cout << "Nombre: " << pupilo.dat.nombre << endl;
 cout << "Curso: " << pupilo.curso << endl;
 cout << "Edad: " << pupilo.dat.edad << endl;
cout << "Las notas: " << endl;
s = 0;
for (i = 0; i < n; i++) {
cout << "Nota " << i + 1 << ": ";
cout << pupilo.notas[i] << endl;
s = s + pupilo.notas[i];
}
 promedio = s / n;
 cout << "El alumno " << pupilo.dat.nombre << ", tiene promedio: " << round(promedio);
 cout << "\n------------------\n";
}
int main() {
//Introduciendo datos
 alumno* estudiante;
 int i, ne;
 cout << "**********Introduciendo datos**********\n";
 cout << "Ingrese cantidad de estudiantes:  ";
 cin >> ne;
 estudiante = new alumno[ne];
 cin.ignore();
for (i = 0; i < ne; i++) {
leerDatos(estudiante[i]);
 }
 //Mostrando datos
 cout << "**********Mostrando datos**********\n";
 for (i = 0; i < ne; i++) {
cout << "Estudiante " << i + 1 << endl;
mostrarDatos(estudiante[i]);
 }
 return 0;
}
