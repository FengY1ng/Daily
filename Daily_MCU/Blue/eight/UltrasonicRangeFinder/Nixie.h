#ifndef __NIXIE_H__
#define __NIXIE_H__

void NixieShowNum(unsigned char local,unsigned char num);
void NixieShowPoint(unsigned char local);
void NixieShowDash(unsigned char local);
void NixieShowHyphen(unsigned char local);
void NixieShowOwn(unsigned char local,unsigned char Data);
void ProcessInit();

#endif