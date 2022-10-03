#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double find_arith_m(int quantity, ...)
{
	int *elemPtr = (&quantity)+1; // �� ���� �� ��� �� ������ �������� �� +8 ����
	// �� ���� � ���������� � (� �� ������)
	
	double *elemPtr_d = (double*)elemPtr; // �������� ������� ��������� � ���� ����
	double sum = 0;

	for (int i = 0; i < quantity; i++)
	{
		sum += *elemPtr_d;
		elemPtr_d++; // ������������� �� ������� ������ (b, c...)
	}

	return sum / quantity;
}

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	double a = 2.5, b = 7.3, c = 3.9;

	printf_s("������� ��������������: %.2lf\n", find_arith_m(3, a, b, c)); // ~4.57


	system("pause");
	return 0;
}
