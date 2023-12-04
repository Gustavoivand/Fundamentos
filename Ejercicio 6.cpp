#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main()
{
char frase[1000], *token;
float s=0;
cout << "Escriba una cadena : ";
cin.getline(frase, sizeof(frase));
token = strtok(frase, " ");
while (token != NULL)
{
s=s+atof(token);
token = strtok(NULL, " /:");
}
cout<<"La suma es: "<<s<<endl;
return 0;
}
