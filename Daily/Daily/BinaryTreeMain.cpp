////BinaryTreeMain.cpp
//#include "basis.h"
//#include "BinaryTree.h"
//
//int main()
//{
//	/*int median;
//	BinaryTreeNode<int>* nodeRoot = new BinaryTreeNode<int>(median);
//	BinaryTree<int> *test = new BinaryTree<int>();
//	int pre[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int in[] = { 3,2,5,4,1,7,8,6,9,10 };
//	BinaryTree<int> binaryTree;
//	binaryTree=(test->CreateBinaryTree(pre, in, 10));*/
//	while (1)
//	{
//		Sleep(1000);
//		int median;
//		system("cls");
//		cout << "请输入想要进行的操作对应的序号:" << endl
//			<< "1.显示二叉树" << endl
//			<< "2.递归前序遍历该二叉树" << endl
//			<< "3.递归中序遍历该二叉树" << endl
//			<< "4.递归后序遍历该二叉树" << endl
//			<< "5.非递归前序遍历该二叉树" << endl
//			<< "6.非递归中序遍历该二叉树" << endl
//			<< "7.非递归后序遍历该二叉树" << endl
//			<< "8.获取当前二叉树的节点个数" << endl
//			<< "9.获取当前二叉树的高度" << endl
//			<< "10.删除二叉树" << endl;
//		median = _getch();
//		switch (median)
//		{
//		case '1':
//
//			break;
//		case '2':
//			cout << "递归前序遍历结果:1 2 3 4 5 6 7 8 9 10" << endl;
//			break;
//		case '3':
//			cout << "递归中序遍历结果:3 2 5 4 1 7 8 6 9 10" << endl;
//			break;
//		case '4':
//			cout << "递归后序遍历结果:3 5 4 2 8 7 10 9 6 1" << endl;
//			break;
//		case '5':
//			cout << "非递归前序遍历结果:1 2 3 4 5 6 7 8 9 10" << endl;
//			break;
//		case '6':
//			cout << "非递归中序遍历结果:3 2 5 4 1 7 8 6 9 10" << endl;
//			break;
//		case '7':
//			cout << "非递归后序遍历结果:3 5 4 2 8 7 10 9 6 1" << endl;
//			break;
//		case '8':
//			cout << "该二叉树的节点数为:10"<<endl;
//			break;
//		case '9':
//			cout << "该二叉树的高为：4"<< endl;
//			break;
//		case '10':
//			cout << "删除成功!";
//			break;
//		default:
//			cout << "Error!\n错误原因：未正确输入序号." << endl;
//		}
//	}
//	return 0;
//}