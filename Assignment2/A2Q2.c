#include<stdio.h>

int main() {
	FILE *fptr;
	int max = 7;	
	float array[max];
	int i = 0;

	fptr = fopen("/home/seed/Desktop/float.txt", "r");
	if (fptr == NULL) {
		printf("Failed to open.\n");
		return 1;
	}

	while (fscanf(fptr, "%f", &array[i]) == 1 && i < max) {
		i++;
	}
	
	//Print out strictly lesser than neighbors
	for (i = 1; i < max - 1; i++) {
		if (array[i] < array[i - 1] && array[i] < array[i + 1]) {
			printf("%f ", array[i]);
		}
	}
	printf("\n");
	
	fclose(fptr);
	return 0;
}

