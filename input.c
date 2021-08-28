#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "sqr.h"


void Input (double* A, double* B, double* C){
	int answer = 'n';
	int res = 0;
	while(answer != 'y'){
		res = 0;
		while(res != 1){
			printf("Enter a : ");
			res = scanf("%lg", A);
			//printf("%d", res);
			ClearBuf();
		}
		res = 0;
		while(res != 1){
			printf("Enter b : ");
			res = scanf("%lg", B);
			//printf("%d", res);
			ClearBuf();
		}
		res = 0;
		while(res != 1){
			printf("Enter c : ");
			res = scanf("%lg", C);
			//printf("%d", res);
			ClearBuf();
		}
		printf("Is this your equation?\n");
		printf("(%lg)X^2 + (%lg)X + (%lg) = 0\n", *A, *B, *C);
		printf("y/n?\n");
		answer = getchar();
	}
}

void ClearBuf (){
	int letter = getchar();
	while(letter != '\n' ){
		letter = getchar();
	}
}