#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char username[10];

int main(int argc, char* argv[]) 
{

	FILE *fin, *fout;
	int err1, err2;

	printf_s("Program started\n");
	
	// первое занятие по файлам:
	/*
	if (argc == 3)
	{
		err = fopen_s(&fin, argv[1], "r");
		if (err == 0)
		{
			fgets(username, 10, fin); // name - буфер, 10 - сколько, fin - откуда
			printf_s("Username: %s\n", username);
		}
		else
		{
			printf_s("File %s cannot be opened!\n", argv[1]);
		}
		fclose(fin);
	}
	if (argc == 3)
	{
		err = fopen_s(&fout, argv[2], "w");
		if (err == 0)
		{
			fprintf_s(fout, "My name is %s", username);
			printf_s("File was edited successfully!\n");
		}
		else
		{
			printf_s("File %s cannot be opened!\n", argv[2]);
		}
		fclose(fout);
	}
	*/

	// второе занятие по файлам:
	int scanfkol;

	err1 = fopen_s(&fin, argv[1], "r");
	err2 = fopen_s(&fout, argv[2], "w");
	if ((err1 == 0) && (err2 == 0))
	{
		printf_s("\n Files opened successfully! \n");
		int size, i = 0; double *arr;
		printf_s("Enter the size of array: ");
		fscanf_s(fin, "%d", &size); // заведомо знаем, что первое целое число в файле - размер массива 
		arr = (double*)malloc(sizeof(double)*size);
		if (arr != NULL)
		{

		}
	}

	system("pause");
	return 0;
}