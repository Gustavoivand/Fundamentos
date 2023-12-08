#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Declaracion de estructuras
struct MiEstructura
{
	int dato1[2][2];
	int dato2;
};
//Declaracion de funciones
void imprimirmatriz(MiEstructura***,int ,int );
void imprimirmatriz(MiEstructura***,int ,int, int );
int main(){
	srand(time(NULL));
	int filas, columnas;
	//Tamaño de la matriz
	cout<<"Numero de Filas de A: ";
	cin>>filas;
	cout<<"Numero de columnas de A: ";
	cin>>columnas;

	//Crea la matriz cuadrada de punteros a estructuras
	MiEstructura*** matriz=new MiEstructura**[filas];
	//define el maximo valor de la suma de los elementos internos
	int maximo=0;
	for (int i = 0; i < filas; i++)
	{
		*(matriz+i)=new MiEstructura*[columnas];
		for (int j = 0; j < columnas; j++)
		{
			*(*(matriz + i) + j)=new MiEstructura();
			int suma=0;
			int aleatorio;
			for (int p = 0; p < 2; p++)
			{
				for (int q = 0; q < 2; q++)
				{
					aleatorio=rand()%5+1;
					matriz[i][j]->dato1[p][q]=aleatorio;
					suma=suma+aleatorio;
				}
			}
			matriz[i][j]->dato2=suma;
			if (suma>maximo)
			{
				maximo=suma;
			}
			
		}
		
	}
	//imprimimos la matriz cuadrada
	imprimirmatriz(matriz,filas,columnas);
	//imprimimos los maximos
	imprimirmatriz(matriz,filas,columnas,maximo);
	
	return 0;	
}
//definicion de funciones
void imprimirmatriz(MiEstructura ***matriz,int filas,int columnas){
	cout<<"Matriz A:"<<endl;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout<<"Matriz A["<<i<<"]["<<j<<"], (Suma="<<matriz[i][j]->dato2<<"). Direccion de memoria: "<<matriz[i][j]<<endl;
			for (int p = 0; p < 2; p++)
			{
				for (int q = 0; q < 2; q++)
				{
					cout<<"B["<<p<<"]["<<q<<"] = "<<matriz[i][j]->dato1[p][q]<<" ";
				}
				cout<<endl;			
			}
		}
	}
}

void imprimirmatriz(MiEstructura ***matriz,int filas,int columnas, int maximo){
	cout<<"Matriz A:"<<endl;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if(matriz[i][j]->dato2==maximo){
			cout<<"Matriz A["<<i<<"]["<<j<<"], (Suma="<<matriz[i][j]->dato2<<"). Direccion de memoria: "<<matriz[i][j]<<endl;
			}

		}
	}
}