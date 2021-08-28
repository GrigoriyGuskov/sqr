
#include "sqr.h"

void Input (double* A, double* B, double* C){
	//assert?
	int answer = 'n';
	
	while(answer != 'y'){
		int res = 0;
		while(res != 1){ /////////!!!!!!!!!
			printf("Enter a : ");
			res = scanf("%lg", A);
			if (res != 1)
				printf("It's not a number. Try again\n");
			ClearBuf();
		}
		res = 0;
		while(res != 1){
			printf("Enter b : ");
			res = scanf("%lg", B);
			if (res != 1)
				printf("It's not a number. Try again\n");
			ClearBuf();
		}
		res = 0;
		while(res != 1){
			printf("Enter c : ");
			res = scanf("%lg", C);
			if (res != 1)
				printf("It's not a number. Try again\n");
			ClearBuf();
		}
		
		printf("Is this your equation?\n\n");
		printf("(%lg)X^2 + (%lg)X + (%lg) = 0\n\n", *A, *B, *C);
		printf("y/n?\n");
		
		answer = getchar();
	}
}

void ClearBuf (){
	while (getchar() != '\n');
}