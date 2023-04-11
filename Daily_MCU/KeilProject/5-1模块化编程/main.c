#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main()
{
	while(1)
	{
		int i=0;
		for(i=0;i<8;i++)
		{
			Nixie(i+1,i);
		}
		
	}
}