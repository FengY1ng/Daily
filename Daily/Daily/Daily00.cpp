#include "basis.h"

class Test_Father
{
private:
	int num=0;
};

class Test_Children:Test_Father
{
public:
	void Output();
};

void Test_Children::Output()
{
	cout << this->num;
}

int main()
{

}