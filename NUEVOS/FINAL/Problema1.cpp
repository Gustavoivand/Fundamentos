#include <iostream>
#include <cstdlib>

using namespace std;

// Estructura para almacenar la información de un semáforo
struct Semaforo {
  int valor;
  bool ocupado;
};

// Función para inicializar un semáforo
Semaforo *inicializarSemaforo(int valor) {
  // Crear un puntero a un semáforo
  Semaforo *semaforo = new Semaforo();

  // Inicializar el valor del semáforo
  semaforo->valor = valor;

  // Inicializar el estado del semáforo
  semaforo->ocupado = false;

  // Devolver el semáforo
  return semaforo;
}

// Función para adquirir un semáforo
void adquirirSemaforo(Semaforo *semaforo) {
  // Mientras el semáforo esté ocupado, esperar
  while (semaforo->ocupado) {
    // Bloquear el hilo
    // No se usa
  }

  // Marcar el semáforo como ocupado
  semaforo->ocupado = true;
}

// Función para liberar un semáforo
void liberarSemaforo(Semaforo *semaforo) {
  // Marcar el semáforo como desocupado
  semaforo->ocupado = false;
}

int main() {
  // Crear un semáforo
  Semaforo *semaforo = inicializarSemaforo(1);

  // Solicitar al usuario el número de hilos
  int num_hilos;
  cout << "Ingrese el número de hilos: ";
  cin >> num_hilos;

  // Iterar sobre los hilos
  for (int i = 0; i < num_hilos; i++) {
    // Adquirir el semáforo
    adquirirSemaforo(semaforo);

    // Realizar una operación crítica
    cout << "El hilo " << i + 1 << " está en la sección crítica" << endl;

    // Liberar el semáforo
    liberarSemaforo(semaforo);

    // Simular un retardo
    int retardo = rand() % 1000;
    cout << "El hilo " << i + 1 << " está realizando un retardo de " << retardo << " milisegundos" << endl;

    // Simular el retardo sin sleep_for
    for (int j = 0; j < retardo * 1000; j++) {
      // Realizar una operación simple para simular el paso del tiempo
      int aux = 1 + 1;
    }
  }

  // Destruir el semáforo
  delete semaforo;

  return 0;
}