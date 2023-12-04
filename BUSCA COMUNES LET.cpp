//Pregunta 02 - PC3 2021-2
#include<iostream>
using namespace std;
bool esta(int num, int* v, int len) {
      for (int i = 0;i < len;i++)
             if (num == *(v+i))
                   return true;
      return false;
}
int main()
{
      string n1,n2;
      int len1, len2;
      do {
             cout << "Ingrese el primer número :";
             cin >> n1;
             len1 = n1.length();
      } while (len1 > 12);
      do {
             cout << "Ingrese el segundo número :";
             cin >> n2;
             len2 = n2.length();
      } while (len2 > 12);
      int* num1 = new int[len1];
      int* num2 = new int[len2];
      for (int i = 0;i < len1;i++)
             *(num1+i) = n1.at(i)-'0';
      for (int i = 0;i < len2;i++)
             *(num2 + i) = n2.at(i) - '0';
      for (int i = 0;i <= 9;i++)
             if (esta(i, num1,len1) && esta(i, num2,len2))
                   cout << i << "  ";
      cout << endl;
      delete[]num1;
      delete[]num2;
      return 0;
}
