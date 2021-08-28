
#include "sqr.h"

const double ACCURACY = 0.0001;

int Solver (){
	
	double a = NAN, b = NAN, c = NAN;
	
	Input(&a, &b, &c);
	
	double x1 = NAN, x2 = NAN;

	int nRoots = SolveSquare(a, b, c, &x1, &x2);
	
	switch (nRoots){ //!
		case 0:
			printf("No roots\n");
			break;
			
		case 1:
			printf("X = %lg\n", x1);
			break;
		case 2: //!
			printf("X1 = %lg, X2 = %lg\n", x1, x2);
			break;
		case INF_ROOTS:
			printf("Infinite number of roots. X can be any number\n");
			break;
		default:
			printf("error: nRoots = %d\n", nRoots);
			return 1;
	}
	return 0;
}

int isZero (double val){
	assert(isfinite(val)); //!

	return (fabs(val) < ACCURACY);
}

int isEqual (double val1, double val2){
	assert(isfinite(val1)); //!
	assert(isfinite(val2));
	
	return isZero(val1 - val2);
}

int SolveLinear (double A, double B, double* X){
	assert(isfinite(A));
	assert(isfinite(B));
	
	assert(X != NULL);
	
	if (isZero(A))
		return(isZero(B))? INF_ROOTS : 0; //!
	else {	
		*X = -B/A;
		return 1;
	}
}

int SolveSquare (double A, double B, double C, double* X1, double* X2){
	assert(isfinite(A));
	assert(isfinite(B));
	assert(isfinite(C));
	
	assert(X1 != NULL);
	assert(X2 != NULL);
	assert(X1 != X2);
	
	if (isZero(A)){
		return SolveLinear(B, C, X1); //!
	} else {
		double D = B*B - 4*A*C;

		if (isZero(D)){
			*X1 = -B/(2*A);
			*X2 = *X1;
			return 1;
		} else if (D < -ACCURACY) {
			return 0;
		} else {
			double square_root_D = sqrt(D);
			*X1 = (-B + square_root_D) / (2*A);
			*X2 = (-B - square_root_D) / (2*A);
			return 2;
		}
		
	}
}

