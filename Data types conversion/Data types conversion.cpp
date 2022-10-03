#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int i = 30000; double dbl = i; float flt = dbl;
	printf_s("dbl = %lf\n", dbl); // 30000.000
	printf_s("flt = %f\n", flt); // 30000.000
	dbl = 0.123456789;
	printf_s("dbl = %.9lf\n", dbl); // 0.123456789
	flt = dbl;
	printf_s("flt = %.9f\n", flt); // 0.123456781 (1 - как бы мусор уже)
	i = dbl;
	printf_s("i = %d\n\n", i); // i = 0

	i = 30000;
	char c = i;
	printf_s("c = %d\n", (int)c); // c = 48 30000 % 256 = 48
	printf_s("c = %d\n", c); // c = 48
	printf_s("c = %c\n", c); // c = 0 (48 - код нуля)

	printf_s("\n\n---------------------\n\n");

	i = 3;
	c = i;
	printf_s("c = %d\n", c); // c = 3

	char symbol = 'a';
	printf_s("symbol = %c or %d\n", symbol, symbol); // a или 97 (код буквы а)

	flt = 14 / 3;
	printf_s("flt = %f\n", flt);
	flt = (float(14)) / 3;
	printf_s("flt = %f\n", flt);

	system("pause");
	return 0;
}