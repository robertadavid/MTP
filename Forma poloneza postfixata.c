#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max_size 101                         
int top = -1, x;
int st[max_size];

int push(int x)
{
	if (top == max_size - 1)
	{
		printf("Eroare: Stiva este plina!");

	}
	top++;
	st[top] = x;
	return x;
}

int pop()
{
	if (top == -1)
	{
		printf("Eroare: Stiva este goala!");
		return -1;
	}
	return top--;
}

int e_operator(char car)
{
	if (car == '+' || car == '-' || car == '*' || car == '/' || car == '(' || car == ')')
		return 1;
	else
		return 0;
}

int prioritate(char car)
{
	if (car == '(' || car == ')')
		return 0;
	else if (car == '*' || car == '/')
		return 1;
	else
		return 2;
}

int main()
{
	char fp[50], rez[50], E[50], aux;
	int i, j = 0;
	printf("Introduceti expresia: ");
	gets(E);

	for (i = 0; i <= (strlen(E)); i++)
	{
		if (i == '(')
			push(i);

		else if (e_operator(i) == 0)
		{
			rez[j] = i;
			j++;
		}
		else if (e_operator(i) == 1)
		{
			aux = pop();
			while (e_operator == 1 && prioritate(aux) > prioritate(i))
			{
				rez[j] = aux;
				j++;
				aux = pop();
			}
			push(aux);
			push(i);
		}
		else if (i == ')')
		{
			aux = pop();
			while (aux != '(')
			{
				rez[j] = aux;
				j++;
				aux = pop();
			}
		}
		else
			printf("Expresie invalida!");
	}
	puts(rez);

	system("pause");
	return 0;
}