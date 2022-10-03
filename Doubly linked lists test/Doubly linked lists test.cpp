#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct List_unit
{
	int num;
	List_unit *next; // указатель на следующий элемент
	List_unit *previous; // указатель на предыдущий элемент
};

// инициализация списка (создание корневого узла)
struct List_unit *list_init(int a) // а - значение первого узла
{
	List_unit *lst;
	lst = (List_unit*)malloc(sizeof(List_unit));

	lst->num = a;
	lst->previous = NULL; // указатель на след узел
	lst->next = NULL; // указатель на пред узел

	return lst;
}

// *lst - указатель на УЗЕЛ, ПОСЛЕ которго происходит добавление
struct List_unit *add_element(List_unit *lst, int num)
{
	List_unit *new_list_unit, *buffer;
	new_list_unit = (List_unit*)malloc(sizeof(List_unit)); // выделяем память под новый узел

	buffer = lst->next; // сохраняем указатель на следующий узел
	lst->next = new_list_unit; // предыдущий узел указывает на создаваемый

	new_list_unit->num = num; // сохранение данных в новом узле
	new_list_unit->next = buffer; // переставили указатели 
	new_list_unit->previous = lst;

	if (buffer != NULL)
	{
		buffer->previous = new_list_unit;
	}

	return new_list_unit; // возвращаем адрес добавленного узла
}

// head - корень списка (первый элемент)
struct List_unit *delete_head(List_unit *head)
{
	List_unit *new_head;
	new_head = head->next;
	new_head->previous = NULL;
	free(head);
	return new_head;
}


// *lst - указатель на УЗЕЛ, который хотим удалить
struct List_unit *delete_element(List_unit *lst)
{
	List_unit *previous_unit, *next_unit;
	previous_unit = lst->previous; // УЗЕЛ до lst
	next_unit = lst->next; // УЗЕЛ после lst

	// переставляем указатели:
	if (previous_unit != NULL)
	{
		previous_unit->next = lst->next;
	}
	if (next_unit != NULL)
	{
		next_unit->previous = lst->previous;
	}

	free(lst); // освобождаем память
	return previous_unit; // возвращает указатель на узел, следующий за удаляемым
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
		lst = list_init(n); // создали корень списка
		first_unit = lst; // отдельно сохраняем первый элемент
		printf_s("Created first element!\n");
		
		while (fscanf_s(fin, "%d", &n) > 0) // добавляем элементы в список
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

// lst - первый элемент списка (корень списка)
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
	
	if (lst->num == 5) // обработка крайнего случая, когда в конце есть цифра 5
	{	
		lst = delete_element(lst); // lst - нулевой
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