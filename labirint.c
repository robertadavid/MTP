#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int matrice[5][5] = {
	{1,1,1,1,1},
	{1,1,0,1,1},
	{1,0,1,0,1},
	{1,0,1,0,1},
	{1,1,0,1,1}
};

int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };

int m = 5, n = 5;

void Print(int i, int j)
{
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (matrice[i][j] == 0)
				printf("P(%d, %d)", i, j);
		}

		printf("\n");
	}
}

void cautare(int i, int j)
{
	int k;
	if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
	{
		Print(i, j);
	}
	else
		for (k = 0;k < 8;k++)
		{
			if (matrice[i + dx[k]][j + dy[k]] == 0)
			{
				matrice[i + dx[k]][j + dy[k]] = matrice[i][j] + 1;
				cautare(i + dx[k], j + dy[k]);
				matrice[i + dx[k]][j + dy[k]] = 0;
			}
		}
}


int main()
{
	int i = 0, j = 0;

	cautare(i, j);
	printf("\n");

	system("pause");
	return 0;

}