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
	int *p1 = &x; // хранит адрес переменной х
	int **p2 = &p1; // хранит адрес переменной х

	y = **p2; // то же, что y=*(*p2)=*p1=x

	int z = 5;

	int *pi = &z; // хранит адрес переменной z
	printf_s("%d", *pi); // 5
	int **ppi = &pi; // хранит адрес переменной pi
	int *pi2 = *ppi; // хранит значение указателя pi, то есть адрес переменной z



	system("pause");
	return 0;
}