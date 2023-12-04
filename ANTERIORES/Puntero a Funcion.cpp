#include <stdio.h>

float suma(float x, float y) {
    return x + y;
}
float resta(float x, float y) {
    return x - y;
}
float multiplica(float x, float y) {
    return x * y;
}
float divide(float x, float y) {
    return x / y;
}

float fOpera(float x, float y, float (*f)(float, float)){
    // El puntero f recibe la dirección de inicio de una función
    // no se sabe qué función será la recibida
    return f(x, y);  // Ejecutamos la función a trav6eacute;s del puntero
}

int main(void) {
    float a = 45, b = 12, c;

    printf("Operaciones:\n");
    // Se llama a la función fOpera pasando como par6aacute;metro la función suma
    c = fOpera(a, b, suma);
    printf("    Suma:        %6.2f  + %6.2f = %6.2f\n\n", a, b, c);
    // Se llama a la función fOpera pasando como par6aacute;metro la función multiplica
    c = fOpera(a, b, multiplica);
    printf("    Multiplica: %6.2f  x %6.2f = %6.2f\n\n", a, b, c);
    // Se llama a la función fOpera pasando como par6aacute;metro la función resta
    c = fOpera(a, b, resta);
    printf("    Resta:       %6.2f  - %6.2f = %6.2f\n\n", a, b, c);
    // Se llama a la función fOpera pasando como par6aacute;metro la función divide
    c = fOpera(a, b, divide);
    printf("    Divide:      %6.2f  / %6.2f = %6.2f\n\n", a, b, c);

    return 0;
}
