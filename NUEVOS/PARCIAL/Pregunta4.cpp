#include <iostream> 
#include <cstring> 

using namespace std; 

int main() { 

    const int maxCaracteres = 100; 
    char frase[maxCaracteres]; 
    cout << "Ingrese una frase: "; 
    cin.getline(frase, maxCaracteres); 
    char* inicioOriginal = frase; 
    char* finOriginal = frase + strlen(frase) - 1; 
    cout << "Direcciones de memoria del texto original:" << endl; 

    while (inicioOriginal <= finOriginal) { 
        cout << "Caracter " << *inicioOriginal << ": " << (void*)inicioOriginal << endl; 
        inicioOriginal++; 
    } 

    char* inicio = frase; 
    char* fin = frase + strlen(frase) - 1; 
    while (inicio < fin) { 
        // Intercambiar los caracteres apuntados por inicio y fin 
        char temp = *inicio; 
        *inicio = *fin; 
        *fin = temp; 
        inicio++; 
        fin--; 

    } 

    cout << "Frase invertida: " << frase << endl; 
    cout << "Direcciones de memoria de la frase invertida:" << endl; 
    char* inicioInvertido = frase; 
    char* finInvertido = frase + strlen(frase) - 1; 
    while (inicioInvertido <= finInvertido) { 
        cout << "Caracter " << *inicioInvertido << ": " << (void*)inicioInvertido << endl; 
        inicioInvertido++; 
    } 
    return 0; 
} 
