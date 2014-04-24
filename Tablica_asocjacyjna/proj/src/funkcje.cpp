#include "funkcje.hh"
#include <sstream>
#include "tablica_asocjacyjna.hh"
#include "drzewo_binarne.hh"
#include "tablica_haszujaca.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w programie.
 */

double Uruchom(int ilosc_elementow)
{
	clock_t s,f;
	double czas=0;
	Tablica_haszujaca hash(ilosc_elementow+10);
	Drzewo_binarne drzewo;
	TablicaAsocjacyjna<string> tab_a;
	
	for(int i=0; i<ilosc_elementow; i++)
	{
		ostringstream konw;
		konw<<i;
		string znak = konw.str();
		//hash.dodaj(znak,znak);
		//drzewo.dodaj(znak, znak);
		tab_a.DodajElement(znak, znak);
	}
	s=clock();
	/*if(drzewo.czy_jest("87"))
		cout<<"JEST!"<<endl;*/
	for(int i=0; i<ilosc_elementow; i++)
	{
		ostringstream konw;
		konw<<i;
		string znak = konw.str();
		//cout<<*hash[znak];
		cout<<tab_a[i]<<endl;
	}
	//drzewo.wyswietl_kolejno();
	f=clock();
	czas=(double)(f-s)/(double)(CLOCKS_PER_SEC);
	cout<<endl<<endl<<"CZAS: "<<czas<<" sekund"<<endl;
	Zapis(czas, ilosc_elementow);
	return czas;
}

void Zapis (double czas_sredni, int ilosc_elementow)
{
	ofstream plik_zapisany;
	
	plik_zapisany.open("Wynik_tablica_asoc.csv", ios::app);
	//plik_zapisany<<"Ilosc elementow;"<<"Ilosc powtorzen algorytmu;"<<"Sredni czas wykonywania algorytmu;"<<endl;
	plik_zapisany<<ilosc_elementow<<";"<<czas_sredni<<";sekund;"<<endl;
	
	plik_zapisany.close();
}

