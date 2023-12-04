// 1.cpp
#include <cstdio>
#include <iostream>
using namespace std;
 
// Funci�n para intercambiar los elementos `A[i]` y `A[j]` en un arreglo
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
 
// Rutina de partici�n de tiempo lineal para ordenar una matriz que contiene 0, 1 y 2.
// Es similar a la partici�n de 3 v�as para el problema de la bandera nacional alemana.
int threeWayPartition(int A[], int end)
{
    int start = 0, mid = 0;
    int pivot = 1;
 
    while (mid <= end)
    {
        if (A[mid] < pivot)         // el elemento actual es 0
        {
            swap(A, start, mid);
            ++start, ++mid;
        }
        else if (A[mid] > pivot)    // el elemento actual es 2
        {
            swap(A, mid, end);
            --end;
        }
        else {                      // el elemento actual es 1
            ++mid;
        }
    }
}
 
int main()
{
    int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
    int n = sizeof(A)/sizeof(A[0]);
 
    threeWayPartition(A, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout<<A[i];
    }
 
    return 0;
}
