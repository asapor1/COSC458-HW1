#include <stdio.h>
#include <limits.h>

int main() {
	int a = INT_MAX - 1;
	int b = 1;
	int sum;
	
	if (b > INT_MAX - a) {
		printf("Integer overflow!\n");
	} else {
		sum = a+b;
		printf("%d\n", sum);
	}
	return 0;
}
