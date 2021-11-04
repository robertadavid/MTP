#include<iostream>
#include<fstream>
#include<string>
#include<list>
#include<iterator>
#include<conio.h>
#pragma warning(disable:4996);
using namespace std;
class restaurant {
public:
	int mese = 50;
	string comanda;
	string status;
	restaurant(string comanda,string status)
	{
		this->status = status;
		this->comanda = comanda;
	}
	void schimbare_status(string status_nou)
	{
		this->status = status_nou;
	}
};
class pizza:public restaurant {
	string tip;
	string dimensiune;
	string sosuri;
public:
	pizza(string comanda,string status,string tip, string dimensiune, string sosuri):restaurant(comanda,status)
	{
		this->tip = tip;
		this->dimensiune = dimensiune;
		this->sosuri = sosuri;
	}
	friend void afisare();
	friend void cautare();
	friend void stergere();
	friend void numarare();

};
class paste :public restaurant {
	string tip;
	string portie;
	string sosuri;
public:
	paste(string comanda,string status,string tip, string portie, string sosuri):restaurant(comanda,status)
	{
		this->tip = tip;
		this->portie = portie;
		this->sosuri = sosuri;
	}
	friend void afisare();
	friend void cautare();
	friend void stergere();
	friend void numarare();

};
class bauturi :public restaurant {
	string tip;
	int numar_sticle;
public:
	bauturi(string comanda,string status,string tip, int numar_sticle):restaurant(comanda,status)
	{
		this->tip = tip;
		this->numar_sticle = numar_sticle;
	}
	friend void afisare();
	friend void cautare();
	friend void stergere();
	friend void numarare();
	
};
list<restaurant*>l;
list<restaurant*>::iterator i;
void citire()
{
	string comanda;
	string tip;
	string dimensiune;
	string sosuri, portie;
	string status;
	int numar_sticle;

	cout << "Intoduceti comanda dumneavoastra (pizza,paste,bauturi) (string):"; cin >> comanda;
	cout << "Introduceti statusul comenzii (sting):"; cin >> status;
	if (comanda == "pizza")
	{
		cout << "Introduceti tipul:"; cin >> tip;
		cout << "Introduceti dimensiunea:"; cin >> dimensiune;
		cout << "Introduceti susurile:"; cin >> sosuri;
		l.push_front(new pizza(comanda,status,tip, dimensiune, sosuri));
	}
	if (comanda =="paste")
	{
		cout << "Introduceti tipul:"; cin >> tip;
		cout << "Introduceti portia:"; cin >> portie;
		cout << "Introduceti sosurile:"; cin >> sosuri;
		l.push_front(new paste(comanda,status,tip, portie, sosuri));
	}
	if (comanda == "bauturi")
	{
		cout << "Introduceti tipul:"; cin >> tip;
		cout << "Introduceti numarul de sticle:"; cin >> numar_sticle;
		l.push_front(new bauturi(comanda,status,tip, numar_sticle));
	}
}
void afisare()
{
	for (i = l.begin(); i != l.end(); i++)
	{
		if ((*i)->comanda == "pizza")
		{
			cout<<(*i)->comanda<<" ";
			pizza *m = (pizza*)(*i);
			cout << m->dimensiune << " " << m->mese << " " << m->sosuri<<" "<< m->tip << " "<<m->status<<endl;
			char ch = _getch();
		}
		if ((*i)->comanda == "paste")
		{
			cout<<(*i)->comanda<<" ";
			paste *m = (paste*)(*i);
			cout << m->portie << " " << m->mese << " " << m->sosuri << " " << m->tip << " " << m->status<<endl;
			char ch = _getch();
		}
		if ((*i)->comanda == "bauturi")
		{
			cout<<(*i)->comanda<<" ";
			bauturi *m = (bauturi*)(*i);
			cout << m->tip << " " << m->numar_sticle << m->status<<endl;
			char ch = _getch();
		}
	}
}
void cautare()
{
	string comanda;
	cout << "Introduceti comanda pe care doriti sa o cautati:"; cin >> comanda;
	for (i = l.begin(); i!= l.end(); i++)
	{
		if ((*i)->comanda == "pizza")
		{
			cout << (*i)->comanda << " ";
			pizza *m = (pizza*)(*i);
			cout << m->dimensiune << " " << m->mese << " " << m->sosuri << " " << m->tip << " " << endl;
		}
		if ((*i)->comanda == "paste")
		{
			cout << (*i)->comanda << " ";
			paste *m = (paste*)(*i);
			cout << m->portie << " " << m->mese << " " << m->sosuri << " " << m->tip << " " << endl;
		}
		if ((*i)->comanda == "bauturi")
		{
			cout << (*i)->comanda << " ";
			bauturi *m = (bauturi*)(*i);
			cout << m->tip << " " << m->numar_sticle << endl;
		}
	}
}
void numarare()
{
	//Eu nu inteleg cerinta aceasta deoarece este ambigua:) Sa imi fie cu iertare:D
	int cerinta_ambigua=0,cerinta_ambigua1=0,cerinta_ambigua2=0;
	for (i = l.begin(); i != l.end(); i++)
	{
		if ((*i)->comanda == "pizza")
		    cerinta_ambigua++;
		if ((*i)->comanda == "paste")
			cerinta_ambigua1++;
		if ((*i)->comanda == "bauturi")
			cerinta_ambigua2++;
	}
	if (cerinta_ambigua != 0)
		cout << "Numarul comenzilor de tip pizza este:" << cerinta_ambigua << endl;
	else
		if (cerinta_ambigua1 != 0)
			cout << "Numarul comenzilor de tip paste este:" << cerinta_ambigua1 << endl;
		else
			if (cerinta_ambigua2 != 0)
				cout << "Numarul comenzilor de tip bauturi este:" << cerinta_ambigua2 << endl;
			else
				cout << "Nu avem nici o comanda pe stoc\n";
}
void stergere() {
	int okay;
	string comanda,tip;
	cout << "Introduceti comanda pe care doriti sa o anulati:"; cin >> comanda;
	cout << "Introduceti tipul comenzii pe care doriti sa o anulati:"; cin >> tip; 
			for(i = l.begin(); i != l.end(); i++)
			{
				restaurant *sterge = (restaurant*)*i;
				pizza *tip_sters = (pizza*)(*i);
				paste *tip_paste = (paste*)(*i);
				bauturi *tip_bauturi = (bauturi*)(*i);

				if (sterge->comanda == comanda)
				{
					
					
					if (comanda == "pizza")
					{
						
						if (tip_sters->tip == tip)
						{
							i = l.erase(i);
							cout << "Comanda eliminata\n";
							char ch = _getch();
							return;
							
						}
					}
					if (comanda == "paste") {
						
						if (tip_paste->tip == tip)
						{
							i = l.erase(i);
							cout << "Comanda eliminata\n";
							char ch = _getch();
							return;
							
						}
					}
					if (comanda == "bauturi")
					{
						
						if (tip_bauturi->tip == tip)
						{
							i = l.erase(i);
							cout << "Comanda eliminata\n";
							char ch = _getch();
							return;
						}
					}
				}
			}

}
int main()
{
	int opt;
	string status;
	string comanda;
	do{
		system("CLS");
		cout << "0.Iesire\n";
		cout << "1.Citire\n";
		cout << "2.Afisare\n";
		cout << "3.Cautare\n";
		cout << "4.Numarare\n";
		cout << "5.Anulare comanda\n";
		cout << "6.Schimbare status\n ";
		cout << "Introduceti optiunea dumneavostra:"; cin >> opt;
		switch (opt)
		{
		case 0:
			exit(0);
			break;
		case 1:
			citire();
			break;
		case 2:
			afisare();
			break;
		case 3:
			cautare();
			break;
		case 4:
			numarare();
			break;
		case 5:
			stergere();
		case 6:
			cout << "Introduceti noul status:"; cin >> status;
			cout << "Introduceti comanda:"; cin >> comanda;
			for (i = l.begin(); i != l.end(); i++) {
				restaurant *m = (restaurant*)*i;
				if(m->comanda==comanda)
				m->schimbare_status(status);
			}
			break;
		default:cout << "Alegeti alta optiune\n";
			break;
		}
	} while (opt != 0);



	return 0;
}