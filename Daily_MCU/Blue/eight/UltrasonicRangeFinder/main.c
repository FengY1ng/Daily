#include <REGX52.H>
#include "Nixie.h"

void ProcessInit()
{
    NixieShowOwn(0,0x39);
    NixieShowNum(2,0);
    NixieShowNum(3,3);
    NixieShowNum(4,0);
    NixieShowNum(5,0);
    NixieShowNum(6,4);
    NixieShowNum(7,0);
}

void main()
{
    NixieShowNum(5,7);
    while(1)
    {
        
    }
}
