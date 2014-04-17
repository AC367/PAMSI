#include "funkcje.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w programie.
 */

int* Wczytywanie(const char *nazwa)
{
	fstream plik;
	int wielkosc;

	plik.open(nazwa, ios::in);
	plik>>wielkosc;

	int *tablica= new int[wielkosc];

	tablica[0]=wielkosc;
	
	cout<<endl<<endl<<"TABLICA PO WCZYTANIU:"<<endl;
	for(int i=1; i<=wielkosc; i++)
	{
		plik>>tablica[i];
		cout<<"Wartosc numer "<<i<<" wynosi "<<tablica[i]<<endl;
	}
	plik.close();
	return tablica;
}

int* Mnozenie(int tablica[])
{
	int wielkosc=0;
	wielkosc=tablica[0];
	cout<<endl<<"TABLICA PO MNOZENIU:"<<endl;
	for(int i=1; i<=wielkosc; i++)
		{
			tablica[i]=tablica[i]*2;
			cout<<"Wartosc numer "<<i<<" wynosi "<<tablica[i]<<endl;
		}
	return tablica;	
}

bool Porownanie(int wynik[], int porownanie[])
{
	int wielkosc=porownanie[0];
	for(int i=1; i<=wielkosc; i++)
	{
		if (wynik[i]==porownanie[i])
		{
			continue;
		}
		else
		{
			return false;
			cout<<endl<<"Wystapil blad! Wyniki rozne od spodziewanych."<<endl;
		}
	}
	return true;
}
