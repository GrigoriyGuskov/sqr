#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


#define INF_ROOTS 42

const double ACCURACY = 0.0001;

//---------SolveStatus----------
#define WR_nROOTS -5
#define WR_X1 -1
#define WR_X2 -2
//------------------------------

struct coeffs {
	double a;
	double b;
	double c;
	double x1;
	double x2;
	int nRoots;
	int nRoots_ref;
	double x1_ref;
	double x2_ref;
};


int isEqual (double val1, double val2);
int isZero (double val);

int SolveLinear (double A, double B, double* X);
int SolveSquare (double A, double B, double C, double* X1, double* X2);

int SolveSquareTest (int counter, struct coeffs DATA);

void AscendingSort (double* val1, double* val2);	//Сортировка по возрастанию. После этой функции val2 всегда больше val1.
													//Также если только одно число не NAN оно ставится на первое место

void PrintInfo(struct coeffs DATA);

int main (){
	struct coeffs Data[] = {
	{1, 5, -6, NAN, NAN, 0, 2, 1 , -6},
	{0.00009, 5, 18, NAN, NAN, 0, 1, -3.6 , NAN},
	{1, 0, -2, NAN, NAN, 0, 2, sqrt(2) , -sqrt(2)},
	};
	
	int N = sizeof(Data)/sizeof(Data[0]);
	int failed = 0;
	for (int i = 0; i < N; i++) {
		int status = SolveSquareTest(i, Data[i]);
		if(status){
			failed++;
			switch (status){
				case WR_nROOTS:
				printf("Wrong number of roots\n");
					break;
				case WR_X1:
					printf("Wrong X1\n");
					break;
				case WR_X2:
					printf("Wrong X2\n");
					break;
				default:
					printf ("error: TestStatus = %d\n", status);
					return 1;
			}
		}
	}
	printf("Total tests: %d\n", N);
	printf("Failed: %d\n", failed);
	printf("Succeed: %d\n",N - failed);
	return 0;
}

void AscendingSort (double* val1, double* val2){
	if (*val1 > *val2 || isnan(*val1)){
		double var = *val1;
		*val1 = *val2;
		*val2 = var;
	}
}

void PrintInfo(struct coeffs DATA){
	printf("A = %lg\n", DATA.a);
	printf("B = %lg\n", DATA.b);
	printf("C = %lg\n", DATA.c);
	printf("nRoots = %d\n", DATA.nRoots);
	printf("nRoots_REF = %d\n", DATA.nRoots_ref);
	switch (DATA.nRoots_ref) {
		case 2:
			printf("X1 = %lg ", DATA.x1);
			printf("X2 = %lg\n", DATA.x2);
			printf("X1_REF = %lg ", DATA.x1_ref);
			printf("X2_REF = %lg\n", DATA.x2_ref);
			break;
		case 1:
			printf("X1 = %lg\n", DATA.x1);
			printf("X1_REF = %lg\n", DATA.x1_ref);
			break;
	}
}

int isZero (double val){
	assert(isfinite(val));

	return (fabs(val) < ACCURACY);
}

int isEqual (double val1, double val2){
	assert(isfinite(val1));
	assert(isfinite(val2));
	
	return isZero(val1 - val2);
}

int SolveLinear (double A, double B, double* X){
	assert(isfinite(A));
	assert(isfinite(B));
	
	assert(X != NULL);
	
	if (isZero(A))
		return(isZero(B))? INF_ROOTS : 0;
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
		return SolveLinear(B, C, X1);
	} else {
		double D = B*B - 4*A*C;

		if (isZero(D)){
			*X1 = -B/(2*A);
			return 1;
		} else if (D < 0){
			return 0;
		} else {
			double square_root_D = sqrt(D);
			*X1 = (-B + square_root_D)/(2*A);
			*X2 = (-B - square_root_D)/(2*A);
			return 2;
		}
		
	}
}

int SolveSquareTest (int counter, struct coeffs DATA){
	DATA.nRoots = SolveSquare(DATA.a, DATA.b, DATA.c, &DATA.x1, &DATA.x2);
	
	AscendingSort(&DATA.x1, &DATA.x2);
	AscendingSort(&DATA.x1_ref, &DATA.x2_ref);
	
	if (DATA.nRoots_ref != DATA.nRoots){
		printf("Test #%d is failed\n", counter);
		PrintInfo(DATA);
		return WR_nROOTS;
	} else {
		switch (DATA.nRoots){
			case 1:
				if (!isEqual(DATA.x1, DATA.x1_ref)){
					printf("Test #%d is failed\n", counter);
					PrintInfo(DATA);
					return WR_X1;
				}
				break;
			case 2:
				if (!isEqual(DATA.x1, DATA.x1_ref)){
					printf("Test #%d is failed\n", counter);
					PrintInfo(DATA);
					return WR_X1;
				} else if (!isEqual(DATA.x2, DATA.x2_ref)){
					printf("Test #%d is failed\n", counter);
					PrintInfo(DATA);
					return WR_X2;
				}
				break;
			default:
				break;
		}
	}
	return 0;
}




