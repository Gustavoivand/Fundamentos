#include <iostream>
#include <cstdlib>

using namespace std;

// Estructura para almacenar la informaci�n de un sem�foro
struct Semaforo {
  int valor;
  bool ocupado;
};

// Funci�n para inicializar un sem�foro
Semaforo *inicializarSemaforo(int valor) {
  // Crear un puntero a un sem�foro
  Semaforo *semaforo = new Semaforo();

  // Inicializar el valor del sem�foro
  semaforo->valor = valor;

  // Inicializar el estado del sem�foro
  semaforo->ocupado = false;

  // Devolver el sem�foro
  return semaforo;
}

// Funci�n para adquirir un sem�foro
void adquirirSemaforo(Semaforo *semaforo) {
  // Mientras el sem�foro est� ocupado, esperar
  while (semaforo->ocupado) {
    // Bloquear el hilo
    // No se usa
  }

  // Marcar el sem�foro como ocupado
  semaforo->ocupado = true;
}

// Funci�n para liberar un sem�foro
void liberarSemaforo(Semaforo *semaforo) {
  // Marcar el sem�foro como desocupado
  semaforo->ocupado = false;
}

int main() {
  // Crear un sem�foro
  Semaforo *semaforo = inicializarSemaforo(1);

  // Solicitar al usuario el n�mero de hilos
  int num_hilos;
  cout << "Ingrese el n�mero de hilos: ";
  cin >> num_hilos;

  // Iterar sobre los hilos
  for (int i = 0; i < num_hilos; i++) {
    // Adquirir el sem�foro
    adquirirSemaforo(semaforo);

    // Realizar una operaci�n cr�tica
    cout << "El hilo " << i + 1 << " est� en la secci�n cr�tica" << endl;

    // Liberar el sem�foro
    liberarSemaforo(semaforo);

    // Simular un retardo
    int retardo = rand() % 1000;
    cout << "El hilo " << i + 1 << " est� realizando un retardo de " << retardo << " milisegundos" << endl;

    // Simular el retardo sin sleep_for
    for (int j = 0; j < retardo * 1000; j++) {
      // Realizar una operaci�n simple para simular el paso del tiempo
      int aux = 1 + 1;
    }
  }

  // Destruir el sem�foro
  delete semaforo;

  return 0;
}