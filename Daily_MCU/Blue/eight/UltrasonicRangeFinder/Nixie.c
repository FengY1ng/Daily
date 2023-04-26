#include <REGX52.H>

unsigned char NixieNum[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x80};
unsigned char NixieLocal[]={0x1C,0x18,0x14,0x10,0x0C,0x08,0x04,0x00};

void NixieShowNum(unsigned char local,unsigned char num)
{
    P2=NixieLocal[local-1];
    P0=NixieNum[num];
}

void NixieShowPoint(unsigned char local)
{
    P2=NixieLocal[local-1];
    P0=NixieNum[10];
}

void NixieShowDash(unsigned char local)
{
    P2=NixieLocal[local-1];
    P0=0x40;
}

void NixieShowHyphen(unsigned char local)
{
    P2=NixieLocal[local-1];
    P0=0x08;
}

void NixieShowOwn(unsigned char local,unsigned char Data)
{
    P2=NixieLocal[local-1];
    P0=Data;
}

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