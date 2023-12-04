// 1.cpp

#include <iostream>
#include <cmath>
using namespace std;
 
// Función de utilidad para comprobar si un número dado "n" es un cuadrado perfecto o no
bool esCuadradoPerfecto(int n)
{
    // encuentra el valor de punto flotante de la raíz cuadrada de "n"
    long double sqr = sqrt(n);
 
    // devuelve verdadero si la raíz cuadrada es un número entero
    return sqr == floor(sqr);
}
 
// Función recursiva para encontrar el número mínimo de cuadrados que suman "n"
int encuentraMinCuadrados(int n)
{
    // caso base: `n` es un cuadrado perfecto
    if (esCuadradoPerfecto(n)) {
        return 1;
    }
 
    // inicializar el resultado con el máximo número de cuadrados posible
    int result = n;
 
    // lazo que recorre todos los enteros positivos menores que la raíz cuadrada de "n"
    for (int i = 1; i*i < n; i++)
    {
        // recurre para "n-i × i" y actualiza el resultado si se encuentra un valor menor
        result = min(result, 1 + encuentraMinCuadrados(n - i*i));
    }
 
    return result;
}
 
int main()
{
    int n = 63;
    cout << "El número mínimo de cuadrados es " << encuentraMinCuadrados(n) << endl;
 
    return 0;
}
