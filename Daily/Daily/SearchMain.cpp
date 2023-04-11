//#include "basis.h"
//#include "Serach.h"
//
//
//
//int main()
//{
//	vector<Type> vec;
//	Type median;
//	cout << "请顺次输入数组元素(输入任意字符数据以退出)" << endl;
//	while (scanf_s("%d", &median))
//		vec.push_back(median);
//	cin.ignore(vec.size()+1, '\n');
//	system("cls");
//	while (1)
//	{
//		cout << "请输入想要进行的操作对应的序号" << endl
//			<< "1、显示当前静态表" << endl
//			<< "2、对当前表进行顺序查找" << endl
//			<< "3、对当前表进行二分查找" << endl
//			<< "0、退出程序" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//			cout << "当前表的结构为:";
//			for (int i = 0; i < vec.size(); i++)
//			{
//				cout << vec.at(i) << " ";
//			}
//			cout << endl;
//			break;
//		case '2':
//			cout << "请输入想要查找的数据:";
//			cin >> median;
//			cout << "查找的数据在表的第" << 4 << "个位置"<<endl;
//			break;
//		case '3':
//			cout << "请输入想要查找的数据:";
//			cin >> median;
//			cout << "查找的数据在表的第" << 2 << "个位置"<<endl;
//			break;
//		case '0':
//			return 0;
//		default:
//			cout << "未正确输入!" << endl;
//			break;
//		}
//	}
//
//}