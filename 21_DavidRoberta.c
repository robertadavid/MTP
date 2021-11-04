#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

 int prim(long int x) //verifica proprietatea de nr prim
{
	int i, k = 0;
	if (x == 2)
		return 1;
	for (i = 2; i <= sqrt(x); i++)
	{
		if (x%i == 0)
			k++;
	}
	if (k == 0)
		return 1;
	else
		return 0;
}


int main()
{
    int n, i,v[5],j,ok,s,k,l,m,o,p;
	FILE *f, *g;
	f = fopen("in.txt", "r");
	g = fopen("out.txt", "w");

	fscanf(f,"%d", &n);
	for (i = 2; i < n; i++) //parcurg toate numerele de la 2 la n
	{
		if (i < 9 && prim(i)) //daca i este de o cifra si prim, il afisez
			fprintf(g, "%d\n", i);

		if (prim(i)) { //daca are mai multe cifre, ii voi extrage cifrele intr-un vector 
			
				if (i > 9 && i < 100) 
				{
					j = 1;
					o = i;
					while (o > 0) //extrag cifrele in vector
					{
						v[j] = o % 10;
						j++;
						o = o / 10;
					}
					ok = 1;
					for (k = 1; k <= 2 && ok; k++) //iau toate posibilitatile de numere care se pot forma cu cifrele extrase
					{
						for (l = 1; l <= 2&& ok; l++)
						{
							if (k != l ) //trebuie sa difere deoarece daca folosim de 2 ori aceeasi pozitie din vector, nu va mai fi vorba
							{            //de acelasi numar ca cel initial
								s = v[k] * 10 + v[l] ; //alcatuiesc numarul
								if (prim(s) == 0) //il verific daca este prim sau nu
									ok = 0; //daca nu este prim ok va deveni 0
							}
						}
					}
					if (ok) //daca dupa toate incercarile ok nu s-a schimbat, inseamna ca numarul este prim circular si il afisam
						fprintf(g, "%d\n", i);
				}

				if (i >= 100 && i < 1000) //vom face la fel si pentru celelalte numere, deoarece am lucrat in functie de numarul de cifre
				{
					j = 1;
					o = i;
					while (o > 0)
					{
						v[j] = o % 10;
						j++;
						o = o / 10;
					}
					ok = 1;
					for (k = 1; k <= 3 && ok; k++)
					{
						for (l = 1; l <= 3 && ok; l++)
						{
							for (m = 1; m <= 3 && ok; m++) {
								if (k != l && k != m && l != m)
								{
									s = v[k] * 100 + v[l] * 10 + v[m];
									if (prim(s) == 0)
										ok = 0;
								}
							}
						}

					}
					if (ok)
						fprintf(g,"%d\n", i);
				}

				if (i >= 1000 && i <= 100000) //nu exista nicio valoare prima circulare deoarece singura care ar putea fi
				{                            //ar trebui sa se formeze cu cifrele 1,3,7,9
					j = 1;
					o = i;
					while (o > 0)
					{
						v[j] = o % 10;
						j++;
						o = o / 10;
					}
					ok = 1;
					for (k = 1; k <= 4 && ok; k++)
					{
						for (l = 1; l <= 4 && ok; l++)
						{
							for (m = 1; m <= 4 && ok; m++) 
							{
								for (p = 1;p <= 4 && ok;p++)
								{
									if (k != l && k != m && l != m && k != p && m != p && l != p)
									{
										s = v[k] * 1000 + v[l] * 100 + v[m]*10 + v[p];
										if (prim(s) == 0)
											ok = 0;
									}
								}
							}
						}

					}
					if (ok)
						fprintf(g,"%d\n", i);
				}
			
		}
	
	}

	fclose(f);
	fclose(g);
	system("pause");
	return 0;
}