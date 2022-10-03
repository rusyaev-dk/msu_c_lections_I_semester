#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double sum(double a, double b)
{
	return a + b;
}

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	printf_s("5.6 + 5.6 = %.1lf\n", sum(5.6, 5.6));
	printf_s("5 + 5 = %d\n", sum(5, 5));

	system("pause");
	return 0;
}