#include <iostream>
#include<string>
using namespace std;
struct persona { // nombre de la estructura
string nombre;
int nota;
} p1, p2 = { "Juan",20 };
int main() {
persona p3;
float prom;
p1.nombre = "Maria";
p1.nota = 18;
p3 = p1;
p3.nombre = "Benito";
cout << "Nombre de p1 " << p1.nombre << endl;
cout << "Nombre de p2 " << p2.nombre << endl;
cout << "Nombre de p3 " << p3.nombre << endl;
prom = (p1.nota + p2.nota + p3.nota) / 3.0;
cout << "El promedio es: " << prom;
return 0;
}
