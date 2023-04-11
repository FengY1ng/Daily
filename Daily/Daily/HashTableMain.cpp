//#include "basis.h"
//#include "HashTable.h"
//
//typedef int ElemType;
//typedef int KeyType;
//
//int main()
//{
//	int size, divisor, median, k = 1;
//	ElemType e;
//	cout << "请输入哈希表的容量:";
//	cin >> size;
//	cout << endl << "请输入哈希表的赋值除数:";
//	cin >> divisor;
//	cout << endl;
//	HashTable<ElemType, KeyType>* hash = new HashTable<ElemType, KeyType>(size, divisor);
//	while (1)
//	{
//		system("cls");
//		cout << "请输入想要进行的操作对应的序号" << endl
//			<< "1、向哈希表中添加元素" << endl
//			<< "2、在该哈希表中查找元素" << endl
//			<< "0、退出程序" << endl;
//		median = _getch();
//		switch (median)
//		{
//			
//
//		case '1':
//			k = 1;
//			while (k != '0')
//			{
//				cout << "请输入元素:";
//				cin >> e;
//				if (hash->Insert(e))
//				{
//					cout << "插入成功" << endl;
//				}
//				else
//				{
//					cout << "插入失败!" << endl;
//				}
//				cout << "是否要继续插入？（退出请按‘0’键，继续请按任意键）" << endl;
//				k = _getch();
//			}
//			break;
//		case '2':
//			ElemType elem;
//			KeyType key;
//			cout << "请输入想要查找的元素的键值";
//			cin >> key;
//			hash->Search(key, elem);
//			cout << endl << "搜索到的元素为:" << elem << endl;
//			Sleep(2000);
//			break;
//		case '0':
//			return 0;
//		}
//	}
//}