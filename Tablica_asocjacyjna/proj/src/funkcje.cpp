#include "funkcje.hh"
#include <sstream>
#include "tablica_asocjacyjna.hh"
#include "drzewo_binarne.hh"
#include "tablica_haszujaca.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w programie.
 */

double Uruchom(int ilosc_elementow, int ilosc_powtorzen)
{
	clock_t s,f;
	double czas=0;
	Tablica_haszujaca hash(ilosc_elementow+10);
	Drzewo_binarne drzewo;
	TablicaAsocjacyjna<string> tab_a;
	string szukane;
	int lewy=0;
	int prawy=tab_a.Rozmiar()-1;
	int pivot=5;
	char litera='a', litera2='z';	
	
	ostringstream il;
	il<<ilosc_elementow;
	szukane = il.str();
	
	for(int i=0; i<ilosc_elementow; i++)
	{
		ostringstream konw;
		konw<<i;
		string znak = konw.str();
		
		//hash.dodaj(znak,znak);
		//drzewo.dodaj(znak, znak);
		tab_a.DodajElement(znak, znak);
		//cout<<znak<<endl;
	}
	s=clock();
	/*if(drzewo.czy_jest("87"))
		cout<<"JEST!"<<endl;*/
	/*for(int i=0; i<ilosc_elementow; i++)
	{
		ostringstream konw;
		konw<<i;
		string znak = konw.str();
		//cout<<*hash[znak];
		cout<<tab_a[i]<<endl;
	}*/
	//drzewo.wyswietl_kolejno();
	for(int i=0; i<ilosc_powtorzen; i++)
	{
		tab_a.Wyszukaj(szukane, lewy, pivot, prawy);
		//drzewo.czy_jest(szukane);
		//hash.znajdz(szukane);
	}
	f=clock();
	czas=(double)(f-s)/(double)(CLOCKS_PER_SEC);
	double czas_sredni=czas/ilosc_powtorzen;
	cout<<endl<<endl<<"CZAS: "<<czas<<" sekund"<<endl;
	Zapis(czas_sredni, ilosc_elementow);
	return czas;
}

void Zapis (double czas_sredni, int ilosc_elementow)
{
	ofstream plik_zapisany;
	
	plik_zapisany.open("Wynik_tablica_asocjacyjna.csv", ios::app);
	//plik_zapisany<<"Ilosc elementow;"<<"Ilosc powtorzen algorytmu;"<<"Sredni czas wykonywania algorytmu;"<<endl;
	plik_zapisany<<ilosc_elementow<<";"<<czas_sredni<<";sekund;"<<endl;
	
	plik_zapisany.close();
}

