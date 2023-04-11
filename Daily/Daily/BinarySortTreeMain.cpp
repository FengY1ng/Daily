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
//	cout << "二叉查找树构建完成！" << endl;
//	Sleep(2000);
//	while (1)
//	{
//		system("cls");
//		cout << "请输入想要进行的操作对应的序号" << endl
//			<< "1、显示当前二叉树" << endl
//			<< "2、向当前二叉树插入节点" << endl
//			<< "3、查找当前二叉查找树" << endl
//			<< "4、前序遍历二叉树" << endl
//			<< "5、中序遍历二叉树" << endl
//			<< "6、后序遍历二叉树" << endl
//			<< "7、删除二叉树某一结点" << endl
//			<< "0、退出程序" << endl;
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
//				cout << "请输入元素:";
//				cin >> e;
//				if (tree->Insert(e))
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
//		case '3':
//			BinarySortTreeNode<ElemType>* f;
//			cout << "请输入要查找的元素:";
//			cin >> e;
//			f = tree->Search(e);
//			cout << endl << "已找到元素" << endl;
//			Sleep(2000);
//			break;
//		case '4':
//			cout << "前序遍历结果:";
//			tree->PreOrder();
//			Sleep(2000);
//			break;
//		case '5':
//			cout << "中序遍历结果:";
//			tree->InOrder();
//			Sleep(2000);
//			break;
//		case '6':
//			cout << "后序遍历结果:";
//			tree->PostOrder();
//			Sleep(2000);
//			break;
//		case '7':
//			cout << "请输入想要删除的元素:";
//			cin >> e;
//			if (tree->Delete(e))
//			{
//				cout << endl << "删除成功" << endl;
//			}
//			else
//			{
//				cout << endl << "删除失败!" << endl;
//			}
//			Sleep(2000);
//			break;
//		case '0':
//			return 0;
//		}
//	}
//}