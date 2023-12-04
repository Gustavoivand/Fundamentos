// 4.cpp

#include <iostream>
using namespace std;

void RotateLeft(unsigned char* in)
{
    unsigned int* q= (unsigned int*)in;
    *q = (*q >> 8)|((*q & 0xff) << 24);
}

int main() {
    unsigned char temp[4] = {'a', 'b', 'c', 'd'};
    RotateLeft(temp);
    for (int i=0; i<4; i++) {
        cout<<temp[i]<<" ";
    }
}
