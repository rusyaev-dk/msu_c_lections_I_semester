#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Number // структура элемента двусвязного списка
{
	int num;
	Number *next, *previous;
};

void read_from_file(const char* filename)
{
	FILE *fin; int fopen_err;
	Number *list, *first_elem, *last_elem, *removed_elem;
	

	fopen_err = fopen_s(&fin, filename, "r");
	if (fopen_err == 0)
	{
		int n;
		fscanf_s(fin, "%d", &n);
		first_elem = (Number*)malloc(sizeof(Number));
		first_elem->previous = NULL;
		first_elem->num = n;
		list = first_elem;
		while (fscanf_s(fin, "%d", &n) > 0)
		{
			last_elem = (Number*)malloc(sizeof(Number));
			last_elem->num = n;
			last_elem->next = NULL;
			last_elem->previous = list;
			list = last_elem;
			printf_s("%d ", list->num);
		}

		// Инверсия элементов списка:
		/*printf_s("\nInveted list:\n");
		while (list->previous != NULL)
		{
			printf_s("%d ", list->num);
			list = list->previous;
		}*/
		
		printf_s("\nList without \"5\":\n");
		if (first_elem->num == 5)
		{
			removed_elem = first_elem;
			first_elem = first_elem->next;
			printf_s("%d ", first_elem->num);
			free(removed_elem);
		}
		/*while (first_elem->next != NULL)
		{
			if (first_elem->next->num == 5)
			{
				removed_elem = first_elem->next;
				first_elem = first_elem->next->next;
				free(removed_elem);
				printf_s("%d ", first_elem->num);
			}
			else
			{
				printf_s("%d ", first_elem->num);
				first_elem = first_elem->next;
			}
		}*/
		
	}
	else
	{
		printf_s("\nCannot open the file: %s", *filename);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	char filename[] = "input_file.txt";
	read_from_file(filename);



	system("pause");
	return 0;
}