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
	List_unit *previous; // ��������� �� ���������� �������
};

// ������������� ������ (�������� ��������� ����)
struct List_unit *list_init(int a) // � - �������� ������� ����
{
	List_unit *lst;
	lst = (List_unit*)malloc(sizeof(List_unit));

	lst->num = a;
	lst->previous = NULL; // ��������� �� ���� ����
	lst->next = NULL; // ��������� �� ���� ����

	return lst;
}

// *lst - ��������� �� ����, ����� ������� ���������� ����������
struct List_unit *add_element(List_unit *lst, int num)
{
	List_unit *new_list_unit, *buffer;
	new_list_unit = (List_unit*)malloc(sizeof(List_unit)); // �������� ������ ��� ����� ����

	buffer = lst->next; // ��������� ��������� �� ��������� ����
	lst->next = new_list_unit; // ���������� ���� ��������� �� �����������

	new_list_unit->num = num; // ���������� ������ � ����� ����
	new_list_unit->next = buffer; // ����������� ��������� 
	new_list_unit->previous = lst;

	if (buffer != NULL)
	{
		buffer->previous = new_list_unit;
	}

	return new_list_unit; // ���������� ����� ������������ ����
}

// head - ������ ������ (������ �������)
struct List_unit *delete_head(List_unit *head)
{
	List_unit *new_head;
	new_head = head->next;
	new_head->previous = NULL;
	free(head);
	return new_head;
}


// *lst - ��������� �� ����, ������� ����� �������
struct List_unit *delete_element(List_unit *lst)
{
	List_unit *previous_unit, *next_unit;
	previous_unit = lst->previous; // ���� �� lst
	next_unit = lst->next; // ���� ����� lst

	// ������������ ���������:
	if (previous_unit != NULL)
	{
		previous_unit->next = lst->next;
	}
	if (next_unit != NULL)
	{
		next_unit->previous = lst->previous;
	}

	free(lst); // ����������� ������
	return previous_unit; // ���������� ��������� �� ����, ��������� �� ���������
}

void print_list(List_unit *lst)
{	
	List_unit *buffer;
	buffer = lst;
	printf_s("\nYour list:\n");
	while (buffer != NULL)
	{
		printf_s("%d ", buffer->num);
		buffer = buffer->next;
	}
}

struct List_unit *file_to_list(const char *filename)
{
	FILE *fin;  int fopen_error;
	fopen_error = fopen_s(&fin, filename, "r");
	if (fopen_error == 0)
	{	
		printf_s("Creating list...\n");
		List_unit *lst, *first_unit, *new_unit; int n;
		
		fscanf_s(fin, "%d", &n);
		lst = list_init(n); // ������� ������ ������
		first_unit = lst; // �������� ��������� ������ �������
		printf_s("Created first element!\n");
		
		while (fscanf_s(fin, "%d", &n) > 0) // ��������� �������� � ������
		{
			new_unit = add_element(lst, n);
			lst = new_unit;
		}
		
		fclose(fin);
		printf_s("List created!\n");
		
		return first_unit;
	}
	else
	{
		printf_s("Cannot open the file:\n");
		return NULL;
	}
}

// lst - ������ ������� ������ (������ ������)
struct List_unit *sort_list_by_task(List_unit *lst)
{	
	List_unit *new_head = lst, *first_elem = lst;
	
	while (lst->next != NULL)
	{
		if ((lst->num) == 5 && (lst->previous) == NULL)
		{
			lst = delete_head(lst); 
			new_head = lst;
			printf_s("\ndeleted head 5");
		}
		else if (lst->num == 5)
		{	
			lst = delete_element(lst); 
			printf_s("\ndeleted elem 5");
		}
		else
		{	
			printf_s("\npassed %d", lst->num);
			if (lst->next == NULL)
			{
				break;
			}
			else
			{
				lst = lst->next;
			}
		}
	}
	
	if (lst->num == 5) // ��������� �������� ������, ����� � ����� ���� ����� 5
	{	
		lst = delete_element(lst); // lst - �������
		printf_s("\nadsfadf %d", lst->previous->num);
		printf_s("\ndeleted elem 5");
	}

	printf_s("\nSort completed!");
	if (new_head != first_elem)
	{
		return new_head;
	}
	else
	{
		return first_elem;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//srand(time(NULL));

	const char filename[] = "input_file.txt";
	List_unit *first_unit;

	first_unit = file_to_list(filename);
	

	print_list(first_unit);
	printf_s("\n");

	first_unit = sort_list_by_task(first_unit);
	printf_s("\n");

	print_list(first_unit);

	system("pause");
	return 0;
}