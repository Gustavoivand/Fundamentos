// 2.cpp

#include <iostream>
using namespace std;
int main() {
    int *q;
    q=new int();
    *q=1;
	    
    for (int i = 0; i <10; i++) {
    	 cout<<*q<<"  ";
		*q = *q + 1;
    }
    return 0;
}
