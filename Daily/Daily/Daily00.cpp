//#include <iostream>
//
//using namespace std;
//
//void shellsort(int* arr, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap /= 2;
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tem = arr[end + gap];
//			while (end >= 0)
//			{
//				if (tem < arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = tem; 
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 3,5,4,2,9,1 };
//	
//	shellsort(arr, sizeof(arr)/sizeof(arr[0]));
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << arr[i] << " ";
//	}
//}
//
////int main()
////{
////    int n, m, k, t,median;
////    int x = 0, y = 0;
////    cin >> n >> m >> k >> t;
////    int*** a = new int**[n];
////    for (int i = 0; i < n; i++)
////    {
////       a[i] = new int*[m];
////       for (int j = 0; j < m; j++)
////           a[i][j] = new int[3];
////    }
////    for (int i = 0; i < n; i++)
////        for (int j = 0; j < m; j++)
////            for (int k = 0; k < 3; k++)
////                a[i][j][k] = 0;
////    for (int i = 0; i < n; i++)
////        for (int j = 0; j < m; j++)
////            cin >> a[i][j][0]>>a[i][j][1];
////    for (int i = 0; i < t; i++)
////    {
////        cin >> median;
////        switch (median)
////        {
////        case '1':
////            y--;
////            break;
////        case '2':
////            y++;
////            break;
////        case '3':
////            
////            break;
////        case '4':
////
////            break;
////        }
////    }
////}