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
//	cout << "�Ƿ�Ҫ�������飿�����¡�1���Թ��������¡�0����ʹ��Ĭ�����飩";
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
//		cout << "��������Ҫ���еĲ�����Ӧ�����" << endl
//			<< "1����ʾ��ǰ����" << endl
//			<< "2����������ж�����" << endl
//			<< "3����������й鲢����" << endl
//			<< "4����������л�������" << endl
//			<< "0���˳�����" << endl;
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
//			cout << "���������" << endl;
//			Sleep(2000);
//			break;
//		case '3':
//			SimpleMergeSort(vec);
//			cout << "�鲢�������" << endl;
//			Sleep(2000);
//			break;
//		case '4':
//			RadixSort(vec,0,vec.size()-1);
//			cout << "�����������" << endl;
//			Sleep(2000);
//			break;
//		case '0':
//			return 0;
//		default:
//			cout << "δ��ȷ�������";
//			Sleep(2000);
//			break;
//		}
//	}
//	
//}