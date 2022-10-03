#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct List_unit
{
	int num;
	List_unit *next; // ��������� �� ��������� �������
};

struct List_unit *list_init(int a)
{
	List_unit *first_unit;
	first_unit = (List_unit*)malloc(sizeof(List_unit));
	first_unit->num = a;
	first_unit->next = NULL;

	return first_unit;
}

// *lst - ��������� �� ����, ����� ������� ���������� ����������
struct List_unit *add_element(List_unit *lst, int a)
{
	List_unit *new_list_unit, *buffer;
	new_list_unit = (List_unit*)malloc(sizeof(List_unit));
	buffer = lst->next;
	lst->next = new_list_unit;
	new_list_unit->num = a;
	new_list_unit->next = buffer;
	
	return new_list_unit;
}

struct List_unit *delete_head(List_unit *head)
{
	List_unit *new_head;
	new_head = head->next;
	free(head);

	return new_head;
}

// *head - ������ ������
// *lst - ��������� �� ����, ������� �� ����� �������
struct List_unit *delete_element(List_unit *head, List_unit *lst)
{	
	List_unit *buffer; // ����� ������, ����� �������� �� �������� ����� ������
	buffer = head;
	while (buffer->next != lst) // ���� �� ������ ����, �������������� lst (����������)
	{
		buffer = buffer->next;
	}
	buffer->next = lst->next; // ������������ ���������
	free(lst);

	return buffer;
}

void print_list(List_unit *first_unit)
{
	List_unit *buffer;
	buffer = first_unit;
	printf_s("\nYour list:\n");
	while (buffer != NULL)
	{
		printf_s("%d ", buffer->num);
		buffer = buffer->next;
	}
}

struct List_unit *file_to_list(const char *filename)
{
	FILE *fin; int fopen_error;
	fopen_error = fopen_s(&fin, filename, "r");
	if (fopen_error == 0)
	{
		List_unit *first_unit, *buffer, *new_unit; int n;
		fscanf_s(fin, "%d", &n);
		first_unit = list_init(n);
		buffer = first_unit;
		while (fscanf_s(fin, "%d", &n) > 0)
		{
			new_unit = add_element(buffer, n);
			buffer = new_unit;
			//printf_s("\n Scanned %d", n);
		}
		fclose(fin);
		//printf_s("\nList created!\n");

		return first_unit;
	}
	else
	{
		printf_s("\nCannot open the file: %s\n", *filename);
		return NULL;
	}
}

// *lst - ������ ������ (������ �������), �� ���� new_head = lst = first_unit
struct List_unit *sort_list_by_task(List_unit *lst)
{
	List_unit *new_head = lst, *first_unit = lst, *first_unit_2 = lst;

	while (lst->next != NULL)
	{
		if ((lst->num) == 5 && (lst==first_unit_2))
		{
			new_head = delete_head(lst);// ���������� ����� �� ��������� ������� � �� ���������� ������
			first_unit_2 = new_head;
			lst = new_head;
			//printf_s("\nDeleted head 5"); 
		}
		else if ((lst->num) == 5)
		{
			lst = delete_element(new_head, lst); // ���������� ����� �� ���� ������� ����� ����������
			//printf_s("\nDeleted elem 5");
		}
		else
		{
			//printf_s("\nPassed %d", lst->num);
			lst = lst->next;
		}
	}
	if (lst->num == 5) // ��������� �������� ������, ����� ��������� ������� ����� 5
	{
		lst = delete_element(new_head, lst);
		//printf_s("\nDeleted elem 5");
	}

	printf_s("\nList sorted!\n");
	if (new_head == first_unit)
	{
		return first_unit;
	}
	else if (new_head != first_unit)
	{
		return new_head;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	const char filename[] = "input_file.txt";
	List_unit *first_unit;

	first_unit = file_to_list(filename);
	print_list(first_unit);


	printf_s("\nSorted list:\n");
	first_unit = sort_list_by_task(first_unit);
	print_list(first_unit);

	system("pause");
	return 0;
}