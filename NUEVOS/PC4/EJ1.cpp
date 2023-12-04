#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int ne = 8;
//estructura
struct empleados
{
	int id;
	string nombre;
	float salario;
};
//FUNCION LLENAR BINARIO
void llenarbinario(empleados empleado[], int cantidad){
	// Abrir el archivo en modo de escritura binaria
	ofstream archivo("C:/PC4/empleados.bin", ios::binary);
	if (archivo.is_open()) { // Verificamos si el archivo esta abierto
		// Escribir los datos en el archivo
		for(int i=0;i<cantidad;i++){
			int id=empleado[i].id;
			string nombre=empleado[i].nombre;
			float salario=empleado[i].salario;
			archivo.write(reinterpret_cast<char*>(&id), sizeof(id));
			archivo.write(reinterpret_cast<char*>(&salario), sizeof(salario));
			archivo.write(nombre.c_str(), nombre.size() + 1);
		}
		// Cerrar el archivo
		archivo.close();
		cout << "Archivo binario creado correctamente." << endl;
	}
	else {
		cout << "No se pudo crear el archivo." << endl;
	}
}
 //FUNCION LEER BINARIO
 void leerbinario(){
	// Variables para almacenar los datos leídos
	int id;
	float salario;
	string nombre;
	// Abrir el archivo en modo de lectura binaria
	ifstream archivo("C:/PC4/empleados.bin", ios::binary);
	if (archivo.is_open()) {
		while (archivo.read(reinterpret_cast<char*>(&id), sizeof(id))) {
	 		archivo.read(reinterpret_cast<char*>(&salario), sizeof(salario));
	 		getline(archivo, nombre, '\0');
	 		// Mostrar los datos leídos
	 		cout << "ID: " << id <<", ";
			cout << "Nombre: Empleado " << nombre <<", ";
			cout << "Salario: $" << salario << endl;
	}
	//Cerrar el archivo
	archivo.close();
	}
	else {
		cout << "No se pudo abrir el archivo." << endl;
	}
 }
 void buscarporsalario(float minimo,float maximo){
 	// Variables para almacenar los datos leídos
	int id;
	float salario;
	string nombre;
	// Abrir el archivo en modo de lectura binaria
	ifstream archivo("C:/PC4/empleados.bin", ios::binary);
	if (archivo.is_open()) {
		while (archivo.read(reinterpret_cast<char*>(&id), sizeof(id))) {
	 		archivo.read(reinterpret_cast<char*>(&salario), sizeof(salario));
	 		getline(archivo, nombre, '\0');
	 		// Mostrar los datos leídos
	 		if(salario>=minimo and salario<=maximo){
	 		cout << "ID: " << id <<", ";
			cout << "Nombre: Empleado " << nombre <<", ";
			cout << "Salario: $" << salario << endl;
			}
	}
	//Cerrar el archivo
	archivo.close();
	}
	else {
		cout << "No se pudo abrir el archivo." << endl;
	}	
 };
int main() {
//crear vector de empleados
	empleados empleado[ne];
//Datos de empleados
	empleado[0].id=1;
	empleado[0].nombre="A";
	empleado[0].salario=3000;
	empleado[1].id=2;
	empleado[1].nombre="B";
	empleado[1].salario=4000;
	empleado[2].id=3;
	empleado[2].nombre="C";
	empleado[2].salario=3500;
	empleado[3].id=4;
	empleado[3].nombre="D";
	empleado[3].salario=4500;
	empleado[4].id=5;
	empleado[4].nombre="E";
	empleado[4].salario=3200;
	empleado[5].id=6;
	empleado[5].nombre="F";
	empleado[5].salario=3800;
	empleado[6].id=7;
	empleado[6].nombre="G";
	empleado[6].salario=4200;
	empleado[7].id=8;
	empleado[7].nombre="H";
	empleado[7].salario=3900;
	llenarbinario(empleado,ne);
	leerbinario();
	float minimo;
	float maximo;
	cout<<"Ingrese el salario minimo: $";
	cin>>minimo;
	cout<<"Ingrese el salario maximo: $";
	cin>>maximo;
	buscarporsalario(minimo,maximo);

 return 0;
}

