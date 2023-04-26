
void Delay_ms(unsigned char ms)//11.0592MHz
{
    unsigned char i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
