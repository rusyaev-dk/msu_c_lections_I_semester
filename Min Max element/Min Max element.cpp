#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double *find_min(double *a, int size)
{
	double *temp = &a[0];
	for (int i = 0; i < size; i++)
	{
		if (*temp > a[i])
		{
			temp = &a[i];
		}
	}
	return temp;
}

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int array_size = 0;
	double *arr;

	scanf_s("%d", &array_size);
	arr = (double*)malloc(sizeof(double)*array_size);
	

	printf_s("Ваш массив:\n");
	for (int i = 0; i < array_size; i++)
	{
		arr[i] = rand() % 100 - 50;
		printf_s("%.1lf ", arr[i]);
	}

	printf_s("\nНаименьший элемент массива: %.1lf\n", *find_min(arr, array_size));

	system("pause");
	return 0;
}