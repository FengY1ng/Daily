////main.cpp
//#include "basis.h"
//#include "LinkStack.h"
//
//typedef int Type;
//
//int main()
//{
//	LinkStack<Type>* stack = new LinkStack<Type>();
//	int length;
//	Type median;
//	cout << "��������ʽջ���ȣ�";
//	cin >> length;
//	for (int i = 0; i < length; i++)
//	{
//		cout << endl << "�������" << i + 1 << "��Ԫ��(ע������Ϊ����:";
//		cin >> median;
//		if (!stack->Push(median))
//		{
//			return 0;
//		}
//	}
//	cout << "��ʽջ�ѹ�����ɣ�" << endl;
//	while (1)
//	{
//	we:
//		Sleep(1500);
//		system("cls");
//		cout << "�����������Ҫ���еĲ�����Ӧ�����" << endl
//			<< "1.�����ǰջ" << endl
//			<< "2.����Ԫ��" << endl
//			<< "3.��ȡջ��Ԫ��" << endl
//			<< "4.ɾ��ջ��Ԫ��" << endl
//			<< "5.�˳�����" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//			stack->Output();
//			break;
//		case '2':
//			cout << "������Ԫ��:";
//			cin >> median;
//			stack->Push(median);
//			break;
//		case '3':
//			if (!stack->Top(median))
//			{
//				cout << "��ȡʧ��!" << endl;
//				Sleep(1000);
//				system("cls");
//				goto we;
//			}
//			else
//			{
//				cout << "ջ��Ԫ��Ϊ:" << median << endl;;
//			}
//			break;
//		case '4':
//			stack->Pop(median);
//			break;
//		case '5':
//			return 0;
//		}
//	}
//}