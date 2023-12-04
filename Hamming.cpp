// 2.cpp

#include <iostream>
using namespace std;
const int STRLNG = 5;
const int ADNLNG=5;

int hamming(char* s1, char* s2){
    int dist=0;
    for(int i=0; i<STRLNG; i++){
        if (*(s1+i) != *(s2+i)){
            dist++;
        }
    }
    return dist;
}

int main()
{
    int dist=0;
    int mindist=99, mini=0,minj=0;

    // char * ADN[ADNLNG] ={
    char ADN[ADNLNG][STRLNG] ={
        "AAAC",
        "ACCC",
        "AGCC",
        "GGAC",
        "GGGA",
        };

    for (int i = 0 ; i< ADNLNG;  i++){  
        for (int j=i; j< ADNLNG;  j++){  
            dist = hamming(*(ADN+i), *(ADN+j));
            if (dist!=0 && dist< mindist) {
                mindist=dist;
                minj=j;
                mini=i;
            }    
            cout << "La distancia entre " << *(ADN+i) << " y " 
                << *(ADN+j) << " es: "<< dist << endl;
        }    
    }
    cout << "La menor distancia es: " << mindist << " entre "
            <<  *(ADN+mini) << " y " << *(ADN+minj) << endl;
    return 0;
}
