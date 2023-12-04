// 1.cpp

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

// Función recursiva para encontrar el elemento pico en una matriz
int encuentraElementopico(int nums[], int bajo, int alto, int n)
{
	// Encuentra el elemento medio. Para evitar el desbordamiento, se usa medio = bajo + (alto - bajo) / 2
	int medio = (bajo + alto) / 2;

	// Comprobar si el elemento medio es mayor que sus vecinos
	if ((medio == 0 || nums[medio - 1] <= nums[medio]) &&
			(medio == n - 1 || nums[medio + 1] <= nums[medio])) {
		return medio;
	}

	// Si el vecino izquierdo de `medio` es mayor que el elemento del medio,
	// se encuentra el pico recursivamente en el subarreglo izquierdo
	if (medio - 1 >= 0 && nums[medio - 1] > nums[medio]) {
		return encuentraElementopico(nums, bajo, medio - 1, n);
	}

	// Si el vecino derecho de `medio` es mayor que el elemento del medio,
	// se encuentra el pico recursivamente en el subarreglo derecho
	return encuentraElementopico(nums, medio + 1, alto, n);
}

int encuentraPico(int nums[], int n)
{
	// caso base 
	if (n == 0) {
		exit(-1);
	}

	int index = encuentraElementopico(nums, 0, n - 1, n);
	return nums[index];
}

int main(void)
{
	int *q,*A;
	q=new int();
	cout<<"ingresar cantidad de elementos:"<<endl;
	cin>>*q;
	A=new int[*q];
	for(int i=0;i<*q;i++){
		cout<<"Ingresar elemento "<<i+1<<":";
		cin>>*(A+i);
	}
	//*A= { 6, 12, 13, 1, 8, 6, 5, 10 };
	//int n = sizeof(nums) / sizeof(nums[0]);

	cout<<"El elemento pico encontrado es = "<< encuentraPico(A, *q)<< endl;

	return 0;
}
