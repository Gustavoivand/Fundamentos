#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void arrayAleat(int *a, int n){
	srand(time(0));
	int *pi, *pf = a + n -1;
 	for (pi = a  ; pi <= pf; pi++)
		*pi = (rand() % 10) + 1;
}

void elimDuplicado(int *a, int &n){
	int uunico = 0;
 	int i;
 	for (i = 1; i < n; ++i){ 
 		int j = 0;
 		while (j <= uunico && *(a+i) != *(a+j)) ++j;
 		if (j > uunico) 
 			*(a+ ++uunico) = *(a+i); 
 	}
 	n = uunico + 1;  
}

void subtotal (int *a, int n){
 int *pi, *pf = a + n -1;
 for (pi = a + 1 ; pi <= pf; pi++)
	*pi += *(pi -1);
}

void imprimir(int *a, int n){
	for(int i = 0; i < n ; i++){
		cout << *(a+ i) << "  ";
	}
	cout <<endl;
}

int main(){
	int n = 15;
	int a[n]; 
	arrayAleat(a,n);
	cout << "Arreglo alatorio generado: " <<endl;
	imprimir(a, n);
	elimDuplicado(a,n);
	cout << "Arreglo sin elementos repetidos: " << endl;
	imprimir(a, n);
	subtotal(a,n);
	cout << "Arreglo de subtotales: " <<endl;
	imprimir(a, n);
	return 0;
}
