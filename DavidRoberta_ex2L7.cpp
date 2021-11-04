#include	<iostream>
#include	<conio.h>
#include	<string>
using namespace std;

class Carte {
private:
	static Carte * head;
	Carte *next;
	string titlu, numeAutori, editura;
	unsigned short anPub;
public:
	~Carte(){}
	Carte(){}
	Carte(string, string, string, unsigned short);
	friend ostream &operator<<(ostream &iesire, Carte &Carte);
	friend istream &operator>>(istream &in, Carte &Carte);
};
Carte * Carte :: head = NULL;
Carte::Carte(string titlu, string numeAutori, string editura, unsigned short anPub) {
	this->titlu = titlu;
	this->numeAutori = numeAutori;
	this->editura = editura;
	this->anPub = anPub;
	this->next = NULL;
	this->next = NULL;
	if (head == NULL) {
		head = this;
		return;
	}
	if (head->titlu > this->titlu) {
		this->next = head;
		head = this;
		return;
	}
	Carte *q = head;
	while (q->next && q->next->titlu < this->titlu) q = q->next;
	this->next = q->next;
	q->next = this;

}

ostream &operator<<(ostream &iesire, Carte &carte)
{   
	Carte* q = Carte::head;
	while (q) {
		iesire << "\nTitlu: " << q->titlu;
		iesire << "\nAutori: " << q->numeAutori;
		iesire << "\nEditura: " << q->editura;
		iesire << "\nAn publicare: " << q->anPub<<"\n";
		q = q->next;
	}
	
	return iesire;
}

istream &operator>>(istream &in, Carte &Carte)
{ 
	cout << "Titlu: ";			getline(in,  Carte.titlu);
	cout << "Autori: ";			getline(in,	 Carte.numeAutori);
	cout << "Editura: ";		getline(in,  Carte.editura);
	cout << "An publicare: ";	in	>> Carte.anPub;
	new ::Carte(Carte.titlu, Carte.numeAutori, Carte.editura, Carte.anPub);
	return in;
}

int main()
{
	int opt;
	Carte carte;
	do {
		cout << "\n1. Citire carte";
		cout << "\n2. Afisare carti";
		cout << "\n0. Iesire";
		cout << "\nIntroduceti optiunea aleasa: "; cin >> opt;
	
		system("cls");
		switch (opt)
		{
		case 0:return 0;
		case 1: getchar(); cin >> carte; break;
		case 2: cout << carte; break;
		default:
			break;
		}

	
	} while (1);
	getch();
	return 0;
}

