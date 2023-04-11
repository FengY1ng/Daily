////#include <iostream>
////#include <vector>
////#include <cmath>
////
////using namespace std;
////
////int main()
////{
////	int t;
////	cin >> t;
////	vector<int> vec(t, 0);
////	for (int i = 0; i < t; i++)
////	{
////		cin >> vec[i];
////		int count = 0,zero=0;
////		vector<int> temp;
////		while (vec[i] != 0)
////		{
////			temp.push_back(vec[i] % 10);
////			if (vec[i] % 10 == 0)
////			{
////				zero++;
////			}
////			vec[i] /= 10;
////		}
////		cout << temp.size()-zero << endl;
////		while (temp.size() != 0)
////		{
////			if (temp[temp.size() - 1] != 0)
////			{
////				cout << temp[temp.size() - 1] * pow(10, temp.size() - 1) << " ";
////			}
////			temp.pop_back();
////		}
////		cout << endl;
////	}
////
////	return 0;
////}
//
////输入三个学生的基本信息（学号、姓名、成绩），输出成绩最高的学生信息
//#include<stdio.h>
//#include<string.h>
//
//typedef struct student
//{
//	char* ID;
//	char* name;
//	int score;
//}STUDENT;
//
//void readDate(STUDENT* stu);//读入学生信息的函数
//int main()
//{
//	STUDENT stu;//声明一个结构体变量stu，表示学生信息,temp表示临时储存 学生信息
//	STUDENT* temp;
//	int score = -1;
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		readDate(temp);//读入学生信息
//		if (temp->score > score)
//		{
//			stu = *temp;//分数更高的同学
//			score = stu.score;
//		}
//	}
//	printf("%s %s %d", stu.ID, stu.name, stu.score);
//	return 0;
//}
//void readDate(STUDENT* stu)
//{
//	scanf("%s", (stu->ID));
//	scanf("%s", (stu->name));
//	scanf("%d", &(stu->score));
//}