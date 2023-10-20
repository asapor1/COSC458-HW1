#include <stdio.h>

//Research:
//File input and output https://www.programiz.com/c-programming/c-file-input-output
// Scan from file: https://www.geeksforgeeks.org/scanf-and-fscanf-in-c/
// Print array in C backwards: https://www.tutorialspoint.com/learn_c_by_examples/print_reverse_array_in_c.htm

int main() {
	FILE *fptr;
	int array[300];
	int i = 0;

	fptr = fopen("/home/seed/Desktop/ints.txt", "r");

	if (fptr == NULL) {
		printf("Can't open file.\n");
		return 1;
	}

	//Read ints from file and put into array
	while (fscanf(fptr, "%d", &array[i]) == 1 && i < 300) 	
	{
		i++;
	}

	//Print ints
	for (int f = i - 1; f >= 0; f--) {
		printf("%d ", array[f]);
	}
	printf("\n");

	//Close file!
	fclose(fptr);

	return 0;
}
