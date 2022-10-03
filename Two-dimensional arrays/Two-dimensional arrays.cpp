#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int arr[3][3], i, j; int *arrPtr = &arr[0][0];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			arrPtr[i * 3 + j] = rand() % 100 - 50; // эквивалентно arr[i][j]
			printf_s("%5d", arr[i][j]);
		}
		printf_s("\n");
	}

	system("pause");
	return 0;
}
