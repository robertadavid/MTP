#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <iterator>

using namespace std;

class Masini
{
private: string nr_inmatr;
	   string tip;
	   string ora, data;
	   float pret;
public: 
	Masini()
	{
		nr_inmatr = ora = data = "";
		tip = "";
		pret = -1;
	}
	Masini(string tip, string nr_inmatr, string ora, string data, float pret)
	{
		this->tip = tip;
		this->nr_inmatr = nr_inmatr;
		this->ora = ora;
		this->data = data;
		this->pret = pret;
	}

	virtual void afisare()
	{
		cout << "Tipul spalarii: " << tip <<endl;
		cout << "Numarul de inmatriculare: " << nr_inmatr <<endl;
		cout << "Ora: " << ora <<endl;
		cout << "Data: " << data <<endl;
		cout << "Pretul masinii: " << pret <<endl;
	}

};

class Mari :public Masini
{
private: 
	   int greutate, lungime;
public:
	Mari()
	{
		
		greutate=lungime= -1;
		
	}

	Mari(string tip, string nr_inmatr, string ora, string data, float pret , int greutate, int lungime) : Masini(tip, nr_inmatr, ora, data, pret)
	{
		
		this->greutate = greutate;
		this->lungime = lungime;
	}

	void afisare()
	{
		Masini::afisare();
		
		cout << "Greutatea masinii: " << greutate <<endl;
		cout << "Lungimea masinii: " << lungime <<endl;


	}
};

class Mici :public Masini
{
private: 
	   string marca, culoare;
public:
	Mici()
	{
		
		marca = culoare = "";
	}

	Mici(string tip, string nr_inmatr, string ora, string data, float pret, string marca, string culoare) : Masini(tip, nr_inmatr, ora, data, pret)
	{
		
		this->marca = marca;
		this->culoare = culoare;
	}

	void afisare()
	{
		Masini::afisare();
		
		cout << "Marca masinii: " << marca <<endl;
		cout << "Culoarea masinii:" <<  culoare <<endl;
	}
};

list <Masini*> l;
list <Masini*> :: iterator it;

void citire()
{
	string nr_inmatr;
	string tip;
	string ora, data;
	float pret;
	int greutate, lungime;
	string marca, culoare;

	cout << "La ce pret doriti sa fie spalarea? ";
	cin >> pret;

	if (pret > 100)
	{
		cout << "Tipul spalarii: "; cin >> tip;
		cout << "Numarul de inmatriculare: "; cin >> nr_inmatr;
		cout << "Ora: "; cin >> ora;
		cout << "Data: "; cin >> data;
		cout << "Greutatea masinii: "; cin >> greutate;
		cout << "Lungimea masinii: "; cin >> lungime;
		l.push_back(new Mari(tip, nr_inmatr, ora, data, pret, greutate, lungime));

	}

	if (pret <= 100)
	{
		cout << "Tipul spalarii: "; cin >> tip;
		cout << "Numarul de inmatriculare: "; cin >> nr_inmatr;
		cout << "Ora: "; cin >> ora;
		cout << "Data: "; cin >> data;
		cout << "Marca masinii: "; cin >> marca;
		cout << "Culoarea masinii:"; cin >> culoare;
		l.push_back(new Mici(tip, nr_inmatr, ora, data, pret, marca, culoare));
	}

}

void show() {
	cout << "=============================" << endl;
	for (it = l.begin(); it != l.end(); it++) {
		(*it)->afisare();
		cout << "----------------------------- \n";
	}
	cout << "=============================" << endl;
}

void citire_fis()
{
	string nr_inmatr;
	string tip;
	string ora, data;
	float pret;
	int greutate, lungime;
	string marca, culoare;
	ifstream f("masini.txt");

	while (!f.eof()) {

		f >> pret;
		if (pret > 100) {
			f >> tip;
			f >> nr_inmatr;
			f >> ora;
			f >> data;
			f >> greutate;
			f >> lungime;
			l.push_back(new Mari(tip, nr_inmatr, ora, data, pret, greutate, lungime));
			
		}
		if (pret <= 100 ) {
			f >> tip;
			f >> nr_inmatr;
			f >> ora;
			f >> data;
			f >> marca;
			f >> culoare;
			l.push_back(new Mici(tip, nr_inmatr, ora, data, pret, marca, culoare));
			
		}

	}
	f.close();
}


int main()
{
	int opt;

	do {

		cout << "1.Citire de la tastatura" <<endl;  
		cout << "2.Afisare " <<endl;
		cout << "3.Citire din fisier" << endl;
		cout << "0.Iesire" <<endl;

		cout << "Dati optiunea dumneavoastra:"; 
		cin >> opt;
		switch (opt)
		{
		case 1: citire();
			break;
		case 2: show();
			break;
		case 3: citire_fis();
			break;
		case 0: exit(0);
		default: cout << "Optiunea dumneavoastra este gresita!";
		}

	} while (opt != 0);

	return 0;
}