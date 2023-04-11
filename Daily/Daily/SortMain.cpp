////SortMain.cpp
//#include "basis.h"
//#include "Sort.h"
//
//typedef int Type;
//
//int main()
//{
//	vector<Type> vec;
//	int inc[5];
//	int median;
//	cout << "是否要构建数组？（按下‘1’以构建，按下‘0’以使用默认数组）";
//	cin >> median;
//	switch (median)
//	{
//	case '1':
//		InsertElem<Type>(vec);
//	case 0:
//		DefaultVector<Type>(vec);
//	}
//	while (1)
//	{
//		system("cls");
//		cout << "请输入想要进行的操作对应的序号" << endl
//			<< "1、显示当前数组" << endl
//			<< "2、对数组进行堆排序" << endl
//			<< "3、对数组进行归并排序" << endl
//			<< "4、对数组进行基数排序" << endl
//			<< "0、退出程序" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//			for (int i = 0; i < vec.size(); i++)
//				cout << vec[i] << " ";
//			cout << endl;
//			Sleep(2000);
//			break;
//		case '2':
//			HeapSort(vec);
//			cout << "堆排序完成" << endl;
//			Sleep(2000);
//			break;
//		case '3':
//			SimpleMergeSort(vec);
//			cout << "归并排序完成" << endl;
//			Sleep(2000);
//			break;
//		case '4':
//			RadixSort(vec,0,vec.size()-1);
//			cout << "基数排序完成" << endl;
//			Sleep(2000);
//			break;
//		case '0':
//			return 0;
//		default:
//			cout << "未正确输入序号";
//			Sleep(2000);
//			break;
//		}
//	}
//	
//}