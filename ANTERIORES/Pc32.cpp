#include <iostream>
using namespace std;
void llenarvector(int*,int,string);
void imprimircomunes(int*,int*,int,int);
int main(){
	string uno,dos;
	cout<<"Ingresa primer digito: ";
	cin>>uno;
	cout<<"Ingresa segundo digito: ";
	cin>>dos;
	int cantidad1,cantidad2;
	cantidad1=uno.length();
	cantidad2=dos.length();
	cout<<cantidad1<<endl;
	cout<<cantidad2<<endl;
	int *vector1=new int[cantidad1];
	int *vector2=new int[cantidad2]; 
	llenarvector(vector1,cantidad1,uno);
	llenarvector(vector2,cantidad2,dos);
	imprimircomunes(vector1,vector2,cantidad1,cantidad2);
	return 0;
};
void llenarvector(int* v,int n,string cifras){
	for(int i=0;i<n;i++){
		*(v+i)=cifras.at(i);
	}
};
void imprimircomunes(int* v1,int* v2,int n1,int n2){
	for(int i=0;i<n1;i++){
		for(int j=0;j<n2;j++){
			if(*(v1+i)=*(v2+j)){
				cout<<*(v1+i);
			}
		}
	}
};
