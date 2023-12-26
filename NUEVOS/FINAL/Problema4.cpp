#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream ar;
    string cadena,nombre;
    string resp="ABCCDBADDC";
    int ind,s=0,c=0;
    float puntaje=0;
    string clave="OOOO";
    for(int i=1;i<=3;i++){
    	nombre="respuestas"+to_string(i)+".txt";
	    ar.open(nombre, ios::in);
	    while (getline(ar, cadena)) {
	        ind= (int)resp[c++] -65 ;
	        clave[ind]='X';
	        if(cadena!=clave){
		        for(int j=0;j<4;j++){
		        	if(cadena[j]=='X'){
		        		s++;
					}
				}
				if(s==1)
					puntaje=puntaje-1;
			}else{
				puntaje=puntaje+5;
			}
			s=0;
			clave="OOOO";
	    }
	    ar.close();
	    cout<<"Puntaje obtenido por estudiante "<<i<<": "<<puntaje<<endl;
	    puntaje=0;
	    c=0;
	}	
    return 0;
}

