#include <stdio.h>
int main() {
	int a, b, c, d = 1, f1 = 1, f2 = 0;
	printf("please enter the number of n\n");
	scanf("%d",&a);
	for (; d <= a; d++) {
		b = f1 + f2;
		f1 = f2;
		f2 = b;
		printf("%d", b);
		return 0;
	}
}