////main.cpp
//#include "basis.h"
//#include "SimpleLinkList.h"
//
//int main()
//{
//	SimpleLinkList<int>* list = new SimpleLinkList<int>();
//	char median;
//	while (1)
//	{
//		system("cls");
//		cout << "����������Ҫִ�еĲ�����Ӧ�ı��:" << endl
//			<< "1.��ȡ��ǰ������" << endl
//			<< "2.����Ԫ�ؽڵ�" << endl
//			<< "3.ɾ��Ԫ�ؽڵ�" << endl
//			<< "4.��ʾ��ǰ����" << endl
//			<< "5.��������" << endl<< endl;
//		median=_getch();
//		switch (median)
//		{
//		case '1':
//			cout<<"��ǰ������Ϊ:" << list->Length()<<endl;
//			cout << "�����������" << endl;
//			median = _getch();
//			break;
//		case '2':
//			int position,data;
//			cout << "��������Ҫ����Ľڵ�λ��:";
//			cin >> position;
//			cout << endl<<"��������Ҫ����ڵ������:";
//			cin >> data;
//			cout << endl;
//			list->Insert(position,data);
//			cout <<"����������"<<endl << "�����������" << endl;
//			median = _getch();
//			break;
//		case '3':
//			int p;
//			cout << "��������Ҫɾ���Ľڵ�λ��:";
//			cin >> position;
//			cout << endl;
//			list->Delete(position, p);
//			cout <<"ɾ���������"<<endl << "�����������" << endl;
//			median = _getch();
//			break;
//		case '4':
//			list->Output();
//			cout << "�����������" << endl;
//			median = _getch();
//			break;
//		case '5':
//			goto exit;
//			break;
//		default:
//			cout << "δ��ȷ���룡" << endl;
//			break;
//		}
//	}
//exit:
//
//	return 0;
//}