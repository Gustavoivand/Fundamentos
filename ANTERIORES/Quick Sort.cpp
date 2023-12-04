// 2.cpp

#include <iostream>
#include <iomanip>
using namespace std;

const int CAPACIDAD = 10;
void ordenamiento_rapido(int* p, int i_ini, int i_fin);
int separar(int* p, int i_ini, int i_fin);
void mostrar(int* p);

int main() {
    int notas[CAPACIDAD] = {19,13,20,17,12,10,16,19,18,20};
    ordenamiento_rapido(notas, 0, CAPACIDAD-1);
    mostrar(notas);
}

void ordenamiento_rapido(int* p, int i_ini, int i_fin) {
    if (i_ini < i_fin) {
        int i_pivote = separar(p, i_ini, i_fin);
        ordenamiento_rapido(p, i_ini, i_pivote - 1);
        ordenamiento_rapido(p, i_pivote + 1, i_fin);
    }
}

int separar(int* p, int i_ini, int i_fin) {
    int pivote = p[i_fin];
    int i_aux = i_ini;
    int aux;//variable auxiliar para hacer los intercambios
    for (int j = i_ini; j < i_fin; ++j) {
        if (p[j] < pivote) {
            aux = p[i_aux];
            p[i_aux] = p[j];
            p[j] = aux;
            ++i_aux;
        }
    }
    aux = p[i_aux];
    p[i_aux] = p[i_fin];
    p[i_fin] = aux;
    return i_aux;//retornando el indice del pivote
}

void mostrar(int* p) {
    cout << "Notas ordenadas:";
    for (int j = 0; j < CAPACIDAD; ++j)
        cout << setw(4) << *p++; // p[j] o *(p+j)
    cout << endl;
}
