// 4.cpp

#include <iostream>
#include <cstring>
using namespace std;
int EncontrarCStr(const char* str, const char* pa)
{
     int conteo = 0;
      const char *p1, *p2, *p3;
      size_t i, j;
       i = j = 0;
      p1 = str;
      p2 = pa;

     for(i = 0; i < strlen(str); ++i)
          {
    	if(*p1 == *p2)
    	{
                  p3 = p1;
        	      for(j = 0; j < strlen(pa); ++j)
                   {
            	           if(*p3 == *p2)
            	          {
                	//std::cout << "*p3 = " << *p3 << ", *p2 = " << *p2 << std::endl;
                	++p3;
                	++p2;
            	        }
            	        else
                	break;
        	   }
        	   p2 = pa;
        	   if(j == strlen(pa))
        	   {
            	        ++conteo;
        	    }
    	   }
    	        ++p1;
	  }

	   return conteo;
}


int main(int argc, char* argv[])
{
    
	cout << EncontrarCStr("xabaacbaxabb", "ab") << endl;  // 2
    cout << EncontrarCStr("xabaacbaxabb", "aba") << endl; // 1
	return 0;
}
