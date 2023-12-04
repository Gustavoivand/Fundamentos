#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Datos{
	float x;
	float y;
};
//estructura
int main(){
	//abrir archivo
	string nombredearchivo="poligono1.txt";
	ifstream archivo(nombredearchivo.c_str());
	string linea;
	getline(archivo,linea);
	cout<<linea<<endl;
	//La primera linea es la cantidad de puntos CantP
	//CantP=stoi(linea);
	//Hacer una funcion De llenado de puntos en la estructura
	//Datos* Punto = new articulo[CantP]
	//hacer una iteracion para obtener los puntos	
	//int i=0;
	while (getline(archivo,linea)){
		//Punto(i).x=
		cout<<linea<<endl;
		//i++;
	}
	archivo.close();
	
	
 	return 0;
}

