#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double power(double a, int p = 2) //  p = 2 по умолчанию
{
	int temp = 1;

	for (int i = 0; i < p; i++)
	{
		temp *= a;
	}

	return temp;
}

double power_2(double a, double p = 2)
{	
	// в разработке...
	double temp1 = 1, temp2 = 1;
	int numerator = floor(p); // округление в меньшую сторону (получим числитель степени)
	double denomenator = p - numerator; // получим знаменатель

	printf_s("numerator = %d\n", numerator);
	printf_s("denomenator = %.1lf\n", denomenator);

	for (int i = 0; i < numerator; i++)
	{
		temp1 *= a;
	}

	temp2 = pow(a, denomenator);

	return temp1 + temp2;
}

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	printf_s("%.1lf\n", power_2(3, 2.7));

	system("pause");
	return 0;
}