#include "kolejka_lista.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzywanych przez kolejke zaimplementowana
 * przy pomocy tablicy - klasa Kolejka_tablica.
 */

void Kolejka_tablica::Powieksz ()
{
	_rozmiar=Licznik_elementow;
	int* nowa_tablica=new int [_rozmiar+1];
	
	for (int i=0; i<_rozmiar; i++)
		nowa_tablica[i]=tab[i];
	_rozmiar=_rozmiar+1;
	delete []tab;
	tab=nowa_tablica;
}

void Kolejka_tablica::Dequeue()
{
 if (IsEmpty())
  throw "Kolejka jest pusta";
 for (unsigned int i=0; i<=(Licznik_elementow); i++)
  tab[i]=tab[i+1];
 Licznik_elementow--;
}

Kolejka_tablica::Kolejka_tablica()
{
	tab=new int [wartosc_pocz_kolejki];
	Licznik_elementow=0;
}

bool Kolejka_tablica::IsEmpty()
{
   return (Licznik_elementow == 0);
}

void Kolejka_tablica::Enqueue(Dane wekt)
{	
	for(int i=1; i<=wekt.Wektor[0]; i++)
	{
		Licznik_elementow++;
		tab[i-1] = wekt.Wektor[i];
		Powieksz();
	}
}

void Kolejka_tablica::Wypisz()
{
cout<<"Zawartosc kolejki:"<<endl;
for(unsigned int i=0; i<Licznik_elementow; i++)
  cout<<tab[i]<<endl;
}

Kolejka_tablica::~Kolejka_tablica()
{
 delete []tab;
} 
