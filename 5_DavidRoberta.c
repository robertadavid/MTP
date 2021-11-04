#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, v[100], l = 0, k = 0, nr = 0, u[100], z[100], aux;
	FILE *g, *f;

	g = fopen("swp.out", "w");
	f = fopen("swp.in", "r");

	if (f == NULL)
		printf("Fisierul nu se poate deschide!\n");
	else {
		while (!feof(f))
		{
			fscanf(f, "%d", &n);
			for (i = 1;i <= n;i++) //citesc cei n biti
				fscanf(f, "%d", &v[i]);
		}
	}

	fclose(f);

	for (i = 1;i <= n;i++)
	{
		if (v[i] == 1) //vom retine in u pozitiile cifrei 1
		{
			k++;
			u[k] = i;
		}
		else
		{
			l++; //vom retine in z pozitiile cifrei 0
			z[l] = i;
		}
	}

	for (i = 1;i <= k && l - i >= 0;i++)
	{
		if (u[i] < z[l - i + 1]) //interschimbam
		{
			aux = v[u[i]];
			v[u[i]] = v[z[l - i + 1]];
			v[z[l - i + 1]] = aux;
			nr++;
			fprintf(g, "%d %d\n", u[i], z[l - i + 1]); //afisam pozitiile pe care le interschimbam
		}
	}

	fprintf(g, "%d\n", nr); //afisez numarul de interschimbari

	for (i = 1;i <= n;i++)
		fprintf(g, "%d", v[i]); //am afisat, in plus, si cum arata numarul dupa ce au loc interschimbarile


	fclose(g);
	system("pause");
	return 0;
}