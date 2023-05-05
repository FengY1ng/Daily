#include <iostream>

using namespace std;
//第五题：编写将一个整数N转换成字符串的递归函数。例如输入345，应输出字符串“345”。N的位数不确定，可以是任意位数的整数。
void str(int N) {
	if (N >= 10)
		str(N / 10);
	cout << N % 10;
}

int main() {
	int N;
	cin >> N;
	str(N);
	return 0;
}

//#include <stdio.h>
//int main() {
//	int a, b, c, d = 1, f1 = 1, f2 = 0;
//	printf("please enter the number of n\n");
//	scanf("%d",&a);
//	for (; d <= a; d++) {
//		b = f1 + f2;
//		f1 = f2;
//		f2 = b;
//		printf("%d", b);
//		return 0;
//	}
//}