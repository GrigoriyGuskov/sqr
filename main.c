#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "sqr.h"

int main(){
	printf("Press 's' if you wanna solve square equation\n");
	printf("Press 't' if you wanna start tests\n");
	printf("Press 'q' if you wanna quit the program\n");
	int answer;
	while(answer != EOF){
		answer = getchar();
		switch(answer) {
			case '\n':
				break;
			case 'q':
				printf("The end of program\n");
				return 0;
			case 's':
				Solver();
				return 0;
			case 't':
				UnitTest();
				return 0;
			default:
				printf("Wrong answer. Try again\n");
			break;
		}
	}
	return 0;
}