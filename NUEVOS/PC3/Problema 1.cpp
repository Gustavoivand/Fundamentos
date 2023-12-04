#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void crearMatriz(int** A, int f, int g) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < g; j++)
            *(*(A + i) + j) = 1 + rand() % 50;
};
void escribirMatriz(int** A, int f, int g) {
    int i, j;
    for (i = 0; i < f; i++)
    {
        for (j = 0; j < g; j++)
        	if (*(*(A + i) + j)>0){			
            	cout << *(*(A + i) + j) << "\t";
            	}
        cout << endl;
    }
};
bool Buscar(int valor,int* vector, int numero){
	for(int i=0;i<numero;i++){
		if (valor==vector[i]){	
			return true;
		}				
	}
	return false;
}
void recortarMatriz(int** A,int f,int g,int** B,int* FilA,int Filas,int* ColA,int Columnas){
	//recortar filas
	int i,j,k,m,n;

	for (i=0,m=0;i<f;i++,m++){
        	for (j=0;j<g;j++){
        		if (!Buscar(i,FilA,Filas)){
        		
					*(*(B + m) + j)=*(*(A + i) + j);
				}else{
					*(*(B + m) + j)=-1;
	
				
				}
			}
	}
        			
	//recortar columnas

	for (i=0;i<f;i++){
        	for (j=0,n=0;j<g;j++,n++){
        		if (!Buscar(j,ColA,Columnas)){
        			
					*(*(B + i) + n)=*(*(B + i) + j);
				}else{
					*(*(B + i) + n)=0;	
				
				}
			}
	}
	
};

int const Filas=2;
int const Columnas=3;
int main() {
    int f, i, g;
    cout << "Ingrese cantidad de filas de la matriz: ";
    cin >> f;
    cout << "\n";
    cout << "Ingrese cantidad de columnas de la matriz: ";
    cin >> g;
    cout << "\n";
    int** A = new int* [f];
    for (i = 0; i < f; i++){
	    *(A + i) = new int[g];
	}
	crearMatriz(A, f, g);
    cout << "Matriz original\n";
    escribirMatriz(A, f, g);
    //vector de eliminacion de filas
    int FilA[Filas]={0,5};
	//vector de eliminacion de columnas
    int ColA[Columnas]={0,5,6};
	//Declaración de nueva matriz
	int** B= new int* [f];
	for (i = 0; i < (f); i++){
	    *(B + i) = new int[g];
	}
	//Crear nueva matriz
	recortarMatriz(A,f,g,B,FilA,Filas,ColA,Columnas);
	cout << "\n";
	//escribir nueva matriz
	cout << "Nueva Matriz\n";
	escribirMatriz(B, f, g);	
    return 0;
}
