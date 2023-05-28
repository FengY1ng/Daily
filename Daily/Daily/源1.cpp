#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct STU
{
	char name[10]; int num; float TotalScore;
};

void f(struct STU* p)
{
	struct STU s[2] = { {"SunDan",20044,520},{"Penghua",20045,537} }, * q = s;
	++p; ++q; *p = *q;
}

int main()
{
	struct STU s[3] = { {"YanSan",2313,123},{"LiGuo",2232,2424} };
	f(s);
	cout << s[1].name << s[1].num << s[1].TotalScore;

	return 0;
}