 //Pregunta 2 - PC2 2022-2 "Con punteros"

 

#include <iostream>
#include <cmath>

using namespace std;

void leerMatriz(int **A,int n){

                for (int i=0;i<n;i++)

                                for (int j=0;j<n;j++){

                                                cout<<"A["<<i<<"]["<<j<<"]: ";

                                                cin>>*(*(A+i)+j); //A[i][j];

                                }             

}

bool matrizDominante(int **A,int n){

                int s;

                for(int i=0;i<n;i++){

                                //Suma la fila

                                s=0;

                                for(int j=0;j<n;j++)

                                                s=s+abs(*(*(A+i)+j)); // A[i][j]

                                /////////////

                                if (abs(*(*(A+i)+i))<=(s-abs(*(*(A+i)+i)))) // A[i][i]

                                                return false;

                }

                return true;

}

int main(){

                int n;

                cout<<"Ingrese el numero de variables: ";

                cin>>n;

                //Creando la matriz dinamica nxn

                int **A=new int*[n];

                for(int i=0;i<n;i++)

                                A[i]=new int[n];

                //Leer Matriz

                leerMatriz(A,n);

                bool resp=matrizDominante(A,n);

                if (resp)

                                cout<<"La matriz SI es dominante\n";

                else

                                cout<<"La matriz NO es dominante\n";

                return 0;

}

