////BinartSortTreeMain.cpp
//#include "BinarySortTree.h"
//#include "Myusers.h"
//#include "basis.h"
//
//typedef int ElemType;
//typedef int KeyType;
//
//int main()
//{
//	ElemType e;
//	int median,k=1;
//	BinarySortTree<ElemType, KeyType>* tree = new BinarySortTree<ElemType, KeyType>();
//	InsertRoot(tree);
//	cout << "���������������ɣ�" << endl;
//	Sleep(2000);
//	while (1)
//	{
//		system("cls");
//		cout << "��������Ҫ���еĲ�����Ӧ�����" << endl
//			<< "1����ʾ��ǰ������" << endl
//			<< "2����ǰ����������ڵ�" << endl
//			<< "3�����ҵ�ǰ���������" << endl
//			<< "4��ǰ�����������" << endl
//			<< "5���������������" << endl
//			<< "6���������������" << endl
//			<< "7��ɾ��������ĳһ���" << endl
//			<< "0���˳�����" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//			tree->DisplayBTWithTreeShape(*tree);
//			Sleep(2000);
//			break;
//		case '2':
//			k = 1;
//			while (k != '0')
//			{
//				cout << "������Ԫ��:";
//				cin >> e;
//				if (tree->Insert(e))
//				{
//					cout << "����ɹ�" << endl;
//				}
//				else
//				{
//					cout << "����ʧ��!" << endl;
//				}
//				cout << "�Ƿ�Ҫ�������룿���˳��밴��0�����������밴�������" << endl;
//				k = _getch();
//			}
//			break;
//		case '3':
//			BinarySortTreeNode<ElemType>* f;
//			cout << "������Ҫ���ҵ�Ԫ��:";
//			cin >> e;
//			f = tree->Search(e);
//			cout << endl << "���ҵ�Ԫ��" << endl;
//			Sleep(2000);
//			break;
//		case '4':
//			cout << "ǰ��������:";
//			tree->PreOrder();
//			Sleep(2000);
//			break;
//		case '5':
//			cout << "����������:";
//			tree->InOrder();
//			Sleep(2000);
//			break;
//		case '6':
//			cout << "����������:";
//			tree->PostOrder();
//			Sleep(2000);
//			break;
//		case '7':
//			cout << "��������Ҫɾ����Ԫ��:";
//			cin >> e;
//			if (tree->Delete(e))
//			{
//				cout << endl << "ɾ���ɹ�" << endl;
//			}
//			else
//			{
//				cout << endl << "ɾ��ʧ��!" << endl;
//			}
//			Sleep(2000);
//			break;
//		case '0':
//			return 0;
//		}
//	}
//}