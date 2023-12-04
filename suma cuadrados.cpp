// 1.cpp

#include <iostream>
#include <cmath>
using namespace std;
 
// Funci�n de utilidad para comprobar si un n�mero dado "n" es un cuadrado perfecto o no
bool esCuadradoPerfecto(int n)
{
    // encuentra el valor de punto flotante de la ra�z cuadrada de "n"
    long double sqr = sqrt(n);
 
    // devuelve verdadero si la ra�z cuadrada es un n�mero entero
    return sqr == floor(sqr);
}
 
// Funci�n recursiva para encontrar el n�mero m�nimo de cuadrados que suman "n"
int encuentraMinCuadrados(int n)
{
    // caso base: `n` es un cuadrado perfecto
    if (esCuadradoPerfecto(n)) {
        return 1;
    }
 
    // inicializar el resultado con el m�ximo n�mero de cuadrados posible
    int result = n;
 
    // lazo que recorre todos los enteros positivos menores que la ra�z cuadrada de "n"
    for (int i = 1; i*i < n; i++)
    {
        // recurre para "n-i � i" y actualiza el resultado si se encuentra un valor menor
        result = min(result, 1 + encuentraMinCuadrados(n - i*i));
    }
 
    return result;
}
 
int main()
{
    int n = 63;
    cout << "El n�mero m�nimo de cuadrados es " << encuentraMinCuadrados(n) << endl;
 
    return 0;
}
