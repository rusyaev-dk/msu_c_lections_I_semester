#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct Car
{
	char *model, *color;
	//int horse_power, max_speed;
	double *price;
};

void create_car(Car *car)
{	
	printf_s("You are creating a new car now!\n");
	
	printf_s("Name the model of the car: ");
	car->model = (char*)malloc(sizeof(char) * 30);
	int i = 0;
	while (scanf_s("%c", (car->model) + i))
	{
		if ((car->model[i]) == '\n')
		{
			break;
		}
		i++;
	}
	car->model[i] = '\0';

	printf_s("\nChoose the color of the car: ");
	car->color = (char*)malloc(sizeof(char) * 30);
	i = 0;
	while (scanf_s("%c", (car->color) + i))
	{
		if ((car->color[i]) == '\n')
		{
			break;
		}
		i++;
	}
	car->color[i] = '\0';

	printf_s("\nSet the price of the car: ");
	car->price = (double*)malloc(sizeof(double) * 15);
	/*i = 0;
	while (scanf_s("%c", (car->price) + i))
	{
		if ((car->price[i]) == '\n')
		{
			break;
		}
		i++;
	}*/
	scanf_s("%lf", car->price[0]);
	printf_s("%lf", car->price);
	printf_s("\nSuccessfully created a new car: %s\n", car->model);
}

void represent_car(Car *car)
{	
	if ((car->model) && (car->color) && (car->price))
	{
		printf_s("\nModel: %s\n", car->model);
		printf_s("Color: %s\n", car->color);
		//printf_s("Horse power: %d\n", car->horse_power);
		//printf_s("Max speed: %d\n", car->max_speed);
		printf_s("Car price: %.2lf\n", car->price);
	}
	else
	{
		printf_s("\nNot enough information! \n");
	}
}

int main()
{	
	Car sonata;
	
	create_car(&sonata);
	//printf_s("%s", sonata.model);
	represent_car(&sonata);

	system("pause");
	return 0;
}

