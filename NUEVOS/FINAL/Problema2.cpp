#include <iostream>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;

    int diasMes(int m, int a){
        if (m == 2) {
            if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    void normalizar() {
        while (mes < 1) {
            mes += 12; anio--;
        }
        while (mes > 12) {
            mes -= 12; anio++;
        }
        while (dia < 1) {
            mes--;
            if (mes < 1) {
                mes = 12; anio--;
            }
            dia += diasMes(mes, anio);
        }
        while (dia > diasMes(mes, anio)) {
            dia -= diasMes(mes, anio);
            mes++;
            if (mes > 12) {
                mes = 1; anio++;
            }
        }
    }

public:
    // constructores vistos en clase
    Fecha() : dia(1), mes(1), anio(1) {
        normalizar();
    }
    Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {
        normalizar();
    }
    Fecha(const Fecha& otraFecha) : dia(otraFecha.dia), mes(otraFecha.mes), anio(otraFecha.anio) {
        normalizar();
    }
    
    void reiniciar(int d, int m, int a) {
        dia = d;
        mes = m;
        anio = a;
        normalizar();
    }

    void adelantar(int d, int m, int a) {
        dia += d;
        mes += m;
        anio += a;
        normalizar();
    }

    void imprimir(){
        cout << dia << "/" << mes << "/" << anio << endl;
    }
};

int main() {
    Fecha fecha1;
    cout << "fecha1: ";
    fecha1.imprimir(); 

    Fecha fecha2(25, 12, 2021);
    cout << "fecha2: ";
    fecha2.imprimir(); 

    Fecha fecha3 = fecha2;
    fecha3.adelantar(10, 2, 1);
    cout << "fecha3 adelantada en 10/2/1: ";
    fecha3.imprimir(); 

    Fecha fecha4(29, 2, 2021);
    cout << "fecha4 antes de reiniciar: ";
    fecha4.imprimir(); 
    
    fecha4.reiniciar(29, 2, 2020);
    cout << "fecha4 después de reiniciar: ";
    fecha4.imprimir();

    Fecha fecha5(32,13,2023);
    cout << "fecha5 no valida se normaliza a: ";
    fecha5.imprimir();
    return 0;
}


