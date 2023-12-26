#include <iostream>

#define MAX_ROCAS 50000

void orden_Personalizado(int *rocas, int num_rocas) {
  for (int i = 0; i < num_rocas - 1; ++i) {
    for (int j = 0; j < num_rocas - i - 1; ++j) {
      if (*(rocas + j) > *(rocas + j + 1)) {

        int temp = *(rocas + j);
        *(rocas + j) = *(rocas + j + 1);
        *(rocas + j + 1) = temp;
      }
    }
  }
}

int hace_min_distancia(int distancia, int *rocas, int num_rocas,
                          int num_removidos, int longitud) {
  int removido = 0, previa_localizacion_roca = 0, actual_localizacion_roca;
  if (longitud < distancia)
    return 0;
  for (int i = 0; i < num_rocas; i++) {
    actual_localizacion_roca = *(rocas + i);
    if (actual_localizacion_roca - previa_localizacion_roca < distancia)
      removido++;
    else
      previa_localizacion_roca = actual_localizacion_roca;
  }
  if (longitud - previa_localizacion_roca < distancia)
    removido++;
  return removido <= num_removidos;
}

void solucion(int *rocas, int num_rocas,
           int num_removidos, int longitud) {
  int menor, mayor, medio;
  menor = 0;
  mayor = longitud + 1;
  while (mayor - menor > 1) {
    medio = (menor + mayor) / 2;
    if (hace_min_distancia(medio, rocas, num_rocas, num_removidos, longitud))
      menor = medio;
    else
      mayor = medio;
  }
  std::cout << menor << std::endl;
}

int main() {
  static int rocas[MAX_ROCAS];
  int longitud, num_rocas, num_removidos, i;
  std::cin >> longitud >> num_rocas >> num_removidos;
  for (i = 0; i < num_rocas; i++)
    std::cin >> rocas[i];
  orden_Personalizado(rocas, num_rocas);
  solucion(rocas, num_rocas, num_removidos, longitud);
  return 0;
}

