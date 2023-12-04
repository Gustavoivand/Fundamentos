// 3.cpp

#include <iostream>
using namespace std ;
void intercambioPorDireccion ( int*, int* ) ;
void intercambioPorReferencia ( int&, int& ) ;

int main( )
{
	int *a, *b ;
	a= new int();
	b= new int();
	cout << "Ingresa dos numeros: " << endl ;
	cin >> *a >> *b ;
	intercambioPorDireccion( a, b ) ;
    	cout << "Despues de intercambiar numeros por direccion: " << endl ;
    	cout << "a: " << *a << " b: " << *b << endl ;
        	
intercambioPorReferencia ( *a, *b ) ;
            	cout << "Despues de intercambiar numeros por referencia: " << endl ;
            	cout << "a: " << *a << " b: " << *b << endl ;
        	return 0 ;
}
void intercambioPorDireccion ( int *addrA, int *addrB )
{
	int t ;
	t = *addrA ;
	*addrA = *addrB ;
	*addrB = t ;
}
void intercambioPorReferencia ( int &refA, int &refB )

{
	int t ;
	t = refA ;
	refA = refB ;
	refB = t ;
}
