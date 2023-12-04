#include <iostream>
using namespace std;
void lectura(int*, int,string);
void imprimir(int*,int*, int);
void OrdQuicksort(int*,int,int);
void intercambiar(int*,int*);
int main(){
	int n;
	cout<<"Ingrese el tamaño de los arreglos:";
	cin>> n;
	int* ayudante = new int[n];
	int* regalo = new int[n];
	lectura(ayudante,n,"Ingrese la estatura del ayudante:");
	lectura(regalo,n,"Ingrese el peso del regalo:");
	OrdQuicksort(ayudante,0,n-1);
	OrdQuicksort(regalo,0,n-1);
	imprimir(ayudante,regalo,n);
	return 0;
};
void lectura(int* v, int n,string mensaje){
	for(int i=0;i<n;i++){
		cout<< mensaje << "["<<i<<"]: ";
		cin>>*(v+i);
	}
};
void imprimir(int* v1,int* v2, int n){
	for(int i=0;i<n;i++){
		cout<<*(v1+i)<<"\t"<<*(v2+i)<<endl;
	}
};
void OrdQuicksort(int* v,int inicio,int fin){
	int centro,pivote,i,j;
	centro=(inicio+fin)/2;
	pivote=*(v+centro);
	i=inicio;
	j=fin;
	while(i<=j){
		while(*(v+i)<pivote) i++;
		while(*(v+j)>pivote) j--;
		if(i<=j){
			intercambiar((v+i),(v+j));
			i++;
			j--;
		}
	}
	if(inicio<j)
		OrdQuicksort(v,inicio, j);
	if(i<fin)
		OrdQuicksort(v,i,fin);
};
void intercambiar(int* x,int*y){
	int aux=*x;
	*x=*y;
	*y=aux;
};
