#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double find_arith_m(int quantity, ...)
{
	int *elemPtr = (&quantity)+1; // то есть мы уже по пам€ти попадаем на +8 байт
	// то есть в переменную а (в ее пам€ть)
	
	double *elemPtr_d = (double*)elemPtr; // приводим интовый указатель к типу дабл
	double sum = 0;

	for (int i = 0; i < quantity; i++)
	{
		sum += *elemPtr_d;
		elemPtr_d++; // передвигаемс€ по €чейкам пам€ти (b, c...)
	}

	return sum / quantity;
}

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	double a = 2.5, b = 7.3, c = 3.9;

	printf_s("—реднее арифметическое: %.2lf\n", find_arith_m(3, a, b, c)); // ~4.57


	system("pause");
	return 0;
}
