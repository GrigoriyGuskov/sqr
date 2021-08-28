
#include "sqr.h"

int main (){
	
	printf("Press 's' if you wanna solve square equation\n");
	printf("Press 't' if you wanna start tests\n");
	printf("Press 'q' if you wanna quit the program\n");
	
	int answer = 0;
	
	while (answer != 'q') {	
		answer = getchar();
		switch (answer) {
			case '\n':
				printf("Press 's' if you wanna solve square equation\n");
				printf("Press 't' if you wanna start tests\n");
				printf("Press 'q' if you wanna quit the program\n");
				break;
				
			case 'q':
				printf("The end of program\n");
				return 0;
				
			case 's':
				Solver();
				break;
				
			case 't':
				UnitTest();
				break;
				
			default:
				printf("Wrong answer. Try again\n");
				break;
		}
		printf("\n");
	}
	
	return 0;
}