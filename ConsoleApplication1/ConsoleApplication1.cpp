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
	free(tmp); // ����������� ���� ������ (���� ����������� ��� ������������)
}

int main()
{	
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	int array_size = 0;
	int a, b;
	double *array; // ������������ ������

	printf_s("������� ����������� �������:\n");
	scanf_s("%d", &array_size);
	array = (double*)malloc(sizeof(double)*array_size); // ��� � ��������� 
	// ������������ ����� ����� ������������� �������

	printf_s("��� ������:\n");
	for (int i = 0; i < array_size; i++)
	{
		array[i] = rand() / 100;
		printf_s("%.1lf ", array[i]);
	}

	printf_s("\n������ ������� ������� ���������, ������� ������ �������� �������:\n");
	scanf_s("%d %d", &a, &b);
	printf_s("\n�� ������� ������� %0.1lf � %0.1lf\n", array[a], array[b]);
	
	swap_elements(&array[a], &array[b], sizeof(double));

	printf_s("\n��� ����� ������:\n");
	for (int i = 0; i < array_size; i++)
	{
		printf_s("%0.1lf ", array[i]);
	}

	system("pause");
	return 0;
}
