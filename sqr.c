#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define a coef[0]
#define b coef[1]
#define c coef[2]

typedef double type;

int main (){

	type coef[3] = {0.0};
	type D = 0, X1 = 0, X2 = 0;

	scanf ("%lf%lf%lf", &a, &b, &c);

	int nuli = 0;

	for (int i = 0; i < 3; i++){
		if (coef[i] == 0)
			nuli++;
	}
	
	switch (nuli){
	case 3:
		printf("X любой\n");
		break;
	case 2:
		if (c)
			printf("Нет корней\n");
		else
			printf ("X = 0\n");
		break;
	case 1:
		if (a == 0)
			printf ("X = %.4lf\n", (-c/b) );
		else if (c == 0)
			printf ("X1 = 0\nX2 = %.4lf\n", (-b/a) );
		else if (b == 0){
			X1 = sqrt(-c/a);
			X2 = -sqrt(-c/a);
			printf ("X1 = %.4lf\nX2 = %.4lf\n", X1, X2);
		}
			break;
	case 0:
		D = b*b - 4*a*c;
		if (D < 0)
			printf("Нет корней\n");
		else if (D == 0)
			printf ("X = %.4lf\n", (-b/(2*a)) );
		else {
			X1 = (-b + sqrt(D))/(2*a);
			X2 = (-b - sqrt(D))/(2*a);
			printf ("X1 = %.4lf\nX2 = %.4lf\n", X1, X2);
		}
		break;
	default:
		printf ("some error\n");
		exit(1);
	}

	return 0;
}