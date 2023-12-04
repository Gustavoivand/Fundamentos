//Pregunta 01 PC3 2022-1
//Vector cambia tamaño continuamente en ejecucón - PC3 2021-2
#include<iostream>
using namespace std;
int main() {
      float monto;
      int codigo,c=0;
      float v[99]{0};
      while (true) {
            cout << "Ingrese monto: ";
            cin >> monto;
            if (monto == -1) break;
            c++;
            cout << "Ingrese codigo del vendedor: ";
            cin >> codigo;
            v[codigo] = v[codigo] + monto;
      }
      //Promedio de ventas
      float s = 0,prom;
      int vend = 0;
      for (int i = 0; i < 99; i++) {
            if (v[i] != 0) {
                  vend++;
                  s = s + v[i];
            }
      }
      prom = s/c; //Promedio por venta, NO por vendedor
      cout << "Monto promedio: " << prom << endl;
      int* cod = new int[vend];
      int* mont= new int[vend];
      int k = 0;
      for (int i = 0; i < 99; i++) {
            if (v[i] > prom) {
                  cod[k] = i;
                  mont[k] = v[i];
                  k++;
            }    
      }
      //Imprimir vector
      for (int i = 0; i < k; i++)
            cout << "Vendedor " << cod[i] << " Monto " << mont[i] << endl;
      //Liberando memoria
      delete[] cod;
      delete[] mont;
      return 0;
}
