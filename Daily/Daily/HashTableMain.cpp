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
//	cout << "�������ϣ�������:";
//	cin >> size;
//	cout << endl << "�������ϣ��ĸ�ֵ����:";
//	cin >> divisor;
//	cout << endl;
//	HashTable<ElemType, KeyType>* hash = new HashTable<ElemType, KeyType>(size, divisor);
//	while (1)
//	{
//		system("cls");
//		cout << "��������Ҫ���еĲ�����Ӧ�����" << endl
//			<< "1�����ϣ�������Ԫ��" << endl
//			<< "2���ڸù�ϣ���в���Ԫ��" << endl
//			<< "0���˳�����" << endl;
//		median = _getch();
//		switch (median)
//		{
//			
//
//		case '1':
//			k = 1;
//			while (k != '0')
//			{
//				cout << "������Ԫ��:";
//				cin >> e;
//				if (hash->Insert(e))
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
//		case '2':
//			ElemType elem;
//			KeyType key;
//			cout << "��������Ҫ���ҵ�Ԫ�صļ�ֵ";
//			cin >> key;
//			hash->Search(key, elem);
//			cout << endl << "��������Ԫ��Ϊ:" << elem << endl;
//			Sleep(2000);
//			break;
//		case '0':
//			return 0;
//		}
//	}
//}