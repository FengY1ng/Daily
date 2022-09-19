//#include <iostream>
//#include <string>
//#include <conio.h>
//#include <cstring>
//
//using namespace std;
//
//const int CLASS = 5;
//const int STUDENT = 10;
//
//struct student
//{
//	double score[CLASS];
//}stu[STUDENT];
//
//void averageStudent(student stu)
//{
//	double all=0;
//	for (int i = 0; i < CLASS; i++)
//		all += stu.score[i];
//	cout << all / CLASS;
//}
//
//void averageClass(student stu[],int num)
//{
//	double all = 0;
//	for (int i = 0; i < STUDENT; i++)
//	{
//		all += stu[i].score[num];
//	}
//	cout << all / STUDENT;
//}
//
//void scoreMax(student sut[])
//{
//	double max_i = -1,max_j=-1,max=-1;
//	int i, j;
//	for (i = 0; i < STUDENT; i++)
//		for (j = 0; j < CLASS; j++)
//			if (stu[i].score[j] > max)
//			{
//				max = stu[i].score[j];
//				max_i = i; 
//				max_j = j;
//			}
//	cout << "得分最高的分数属于第" << max_i + 1 << "名学生的第" << max_j + 1 << "门学科";
//}
//
//int main()
//{
//	for (int i = 0; i < STUDENT; i++)
//	{
//		for (int j = 0; j < CLASS; j++)
//		{
//			cout << "第" << i + 1 << "个学生的第" << j + 1 << "门课的成绩为:";
//			cin >> stu[i].score[j];
//			cout << endl;
//		}
//	}
//	for (int i = 0; i < STUDENT; i++)
//	{
//		cout << "第" << i + 1 << "名学生的平均成绩为:";
//		averageStudent(stu[i]);
//		cout << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < CLASS; i++)
//	{
//		cout << "第" << i + 1 << "门课的平均成绩为:";
//		averageClass(stu, i);
//		cout << endl;
//	}
//	cout << endl;
//	scoreMax(stu);
//	return 0;
//}

