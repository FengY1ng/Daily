#include<iostream>
#include<cmath>
using namespace std;
class container
{
public:
	virtual void show() = 0;  //纯虚函数
	container(double r)
	{
		container::radius = r;
	}
	virtual double area() = 0;  //虚函数面积 
	virtual double volume() = 0;//虚函数体积 
	double print_r()
	{
		return radius;  //获得r值 
	}
	double print_h()
	{
		return height;  //获得h值 
	}
protected:
	double radius;
	double height;

};
class sphere :public container   //声明sphere类公有继承基类
{
public:
	sphere(double r) :container(r)
	{
	};
	double area()
	{
		return 4 * 3.14 * radius * radius;//计算球形面积 
	}
	double volume(double r)
	{
		return 3.14 * radius * radius * radius * 4 / 3; //计算球形体积 
	}
};
class cylinder :virtual public container  //声明cylinder类公有继承基类
{
public:
	cylinder(double r, double h) :container(r)
	{
		height = h;
	};
	double area(double r, double h)
	{
		return 2 * 3.14 * radius * (height + radius);  //计算圆柱体表面积 
	}
	double volume(double r, double h)
	{
		return 3.14 * radius * radius * height;    //计算圆柱体体积 
	}
};
class cube :public container    //声明cube类公有继承基类
{
public:
	cube(double r) :container(r)
	{
	};
	double area(double r)
	{
		return radius * radius * 6;    //计算正方形表面积 
	}
	double volume(double r)
	{
		return radius * radius * radius;   //计算正方形体积 
	}
};
int main()
{
	container* op;    //声明基类指针 
	sphere ab1(3.0);
	cylinder ab2(5.0, 3.0);
	cube ab3(8.0);
	op = &ab1;
	cout << "球体的表面积为:" << op->area() << endl;
	cout << "球体的体积为；" << op->volume() << endl;
	op = &ab2;
	cout << "圆柱体的表面积为：" << op->area() << endl;
	cout << "圆柱体的体积为：" << op->volume() << endl;
	op = &ab3;
	cout << "正方形的表面积为：" << op->area() << endl;
	cout << "正方形的体积为：" << op->volume() << endl;
	return 0;
}