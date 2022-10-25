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
//	cout << "请输入链式栈长度：";
//	cin >> length;
//	for (int i = 0; i < length; i++)
//	{
//		cout << endl << "请输入第" << i + 1 << "个元素(注：数组为升序）:";
//		cin >> median;
//		if (!stack->Push(median))
//		{
//			return 0;
//		}
//	}
//	cout << "链式栈已构建完成！" << endl;
//	while (1)
//	{
//	we:
//		Sleep(1500);
//		system("cls");
//		cout << "请输入接下来要进行的操作对应的序号" << endl
//			<< "1.输出当前栈" << endl
//			<< "2.加入元素" << endl
//			<< "3.获取栈顶元素" << endl
//			<< "4.删除栈顶元素" << endl
//			<< "5.退出程序" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//			stack->Output();
//			break;
//		case '2':
//			cout << "请输入元素:";
//			cin >> median;
//			stack->Push(median);
//			break;
//		case '3':
//			if (!stack->Top(median))
//			{
//				cout << "获取失败!" << endl;
//				Sleep(1000);
//				system("cls");
//				goto we;
//			}
//			else
//			{
//				cout << "栈顶元素为:" << median << endl;;
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