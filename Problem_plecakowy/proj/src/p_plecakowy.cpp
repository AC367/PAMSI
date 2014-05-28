#include "p_plecakowy.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w programie.
 */

void Uruchom(int ilosc_elementow, int pojemnosc_plecaka)
{
	Przedmiot zerowy, pierwszy, drugi, trzeci, czwarty, piaty;
	Glowna g;
	
	zerowy.Wartosci(0, 0, 0);
	pierwszy.Wartosci(1, 1, 1);
	drugi.Wartosci(2, 2, 3);
	trzeci.Wartosci(3, 1, 2);
	czwarty.Wartosci(4, 2, 2);
	//piaty.Wartosci(5, 1, 3);
	
	g._wektor_p.push_back(zerowy);
	g._wektor_p.push_back(pierwszy);
	g._wektor_p.push_back(drugi);
	g._wektor_p.push_back(trzeci);
	g._wektor_p.push_back(czwarty);
	//g._wektor_p.push_back(piaty);
	
	cout<<"Zaczynam rozwiazywanie"<<endl;
	
	g.Rozwiaz(ilosc_elementow, pojemnosc_plecaka);
}

void Przedmiot::Wartosci(int numer, int wartosc, int waga)
{
	_numer=numer;
	_wartosc=wartosc;
	_waga=waga;
}

void Glowna::Rozwiaz(int ilosc_elementow, int pojemnosc_plecaka)
{
	Pole_tablicy poprzedni_i, poprzedni_j;
	Pole_tablicy obecny;
	
	_ilosc_elementow=ilosc_elementow;
	_pojemnosc_plecaka=pojemnosc_plecaka;
	
	for(int i=0; i<=_ilosc_elementow; i++)
	{
		for(int j=0; j<=_pojemnosc_plecaka; j++)
		{
			if(_wektor_p[i]._waga>j)
			{
				if(i>0)
					_tab_rozw[i][j]=_tab_rozw[i-1][j];
				else
				{
					_tab_rozw[i][j]._suma_wart=0;
					_tab_rozw[i][j]._wybrane_przedmioty.push_back(0);
				
				}
			}
			else
			{
				if(i>0)
				{
					poprzedni_i=_tab_rozw[i-1][j];
					poprzedni_i._suma_wart=Oblicz_wartosc(poprzedni_i);
					poprzedni_j=_tab_rozw[i-1][j-_wektor_p[i]._waga];
					poprzedni_j._suma_wart=Oblicz_wartosc(poprzedni_j);
					poprzedni_j._suma_wart+=_wektor_p[i]._wartosc;
					if(poprzedni_j>poprzedni_i)
					{
						_tab_rozw[i][j]=poprzedni_j;
						_tab_rozw[i][j]._wybrane_przedmioty.push_back(i);
					}
					else
					{
						_tab_rozw[i][j]=poprzedni_i;
					}
				}
			}
		}
	}
	
	cout<<"Wybrane przedmioty: "<<endl;
	
	for(unsigned int i=0; i<_tab_rozw[_ilosc_elementow][_pojemnosc_plecaka]._wybrane_przedmioty.size(); i++)
		cout<<_tab_rozw[_ilosc_elementow][_pojemnosc_plecaka]._wybrane_przedmioty[i]<<" ";
	
	cout<<endl;
}

int Glowna::Oblicz_wartosc(Pole_tablicy pole)
{
	int wartosc=0;
	
	for(unsigned int i=0; i<pole._wybrane_przedmioty.size(); i++)
	{
		wartosc+=_wektor_p[pole._wybrane_przedmioty.size()]._wartosc;
	}
	return wartosc;
}

bool Pole_tablicy::operator > (const Pole_tablicy & pole)
{
	if(_suma_wart>pole._suma_wart)
		return true;
	else
		return false;
}

Pole_tablicy Pole_tablicy::operator = (const Pole_tablicy & pole)
{
	_suma_wart=pole._suma_wart;
	
	_wybrane_przedmioty.clear();
	
	for(unsigned int i=0; i<pole._wybrane_przedmioty.size(); i++)
	{
		_wybrane_przedmioty.push_back(pole._wybrane_przedmioty[i]);
	}
	return *this;
}
