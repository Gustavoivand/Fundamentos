// 4.cpp

#include <iostream>
using namespace std;
int guardar(int * pila, int val);
int recuperar(int * pila);
int efectuarOperacion(int* pila);
int  mostrarPila(int *pila);

const int NMAX=3;// Numero de elementos
int pila[NMAX];
// top es la direccion del primer elemento disponible
// de la pila
int *top, *pilaPtr; 
int main(){
    int xval=0,yval=0,operacion;    
    xval=10; yval=50; operacion=-1;
    pilaPtr=pila;
    top= pilaPtr;
    guardar(pilaPtr, xval);
    mostrarPila(pilaPtr);
    guardar(pilaPtr, yval);
    mostrarPila(pilaPtr);
    guardar(pilaPtr,operacion);
    mostrarPila(pilaPtr);
    efectuarOperacion(pila);
    cout<< "El contenido de la pila es:"<< endl;
    mostrarPila(pilaPtr);
    return 0;
}

int guardar(int *pila, int val){
    if (top>=pila+NMAX){
        cout<<"Desbordamiento de la Pila"<<endl;
        return -1;
    }
    *(top) = val;
    top++;
    return 0;
}

int recuperar(int *pila){
    int val;
    if (top == pila){
        cout<<" la Pila está vacia"<<endl;
        return -1;
    }
    top--;
    val= *top;
    *top=0;
    return val;
}
int efectuarOperacion( int *pila){
    int result=0;
    int operacion=recuperar(pila);
    int operando1=recuperar(pila);
    int operando2=recuperar(pila);
    if (operacion==-1){
        result= operando1 + operando2;
    }else{
        result= operando1 - operando2;
    }
    guardar(pila,result);
    return 0;
}
int  mostrarPila(int *pila){
    for (int i=0; i<NMAX; i++){
        cout << "elem.- "<<i<< " = " << *(pila+i) <<"\t" ; 
    }
    cout << endl;
    return 0;
}
