#include <iostream>
using namespace std;

const int MAX_SIZE = 100;  // Change the maximum size as needed
const int CANTIDAD=8;

void findCombinations(int n, int currentCombination[], int currentSum, int start, int size,int *precio) {
    if (currentSum == n) {
        
        // Print the current combination
        cout << "Combinación para varilla de "<<n<<"m: ";
        int suma=0;
        for (int i = 0; i < size; ++i) {
            cout << precio[currentCombination[i]-1] << " ";
            suma=suma+precio[currentCombination[i]-1];
        }
        cout<<endl<<"Precio: "<<suma;
        cout << "\n";

        return;
    }
    for (int i = start; i < n; ++i) {
        if (currentSum + i <= n) {
            currentCombination[size] = i;
            findCombinations(n, currentCombination, currentSum + i, i, size + 1, precio);
        }
    }
};

void buscarmejorarreglo(int* longitud,int* precio){

    for (int i = 0; i < CANTIDAD; i++)
    {
        int currentCombination[MAX_SIZE];
        findCombinations(longitud[i], currentCombination, 0, 1, 0, precio); 
    }
};

int main() {
    //arreglo de varillas
    int longitud[CANTIDAD]={1,2,3,4,5,6,7,8};
    int precio[CANTIDAD]={1,5,8,9,10,17,17,20};
    //arreglo de precios
    buscarmejorarreglo(longitud,precio);
    return 0;
}
