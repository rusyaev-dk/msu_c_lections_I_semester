#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct List_unit // list_unit
{
	int num;
	List_unit *next; // ��������� �� ��������� �������
	List_unit *previous; // ��������� �� ���������� �������
};

// ������������� ������ (�������� ��������� ����)
struct List_unit * init(int a) // � - �������� ������� ����
{
	List_unit *lst;
	lst = (List_unit*)malloc(sizeof(List_unit));
	
	lst->num = a;
	lst->previous = NULL; // ��������� �� ���� ����
	lst->next = NULL; // ��������� �� ���� ����
	
	return lst;
}

// *lst - ��������� �� ����, ����� ������� ���������� ����������
struct List_unit * add_element(List_unit *lst, int num)
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

// *lst - ��������� �� ����, ������� ����� �������
struct List_unit * delete_element(List_unit *lst)
{
	List_unit *buffer_previous, *buffer_next;
	buffer_previous = lst->previous; // ���� �� lst
	buffer_next = lst->next; // ���� ����� lst
	
	// ������������ ���������:
	if (buffer_previous != NULL)
	{
		buffer_previous = lst->next;
	}
	if (buffer_next != NULL)
	{
		buffer_next = lst->previous;
	}
	
	free(lst); // ����������� ������
	return buffer_previous; // ���������� �������, �������������� ����������
}

void print_list(List_unit *lst)
{
	List_unit *buffer;
	buffer = lst;
	
	while (buffer != NULL)
	{
		printf_s("%d ", buffer->num);
		buffer = buffer->next;
	}
}

/*int file_to_list(const char* filename, List_unit *lst)
{
	FILE *fin;  int fopen_error;
	fopen_error = fopen_s(&fin, filename, "r");
	if (fopen_error == 0)
	{
		int list_size = 0, n;
		fscanf_s(fin, "%d", &list_size);
		for (int i = 0; i < list_size; i++)
		{	
			fscanf_s(fin, "%d", &n);
			add_element(lst, n);
		}
		fclose(fin);
	}
	else
	{
		printf_s("Cannot open the file: %s\n", *filename);
		return 1;
	}
	return 0;
}*/

int main()
{
	setlocale(LC_ALL, "Russian");
	//srand(time(NULL));
	
	const char filename[] = "input_file.txt";
	List_unit list1;
	
	//file_to_list(filename, &list1);
	add_element(&list1, 7);
	add_element(&list1, 73);
	add_element(&list1, 73);
	add_element(&list1, 7);
	print_list(&list1);

	system("pause");
	return 0;
}