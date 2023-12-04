#include<iostream>
#include <string>
using namespace std;
int main()
{
string frase;
string clave;
string car;
int sumClave=0,valorConst;
string res="";
cout<<"Ingrese la frase: ";
getline(cin,frase);
cout<<"Ingrese la clave: ";
cin>>clave;
//Hallando el valor constante a partir de la clave
for(int i=0;i<clave.length();i++){
sumClave=sumClave+clave.at(i);
}
valorConst=sumClave%26;
////////////
for (int i=0;i<frase.length();i++){
car=toupper(frase.at(i))+valorConst;
res=res+car;
}
cout<<res<<endl;
return 0;
}
