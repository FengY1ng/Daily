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
////��������ѧ���Ļ�����Ϣ��ѧ�š��������ɼ���������ɼ���ߵ�ѧ����Ϣ
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
//void readDate(STUDENT* stu);//����ѧ����Ϣ�ĺ���
//int main()
//{
//	STUDENT stu;//����һ���ṹ�����stu����ʾѧ����Ϣ,temp��ʾ��ʱ���� ѧ����Ϣ
//	STUDENT* temp;
//	int score = -1;
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		readDate(temp);//����ѧ����Ϣ
//		if (temp->score > score)
//		{
//			stu = *temp;//�������ߵ�ͬѧ
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