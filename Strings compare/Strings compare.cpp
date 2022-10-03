#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int strings_compare(const char *a, const char *b)
{
	int i = 0;
	while (a[i] != '\0')
	{
		if (a[i] == b[i])
		{
			i++;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	char string1[] = "HelloWorld!", string2[] = "Hello World!";

	if (strings_compare(string1, string2)) // массив уже является как бы указателем на самого себя
		// поэтому не нужен амперсант для передачи адреса в функцию
	{
		printf_s("Strings are equal!\n");
	}
	else
	{
		printf_s("Strings are not equal!\n");
	}

	system("pause");
	return 0;
}