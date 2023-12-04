// 3.cpp

#include <iostream>
#include <cstring>
using namespace std;

char *invertido(char *);
char *siguienteCaracter(char *);
void quitaEspacios(char *);
int main()
{
    char texto[] = "   P az y     bien   ";
    quitaEspacios(siguienteCaracter(invertido(texto)));
    return 0;
}
char *invertido(char *frase)
{        
    for (int i = 0; i < strlen(frase) / 2; i++)
    {
        char temp = frase[i];
        frase[i] = frase[strlen(frase) - i - 1];
        frase[strlen(frase) - i - 1] = temp;
    }
    return frase;
}
char * siguienteCaracter (char *frase){
    for (int i = 0; i < strlen(frase); i++){
        int asciiNumber=(int)frase[i]+1;
        if(asciiNumber>122){
            frase[i]=static_cast<char> (97);
        }else if ( asciiNumber>97) {
            frase[i]= static_cast<char> (asciiNumber);
        }else if  (asciiNumber> 90){
            frase[i]=static_cast<char> (65);
        }else{
            frase[i]= static_cast<char> (asciiNumber);
        }        
    }
    return frase;
}
void quitaEspacios(char * frase){
    char finalFrase [strlen(frase)+1];
    int indexFinal=0;
    for (int i = 0; i < strlen(frase); i++){  
    
        if (frase[i]!='!'){
            finalFrase[indexFinal]=frase[i];
            indexFinal+=1;
        }
    }
    finalFrase[indexFinal]='\0';        
    cout<< finalFrase<<endl;
}
//Resultado: ofjczabQ
