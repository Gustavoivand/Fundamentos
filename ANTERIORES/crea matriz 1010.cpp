// 3.cpp

#include <iostream>
#include <ctime>
using namespace std;

void crearMatriz(int** A, int f) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < f; i++)
        for (j = 0; j < f; j++)
            *(*(A + i) + j) = 1 + rand() % 50;
}

void ordenarMatriz(int** A, int f)
{
    int i, j, k, aux;
    for (k = 0; k < f; k++)
    {
        for (i = 0; i < f - 1; i++)
            for (j = 0; j < f - 1 - i; j++)
                if (*(*(A + k) + j) > *(*(A + k) + j + 1))
                {
                    aux = *(*(A + k) + j);
                    *(*(A + k) + j) = *(*(A + k) + j + 1);
                    *(*(A + k) + j + 1) = aux;
                }
    }
}

void escribirMatriz(int** A, int f) {
    int i, j;
    for (i = 0; i < f; i++)
    {
        for (j = 0; j < f; j++)
            cout << *(*(A + i) + j) << "\t";
        cout << endl;
    }
}

int main() {
    int f, i;
    cout << "Ingrese el orden de la matriz cuadrada: ";
    cin >> f;
    cout << "\n";
    //Los alumnos también puede declarar una matriz de
    //tamaño constante 10 X 10 y que el programa solo
    //utilice el tamaño f X f, f<=10.
    //En esta solución se usa una matriz dinámica
    //por si ya se hizo en clases.
    int** A = new int* [f];
    for (i = 0; i < f; i++)
        *(A + i) = new int[f];
    crearMatriz(A, f);
    cout << "Matriz original\n";
    escribirMatriz(A, f);
    ordenarMatriz(A, f);
    cout << "\nMatriz ordenada por filas\n";
    escribirMatriz(A, f);
    return 0;
}
