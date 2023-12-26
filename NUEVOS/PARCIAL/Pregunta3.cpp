#include <iostream>
#include <string>
using namespace std;

// Funcion para comprobar si una palabra esta presente en el diccionario
bool estaPalabraPresente(string palabra, string dict[], int tamDict) {
    for (int i = 0; i < tamDict; i++) {
        if (palabra == dict[i]) {
            return true;
        }
    }
    return false;
}

// Funcion para segmentar una cadena determinada en una secuencia separada por espacios 
// de una o más palabras del diccionario
void segmentarPalabra(string dict[], int tamDict, string palabra, string salida) {
    if (palabra.size() == 0) {
        cout << salida << endl;
        return;
    }

    for (int i = 1; i <= palabra.size(); i++) {
        string prefix = palabra.substr(0, i);
        if (estaPalabraPresente(prefix, dict, tamDict)) {
            segmentarPalabra(dict, tamDict, palabra.substr(i), salida + " " + prefix);
        }
    }
}

int main() {
    string dict[] = { "this", "th", "is", "famous", "Word", "break",
                      "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

    int tamDict = sizeof(dict) / sizeof(dict[0]);
    string palabra = "Wordbreakproblem";

    segmentarPalabra(dict, tamDict, palabra, "");

    return 0;
}

