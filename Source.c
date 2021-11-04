#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int i = 0, vf = 0, st[100];

int push(int val)
{
	vf++;
	st[vf] = val;
	return val;
}

int pop()
{
	if (vf > 0)
	{
		vf--;
		return st[vf];
	}
	else
		return -1;
}

void afisare()
{
	int i;
	for (i = 1;i <= vf; i++)
		printf("%d", st[i]);
	printf("\n");
}
int main()
{
	int x;
	printf("x="); scanf("%d", &x);
	push(x);
	while (vf) {
		if (x >= 12)
		{
			pop();
			vf = x - 1;
		}
		else
			push(x + 2);
		afisare();
	}
	system("pause");
	return 0;
}
