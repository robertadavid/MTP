#include <stdio.h>
#include<stdlib.h>

int main()
{
	int i, j, n, a[20][20], opt,s,t[20][20];
	printf("Dati liniile si coloanele celei de a doua matrici\n"); scanf("%d", &n);
	for (i = 0;i < n;i++)
		for (j = 0;j < n;j++)
		{
			printf("a[%d][%d]=", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	do
	{
		printf("0.Iesire\n");
		printf("1.Afisare matrici\n");
		printf("2.Afis el. diag. princ\n");
		printf("3.Afis el. diag. sec.\n");
		printf("4.Afis el. sub diag. princ.\n");
		printf("5.Afis el. deasupra diag.princ.\n");
		printf("6.Afis el. deasupra diag.sec.\n");
		printf("7.Afis el. de sub diag.sec.\n");
		printf("8.Suma el. de pe marginile matricei\n");
		printf("9.Afisare transpusa matricei\n");
		printf("Optiunea dvs este:\n");
		scanf("%d", &opt);

		switch (opt)
		{
		case 0: exit(0);
			break;
		case 1: {
			for (i = 0;i < n;i++)
			{
				for (j = 0; j < n; j++)
					printf("%3d", a[i][j]);
				printf("\n");
			}
		}
				break;
		case 2: {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++)
					if (i == j)
						printf("%3d", a[i][j]);
					else
						printf("%3c", ' ');
				printf("\n");
			}
		}
				break;
		case 3: {
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					if (i + j == n - 1)
						printf("%3d", a[i][j]);
					else
						printf("%3c", ' ');
				printf("\n");
			}
		}
				break;
		case 4: {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (i > j)
						printf("%3d", a[i][j]);
					else
						printf("%3c", ' ');
				}
				printf("\n");
			}
		}
				break;
		case 5: {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (i < j)
						printf("%3d", a[i][j]);
					else
						printf("%3c", ' ');
				}
				printf("\n");
			}
		}
			break;
		case 6: {
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++) {
					if (i + j < n - 1)
						printf("%3d", a[i][j]);
					else
						printf("%3c", ' ');
				}
				printf("\n");
			}
		}
			break;
		case 7: {
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++) {
					if (i + j > n - 1)
						printf("%3d", a[i][j]);
					else
						printf("%3c", ' ');
				}
				printf("\n");
			}
		}
			break;
		case 8: { s = 0;
			for (j = 0; j < n; j++) {
				s += a[0][j];
				s += a[n - 1][j];
			}
			for (i = 1; i < n - 1; i++) {
				s += a[i][0];
				s += a[i][n - 1];
			}
			printf("Suma elementelor de pe margini este %d\n", s);
		}
			break;
		case 9: {
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					t[i][j] = a[j][i];
				}
			}
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					printf("%3d", t[i][j]);
				}
				printf("\n");
			}

		}
			break;
		default: printf("Optiune gresit\n!");
			break;
		}
	}
		while (opt != 0);
		system("pause");
		return(0);
	}