#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>



int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int x = 10, y = 20;
	int *p1 = &x; // ������ ����� ���������� �
	int **p2 = &p1; // ������ ����� ���������� �

	y = **p2; // �� ��, ��� y=*(*p2)=*p1=x

	int z = 5;

	int *pi = &z; // ������ ����� ���������� z
	printf_s("%d", *pi); // 5
	int **ppi = &pi; // ������ ����� ���������� pi
	int *pi2 = *ppi; // ������ �������� ��������� pi, �� ���� ����� ���������� z



	system("pause");
	return 0;
}