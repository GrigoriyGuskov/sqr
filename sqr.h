
#define INF_ROOTS 42



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

int Solver();
int UnitTest();

void Input();

int isEqual (double val1, double val2);
int isZero (double val);

int SolveLinear (double A, double B, double* X);
int SolveSquare (double A, double B, double C, double* X1, double* X2);

int SolveSquareTest (int counter, struct coeffs DATA);

void AscendingSort (double* val1, double* val2);	//Сортировка по возрастанию. После этой функции val2 всегда больше val1.
													//Также если только одно число не NAN оно ставится на первое место

void PrintInfo (struct coeffs DATA);

void ClearBuf();