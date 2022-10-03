#include "stdio.h"
#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>


int read_from_file(const char *filename, int *array_size, double **arr)
{
	FILE *fin; int fopen_err;

	fopen_err = fopen_s(&fin, filename, "r");
	if (fopen_err == 0)
	{	
		if (fscanf_s(fin, "%d", array_size) > 0) // array_size - уже указатель, не нужно ставить &...
		{	
			if ((*array_size) > 0)
			{
				*arr = (double*)malloc(sizeof(double) * (*array_size));
				int i = 0;
				while ((fscanf_s(fin, "%lf", (*arr) + i) > 0) && (i < (*array_size)))
				{
					i++;
				}
				fclose(fin);
				return 1;
			}
		}
	}
	return 0;
}

double find_array_sum(double *arr, int *array_size)
{
	double array_sum = 0; int i = 0;
	while (i < *array_size)
	{
		array_sum += arr[i];
		i++;
	}
	return array_sum;
}

int write_to_file(const char *filename, double *sum)
{
	FILE *fout; int fopen_err;
	fopen_err = fopen_s(&fout, filename, "w");
	if (fopen_err == 0)
	{
		fprintf_s(fout, "%.3lf", *sum);
		return 1;
	}
	fclose(fout);
	return 0;
}

int main(int argc, char *argv[])
{
	int array_size, rff_err, wtf_err; double *arr;
	
	if (argc == 3)
	{	
		rff_err = read_from_file(argv[1], &array_size, &arr);
		if (rff_err == 1)
		{	
			double array_sum = find_array_sum(arr, &array_size);
			printf_s("Array sum: %.2lf\n", array_sum);
			
			wtf_err = write_to_file(argv[2], &array_sum);
			
			if (wtf_err == 1)
			{
				printf_s("All is done!\n");
			}
		}	
	}
	system("pause");
	return 0;
}
