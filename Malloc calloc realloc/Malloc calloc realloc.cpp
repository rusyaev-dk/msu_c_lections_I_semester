#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int size = 6;
	int *q, *q1;
	q = (int*)malloc(sizeof(int)*size); // ���������� "������� ������"

	if (q)
	{
		for (int i = 0; i < size; i++)
		{
			printf_s("%2d", q[i]);
		}
	}

	printf_s("\n\n-----------------\n\n");

	q1 = (int*)calloc(size, sizeof(int));  // ���������� "������ ������" � ���� �����
	// ������ �������� - ������� ��� ����� ������, ������ - ������ ���� ����� ������

	if (q1)
	{
		for (int i = 0; i < size; i++)
		{
			printf_s("%4d", q1[i]);
		}
	}

	printf_s("\n\n-----------------\n\n");

	q1 = (int*)realloc(q1, sizeof(int) * 2); // �������� ������ ������ (��������� - �������� �����)
	// ������ �������� - ��������� �� �� ������, ������� �� ����� ����������������
	// ������ �������� - ��������������� ������ ������������������ ������

	if (q1)
	{
		for (int i = 0; i < size; i++)
		{
			printf_s("%4d", q1[i]);
		}
	}

	system("pause");
	return 0;
}
