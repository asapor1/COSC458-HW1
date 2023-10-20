#include <stdio.h>
#include <limits.h>

int main() {
	int a = 2147483648;
	int b = 1;
	int sum = a + b;
	printf("%d\n", sum);
	return 0;
}
