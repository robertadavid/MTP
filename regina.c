#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int n,x[10];
void afisare() {
	int i, j;
	for (i = 1; i <= n; i++) {

		for (j = 1; j <= n; j++)

			if (x[i] == j)

				printf("R ");

			else printf("* ");

		printf("\n");

	}
}

int valid(int k) {
	int i;
	for (i = 1; i <= k - 1; i++)
		if (x[k] == x[i] || (abs(i-k)==abs(x[i]-x[k])))
			return 0;
	return 1;
}

int solutie(k)
{
	return (k == n);
}

void back(int k) {
	int i;
	for (i = 1; i <= n; i++) {
		x[k] = i;
		if (valid(k))
			if (k == n)
				afisare();
			else
				back(k + 1);
	}
}

int main() {

	scanf("%d", &n);
	back(1);
	system("pause");
	return 0;
}