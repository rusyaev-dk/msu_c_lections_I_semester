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

	char *name;
	name = "vasya"; // само имя вася в памяти является константой
	printf_s("Hello %s\n", name);

	name = "petya";
	printf_s("Hello %s", name);

	int i = 0;
	printf_s("\n\nВведите имя: ");
	name = (char*)malloc(sizeof(char) * 35);
	while (scanf_s("%c", &name[i]))
	{
		if ((name[i] > 64 && name[i] < 91) || (name[i] > 96 && name[i] < 123))
		{
			i++;
		}
		else
		{
			break;
		}
	}

	name[i] = '\0';
	printf_s("\nHello %s!\n\n", name);

	system("pause");
	return 0;
}