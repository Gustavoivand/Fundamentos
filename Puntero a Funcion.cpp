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
    // El puntero f recibe la direcci�n de inicio de una funci�n
    // no se sabe qu� funci�n ser� la recibida
    return f(x, y);  // Ejecutamos la funci�n a trav6eacute;s del puntero
}

int main(void) {
    float a = 45, b = 12, c;

    printf("Operaciones:\n");
    // Se llama a la funci�n fOpera pasando como par6aacute;metro la funci�n suma
    c = fOpera(a, b, suma);
    printf("    Suma:        %6.2f  + %6.2f = %6.2f\n\n", a, b, c);
    // Se llama a la funci�n fOpera pasando como par6aacute;metro la funci�n multiplica
    c = fOpera(a, b, multiplica);
    printf("    Multiplica: %6.2f  x %6.2f = %6.2f\n\n", a, b, c);
    // Se llama a la funci�n fOpera pasando como par6aacute;metro la funci�n resta
    c = fOpera(a, b, resta);
    printf("    Resta:       %6.2f  - %6.2f = %6.2f\n\n", a, b, c);
    // Se llama a la funci�n fOpera pasando como par6aacute;metro la funci�n divide
    c = fOpera(a, b, divide);
    printf("    Divide:      %6.2f  / %6.2f = %6.2f\n\n", a, b, c);

    return 0;
}
