///Ejercicio 4
//Array de frases con espacio
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
char frases[10][40];
int i, j, k;
cout << "Ingrese 10 frases o una linea en blanco para terminar: " << endl;
for (k = 0; k < 10; k++){
cin.getline(frases[k], sizeof(frases[0]));
if (strlen(frases[k])==0)
break;
}
cout << endl << "Las frases ingresados son :" << endl;
for (i = 0; i < k; i++)
cout << frases[i] << endl;
/////////Burbuja///////////
char aux[40];
for (i=0;i<k-1;i++){
for(j=0;j<k-1-i;j++){
if(strlen(frases[j+1])<strlen(frases[j])){
strcpy(aux,frases[j]);
strcpy(frases[j],frases[j+1]);
strcpy(frases[j+1],aux);
}
}
}
//////////////////////////
cout << endl << "Las frases ordenadas :" << endl;
for (i = 0; i < k; i++)
cout << frases[i] << endl;
return 0;
}
