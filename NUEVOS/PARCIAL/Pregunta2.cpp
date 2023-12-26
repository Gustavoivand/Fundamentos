#include <iostream>
using namespace std;

// Función para intercambiar dos elementos usando punteros
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para particionar el arreglo en torno a un pivotee
int* particion(int* bajo, int* alto) {
    int pivote = *alto;
    int* i = bajo - 1;

    for (int* j = bajo; j < alto; j++) {
        if (*j < pivote) {
            i++;
            swap(i, j);
        }
    }

    swap(i + 1, alto);
    return i + 1;
}

// Función de QuickSort usando punteros
void quickSort(int* bajo, int* alto) {
    if (bajo < alto) {
        int* pivoteIndex = particion(bajo, alto);

        quickSort(bajo, pivoteIndex - 1);
        quickSort(pivoteIndex + 1, alto);
    }
}

int main() {
    const int capacidad = 10;
    int numeros[capacidad] = {42, 17, 9, 55, 16, 77, 34, 2, 90, 8};

    int* bajo = &numeros[0];      // Puntero al primer elemento
    int* alto = &numeros[capacidad - 1];  // Puntero al último elemento

    cout << "Arreglo original: ";
    for (int i = 0; i < capacidad; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    quickSort(bajo, alto);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < capacidad; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}
