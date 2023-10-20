#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Research:
//How to make and print a matrix: https://www.javatpoint.com/how-to-add-matrix-in-c
//Add matrices in C: https://www.programiz.com/c-programming/examples/add-matrix
int main() {
int n,m;
char aos;
printf("N: ");
scanf("%d", &n);
printf("M: ");
scanf("%d", &m);

printf("You entered %d and %d.\n", n, m);

printf("Would you like to add or subtract? a for add, s for subtract: ");
scanf(" %c", &aos);

int matrix1[n][m];
int matrix2[n][m];
int result[n][m];

//Put values in matrices
for (int i = 0; i < n; i++) {
	for (int f = 0; f < m; f++) {
		int random = rand() % 10 + 1;		
		matrix1[i][f] = i + 2 * random;
		matrix2[i][f] = i + f * f + random;
		if (aos == 'a') {
			result[i][f] = matrix1[i][f] + matrix2[i][f];
		}
		if (aos == 's') {
			result[i][f] = matrix1[i][f] - matrix2[i][f];
		}
	}
}

printf("\n Matrix 1\n");
for (int i = 0; i < n; i++) {
	for (int f = 0; f < m; f++) {
		printf("%d ", matrix1[i][f]);
	}
}
printf("\n Matrix 2\n");
for (int i = 0; i < n; i++) {
	for (int f = 0; f < m; f++) {
		printf("%d ", matrix2[i][f]);
	}
}
if (aos == 'a') {
printf("\n Matrix 1 + Matrix 2\n");
}
if (aos == 's') {
printf("\n Matrix 1 - Matrix 2\n");
}
for (int i = 0; i < n; i++) {
	for (int f = 0; f < m; f++) {
		printf("%d ", result[i][f]);
	}
}
printf("\n");

return (0);
}
