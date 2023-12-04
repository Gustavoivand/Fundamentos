#include <stdio.h>

float suma(float x, float y) {
    return  x + y;
}

float resta(float x, float y) {
    return  x - y;
}

float multiplica(float x, float y) {
    return  x * y;
}

float divide(float x, float y) {
    return  x / y;
}

int main() {
    // Se define un arreglo de punteros a funciones y se le asigna a cada
    // elemento la direcci�n de una funci�n
    float (*operacion[4]) (float, float) = { suma, resta, multiplica, divide };

    char oper[ ] = "+-x/";
    float a = 45, b = 12, c;

    printf("Operaciones:\n");
    for(int i = 0; i < 4; i++) {
        c = operacion[i] (a, b);  // Ejecutamos la funci�n a trav�s de los
                                         // elementos del arreglo
        printf("    %6.2f  %c  %6.2f = %6.2f\n", a, oper[i], b, c);
    }
    return 0;
}
