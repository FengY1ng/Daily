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
//		cout << "请输入您想要执行的操作对应的编号:" << endl
//			<< "1.获取当前链表长度" << endl
//			<< "2.插入元素节点" << endl
//			<< "3.删除元素节点" << endl
//			<< "4.显示当前链表" << endl
//			<< "5.结束程序" << endl<< endl;
//		median=_getch();
//		switch (median)
//		{
//		case '1':
//			cout<<"当前链表长度为:" << list->Length()<<endl;
//			cout << "按任意键继续" << endl;
//			median = _getch();
//			break;
//		case '2':
//			int position,data;
//			cout << "请输入想要插入的节点位置:";
//			cin >> position;
//			cout << endl<<"请输入想要插入节点的数据:";
//			cin >> data;
//			cout << endl;
//			list->Insert(position,data);
//			cout <<"插入操作完成"<<endl << "按任意键继续" << endl;
//			median = _getch();
//			break;
//		case '3':
//			int p;
//			cout << "请输入想要删除的节点位置:";
//			cin >> position;
//			cout << endl;
//			list->Delete(position, p);
//			cout <<"删除操作完成"<<endl << "按任意键继续" << endl;
//			median = _getch();
//			break;
//		case '4':
//			list->Output();
//			cout << "按任意键继续" << endl;
//			median = _getch();
//			break;
//		case '5':
//			goto exit;
//			break;
//		default:
//			cout << "未正确输入！" << endl;
//			break;
//		}
//	}
//exit:
//
//	return 0;
//}