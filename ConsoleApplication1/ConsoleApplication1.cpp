#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void swap_elements(void *a, void *b, size_t size)
{	
	char* tmp; 
	tmp = (char*)malloc(size);
	memcpy(tmp, a, size);  
	memcpy(a, b, size);
	memcpy(b, tmp, size);
	free(tmp); // освобождает блок памяти (дает возможность его перезаписать)
}

int main()
{	
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	int array_size = 0;
	int a, b;
	double *array; // динамический массив

	printf_s("Введите размерность массива:\n");
	scanf_s("%d", &array_size);
	array = (double*)malloc(sizeof(double)*array_size); // тут в указатель 
	// записывается АДРЕС ячеек динамического массива

	printf_s("Ваш массив:\n");
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand() / 100;
		printf_s("%.1lf ", array[i]);
	}

	printf_s("\nТеперь укажите индексы элементов, которые хотите поменять местами:\n");
	scanf_s("%d %d", &a, &b);
	printf_s("\nВы меняете местами %0.1lf и %0.1lf\n", array[a], array[b]);
	
	swap_elements(&array[a], &array[b], sizeof(double));

	printf_s("\nВаш новый массив:\n");
	for (int i = 0; i < array_size; i++)
	{
		printf_s("%0.1lf ", array[i]);
	}

	system("pause");
	return 0;
}
