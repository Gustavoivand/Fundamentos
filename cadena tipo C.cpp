//Pregunta 1 cadena tipo C
#include<iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
char frase[200];
char vocal[]="aeiou";
int contador[5]{};
cout << "Ingrese la frase: ";
cin.getline(frase, sizeof(frase));
for(int i=0;i<strlen(frase);i++){
if(tolower(frase[i])=='a')
contador[0]++; //Contador[0] es para la a
else if (tolower(frase[i])=='e')
contador[1]++;
else if (tolower(frase[i])=='i')
contador[2]++;
else if (tolower(frase[i])=='o')
contador[3]++;
else if (tolower(frase[i])=='u')
contador[4]++;
}
//Imprimir
for (int i=0;i<5;i++){
cout<<vocal[i]<<": "<<contador[i]<<endl;
}
//Sumando
int s=0;
for (int i=0;i<5;i++){
s=s+contador[i];
}
cout<<"La suma es: "<<s<<endl;
return 0;
}
