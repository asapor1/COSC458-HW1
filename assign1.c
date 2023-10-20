//Craig Benjamin, Grace Wilson, Anthony Sapporito

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// * * TO COMPILE: Add '-lm' to the end, otherwise it'll throw an error * * //


/*
references:
 Reference #1 - https://math.libretexts.org/Courses/Community_College_of_Denver/MAT_1320_Finite_Mathematics/01%3A_Linear_Equations_and_Lines/1.01%p   3A_Solving_Linear_Equations_and_Inequalities
 Reference #2 - https://www.geeksforgeeks.org/c-quadratic-equation-root/
 Reference #3 - httpss://stackoverflow.com/questions/54073157/input-validation-for-integers-in-c#:~:text=Unfortunately%2C%20this%20can't%20be,followed%20by%20enter%20key%22)%3B
 Reference #4 - https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
 Reference #5 - https://www.programiz.com/c-programming/examples/factors-number
 Reference #6 - https://www.geeksforgeeks.org/program-decimal-binary-conversion/
*/

int main(){ 

	double a, b, c, d, e, f;
	double linearRoot, root1, root2, root3;
	double discriminant;
	int valA, valB;
	int gcd, number;
	int numberOfFactors = 0, numberOfNonFactors = 0;
	int factors[100];
	int nonFactors[100];	
	int arr[100];
	int decimal;

	int g, h;
	float divisor, x;
	int w, y, p = 0;
		
//For the linear root
	printf("Enter your values a, b, and c for the linear equation ax + b = c:\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	linearRoot = (c-b) / a;
	
	if (a!=0){ //since a cannot be equal to zero and have a valid result -- Reference #1
		printf("The root is: %lf\n", linearRoot);
	}
	else{
		printf("The root cannot be determined\n");
	}

//For the quadratic roots
	printf("enter your values a, b, and c for the quadratic equation ax^2 + bx = c: \n");
	scanf("%lf %lf %lf", &d, &e, &f); // d, e, and f represent values a, b, and c respectively in the equation 
	discriminant = (e * e) - (4 * (d * f));
	int sqroot = sqrt(abs(discriminant));

	if (d !=0){ // d cannot be equal to zero	
	//make sure d is not zero
		if (discriminant == 0){
			root3 = (-e)/(2*d);
			printf("The root is %lf\n", root3);
		} else if (discriminant < 0) {
			root1 = ((-e)/(2*d)) + (((-e) + sqroot)/(2*d)); // Logic from Reference #2
			root2 = ((-e)/(2*d)) - (((-e) - sqroot)/(2*d));
			printf("Root 1 for the equation ax^2 + bx = c is: %lf\n", root1);
			printf("Root 2 for the equation ax^2 + bx = c is: %lf\n", root2);
		
		} else { //if discriminant > 0
			root1 = ((-e) + sqroot)/(2*d);
			root2 = ((-e) - sqroot)/(2*d);
			printf("Root 1 for the equation ax^2 + bx = c is: %lf\n", root1);
			printf("Root 2 for the equation ax^2 + bx = c is: %lf\n", root2);
		}
	} else { // if d == 0
		printf("cannot complete operation; a cannot be zero");	
	}

// Finding GCD of two integers
	// Input validation
	while (w == 0){
		printf("Enter two integers: \n");
	
	if ((scanf("%d %d", &valA, &valB) == 2)) { // validating the inputs -- Reference #3
		if ((valA > 0) && (valB > 0)) {
			printf("Valid input \n");			
			w = 1; // Exit loop; Valid integers
		} else {
			printf("Please enter a positive integer \n");
		}
		
	} else {
		while (getchar() != '\n'); // have to clear the input buffer, else the invalid input stays inside and causes infinite loop
		printf("Your input must only contain positive integers. Please try again: \n");	
	}

	}
	
	// Finding GCD using the Euclidian Algorithm
	if (valA > valB){
		g = valA;
		h = valB;
	} else {
		g = valB;
		h = valA;
	}
	
	while (g != 0) { // Implementation of the Euclidian Algorithm -- Reference #4 
		int gcd = g;
		g = h % g;
		h = gcd;
	}
	printf ("the gcd is: %d\n", h);

// Find the factors of a number
	printf("Enter a positive integer\n");
	scanf("%d", &number);
	for (int i = 1; i <= number; i++){
		if (number % i == 0){
			factors[numberOfFactors] = i;
			numberOfFactors++;
			//printf("This is a factor: %d\n", i); 	
		} else {
			nonFactors[numberOfNonFactors] = i;
			numberOfNonFactors++;
		}
	}

	printf("The factors are: \n ");
	for (int i = 0; i < numberOfFactors; i++){
		printf("%d", factors[i]);
		printf(",");	
	}
	
	printf("\nThe non factors are: \n");
	for (int k = 0; k < numberOfNonFactors; k++){
		printf("%d", nonFactors[k]);
		printf(",");	
	}

// - Converting Decimal to Binary
	while (p == 0){
		printf("Enter an integer to convert to Binary: \n");
		if (scanf("%d", &decimal) == 1) { 
			printf("Valid input \n");			
			p = 1;
		} else {
			while (getchar() != '\n'); 
			printf("Your input must only contain a integer. Please try again: \n");	
		}
	}

	int i = 0;
	while(decimal > 0) {
		int rem = decimal % 2;
		if(rem == 0){
			arr[i] = 0;
		} else { 
			arr[i] = 1; 
		}
		decimal = decimal / 2;
		i++;
	}
	
	for (int j = i - 1; j >= 0; j--){ // Printing the output in reverse order -- Reference #6 
		printf("the decimal number is: %d\n", arr[j]);
	}

	return 0;
}


