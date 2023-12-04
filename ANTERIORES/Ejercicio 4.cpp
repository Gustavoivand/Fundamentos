//Pregunta 3 - PC2 2022-2 "Sin puntero"

#include <iostream>

#include <cstring>

using namespace std;

string mensaje;

bool prueba1(char t[],int n){

                if (t[0]=='4' && n==16){

                                mensaje="La tarjeta es Visa\n";

                                return true;

                }

                else if (t[0]=='5' && n==16){

                                mensaje="La tarjeta es Master Card\n";

                                return true;

                }             

                else if (t[0]=='3' && n==15){

                                mensaje="La tarjeta es America Express\n";

                                return true;

                }

                return false;

}

void prueba2(char t[],int n){

                int tInt,dig;

                //Multiplicando por 2 los de posicion par

                for(int i=n-2;i>=0;i=i-2){

                                tInt=2*(t[i]-48);

                                dig=tInt/10+tInt%10;

                                t[i]=dig+48;

                }

                //Sumando

                int s=0;

                for(int i=0;i<n;i++)

                                s=s+t[i]-48;

                //Comprobando

                if (s%10==0){

                                cout<<mensaje<<endl;

                                cout<<"La tarjeta SI es valida\n";

                }else{

                                cout<<"La tarjeta NO es valida\n";

                }

}

int main(){

                char t[17];

                int n;

                cout<<"Ingrese el numero: ";

                cin.getline(t,17);

                n=strlen(t);

                //Primera prueba

                bool res1=prueba1(t,n);

                //Segunda prueba

                if(res1)

                                prueba2(t,n);

                else

                                cout<<"La tarjeta NO es valida\n";

                return 0;

}
