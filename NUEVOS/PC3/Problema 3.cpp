#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Generales
{
	int B[2][2];
	int suma;
};
int main() {
    int f, i, g,j,k;
    srand(time(NULL));
    cout << "Ingrese cantidad de filas de la matriz: ";
    cin >> f;
    cout << "\n";
    cout << "Ingrese cantidad de columnas de la matriz: ";
    cin >> g;
    cout << "\n";
    float** A = new float* [f];
    for (i = 0; i < f; i++){
	    *(A + i) = new float[g];
	}
	int n=f*g;
	Generales* particulares = new Generales[n];
	    for (i=0;i<n;i++){
    	int sumas=0;
    	for (j=0;j<2;j++)
    		for (k=0;k<2;k++)
    			particulares[i].B[j][k]=1 + rand() % 5;
    			sumas=sumas+particulares[i].B[j][k];
     	particulares[i].suma=sumas;
	}
	
	cout<<(particulares+1);
	
    

}
