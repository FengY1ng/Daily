//#include "basis.h"
//#include "Serach.h"
//
//
//
//int main()
//{
//	vector<Type> vec;
//	Type median;
//	cout << "��˳����������Ԫ��(���������ַ��������˳�)" << endl;
//	while (scanf_s("%d", &median))
//		vec.push_back(median);
//	cin.ignore(vec.size()+1, '\n');
//	system("cls");
//	while (1)
//	{
//		cout << "��������Ҫ���еĲ�����Ӧ�����" << endl
//			<< "1����ʾ��ǰ��̬��" << endl
//			<< "2���Ե�ǰ�����˳�����" << endl
//			<< "3���Ե�ǰ����ж��ֲ���" << endl
//			<< "0���˳�����" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//			cout << "��ǰ��ĽṹΪ:";
//			for (int i = 0; i < vec.size(); i++)
//			{
//				cout << vec.at(i) << " ";
//			}
//			cout << endl;
//			break;
//		case '2':
//			cout << "��������Ҫ���ҵ�����:";
//			cin >> median;
//			cout << "���ҵ������ڱ�ĵ�" << 4 << "��λ��"<<endl;
//			break;
//		case '3':
//			cout << "��������Ҫ���ҵ�����:";
//			cin >> median;
//			cout << "���ҵ������ڱ�ĵ�" << 2 << "��λ��"<<endl;
//			break;
//		case '0':
//			return 0;
//		default:
//			cout << "δ��ȷ����!" << endl;
//			break;
//		}
//	}
//
//}