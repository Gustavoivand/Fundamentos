// 4.cpp

#include <iostream>
#include <cstring>
#include <iomanip>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define SIZE 8
typedef string matrix2D[2][SIZE];
void leerFechaHoraLima(int *);
void mostrar(matrix2D);
void llenarFechas(matrix2D, int *);
string setFechaRegion(int *, int);
int diasPermitidos(int);
int main()
{
    //inicializamos la segunda fila con los horas que se aumentan
    matrix2D horaCiudad = {{"Lima", "La Paz", "Buenos Aires", "Roma", "Jerusalem", "Tokio", "Pekin", "Sidney"}, {"0", "1", "2", "6", "7", "13", "12", "11"}};
    int datos[6] = {};
    leerFechaHoraLima(datos);
    llenarFechas(horaCiudad, datos);
    mostrar(horaCiudad);
    return 0;
}
void leerFechaHoraLima(int datos[])
{
    cout << "Ingrese dia mes anio hora minuto y segundo separado por espacios" << endl;
    cin >> datos[0] >> datos[1] >> datos[2] >> datos[3] >> datos[4] >> datos[5];
}
void llenarFechas(matrix2D datos, int *fechaData)
{
    string *ptrValor = datos[1];
    for (int i = 0; i < SIZE; i++)
    {
        *(ptrValor + i) = setFechaRegion(fechaData, stoi(*(ptrValor + i)));
    }
}
string setFechaRegion(int *fechaData, int diffHoras)
{
    int nuevaHora, nuevoAnio, nuevoMes, nuevoDia;
    nuevaHora = (*(fechaData + 3) + diffHoras);
    nuevoDia = *fechaData;
    nuevoMes = *(fechaData + 1);
    nuevoAnio = *(fechaData + 2);
    if (nuevaHora > 24)
    {
        nuevaHora = nuevaHora % 24;
        if (nuevoDia < diasPermitidos(nuevoMes))
        {
            nuevoDia = nuevoDia + 1;
        }
        else if (*(fechaData + 1) < 12)
        {
            nuevoDia = 1;
            nuevoMes = nuevoMes + 1;
        }
        else
        {
            nuevoDia = 1;
            nuevoMes = 1;
            nuevoAnio = nuevoAnio + 1;
        }
    }
    return to_string(nuevoDia) + "-" + to_string(nuevoMes) + "-" + to_string(nuevoAnio) + " " + to_string(nuevaHora) + ":" + to_string(*(fechaData + 4)) + ":" + to_string(*(fechaData + 5));
}
int diasPermitidos(int mes)
{
    int permitidos;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        permitidos = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        permitidos = 30;
    default:
        permitidos = 28;
        break;
    }
    return permitidos;
}
void mostrar(matrix2D ciudadTiempo)
{
    string *ptrCabecera = ciudadTiempo[0];
    string *ptrValor = ciudadTiempo[1];
    cout << string(150, '-') << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << left << " | " << setw(17) << *(ptrCabecera + i);
    }
    cout << "\n";
    cout << string(150, '-') << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        cout << left << " | " << setw(17) << *(ptrValor + i);
    }
    cout << "\n";
    cout << string(150, '-') << "\n";
}
