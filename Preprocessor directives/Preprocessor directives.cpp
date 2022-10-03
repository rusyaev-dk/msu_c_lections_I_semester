#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define Nmax 100
#define print(a) printf_s("\n %s = %d", #a, a)
#define max(a, b) ((a)>(b))?(a):(b)
#define concat(a, b) a##b

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int x = 8, y = 12, z = 15, max;
	print(x); print(y); print(z);
	print(concat(12, 12));

	max = max(x, y);
	print(max);


	system("pause");
	return 0;
}