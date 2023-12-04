// 1.cpp

#include <iostream>
#include <cstdio>
using namespace std;

// Funci�n para encontrar el n�mero total de veces que es girado el arreglo
int contaRotacion(int nums[], int n)
{
    // el espacio de b�squeda es nums[bajo�alto]
    int bajo = 0, alto = n - 1;
 
    // bucle hasta que se agote el espacio de b�squeda
    while (bajo <= alto)
    {
        // si el espacio de b�squeda ya est� ordenado, hemos encontrado
		// el elemento m�nimo (en el �ndice `bajo`)
        if (nums[bajo] <= nums[alto]) {
            return bajo;
        }
 
        int medio = (bajo + alto) / 2;
 
        // encuentra el elemento anterior y siguiente del elemento
		// `medio` (en forma circular)
        int siguiente = (medio + 1) % n;
        int previo = (medio - 1 + n) % n;
 
        // si el elemento `medio` es menor que su vecino siguiente 
		// y anterior, es el elemento m�nimo de la matriz
 
        if (nums[medio] <= nums[siguiente] && nums[medio] <= nums[previo]) {
            return medio;
        }
 
        // si nums[medio�alto] est� ordenado, y `medio` no es el elemento m�nimo, entonces
		// el elemento pivote no puede estar presente en nums[medio�alto], se descarta nums[medio�alto]
		// y se busca en la mitad izquierda
 
        else if (nums[medio] <= nums[alto]) {
            alto = medio - 1;
        }
 
        // si nums[bajo�medio] est� ordenado, entonces el elemento pivote no
		// puede estar presente en �l; se descarta nums[bajo�medio] y se busca
		// en la mitad derecha
 
        else if (nums[medio] >= nums[bajo]) {
            bajo = medio + 1;
        }
    }
 
    // salida inv�lida
    return -1;
}
 
int main(void)
{
	int *q;
	q= new int();
	cout<<"Ingresar cantidad de elementos"<<endl;
	cin>>*q;
	
	int *A;
	A= new int[*q];
	
	for (int i=0;i<*q;i++){
		cout<<"Ingresar elemento"<<i+1<<":";
		cin>>*(A+i);
	};
    int conta = contaRotacion(A, *q);
    cout<<"El arreglo es rotado "<<conta<<" veces"<<endl;
 
    return 0;
}


