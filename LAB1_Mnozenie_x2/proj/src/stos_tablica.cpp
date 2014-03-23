#include "sortowanie.hh"


/*!
 * \file
 * \brief Zawiera definicje funkcji uzywanych przez stos zaimplementowana
 * przy pomocy tablicy - klasa Stos_tablica.
 */

Stos_tablica::Stos_tablica()
	: _szczyt(0), _rozmiar(wartosc_pocz)
{
	_tablica=new int [wartosc_pocz];
	_licznik=0;
}

Stos_tablica::~Stos_tablica()
{
	delete []_tablica;
}

void Stos_tablica::Push (Dane wekt)
{
	for(int i=1; i<=wekt.Wektor[0]; i++)
	{
	if (_szczyt==_rozmiar)
		Powieksz ();
	_tablica[_szczyt]=wekt.Wektor[i];
	++_szczyt;
	_licznik++;
	}
}

void Stos_tablica::Powieksz ()
{
	int* nowa_tablica=new int [_rozmiar+1];
	//int* nowa_tablica=new int [_rozmiar*2];
	for (int i=0; i<_rozmiar; i++)
		nowa_tablica[i]=_tablica[i];
	_rozmiar=_rozmiar+1;
	//_rozmiar=_rozmiar*2;
	delete []_tablica;
	_tablica=nowa_tablica;
}

void Stos_tablica::Pop()
{
	int* tmp=new int [_rozmiar-1];
	
	assert (_szczyt>0);
	--_szczyt;
	--_licznik;
	if(_szczyt<_rozmiar/2)
		_rozmiar=_rozmiar/2;
	for(int i=0; i<=_licznik; i++)
		tmp[i]=_tablica[i];
	delete []_tablica;
	_tablica=tmp;
}

bool Stos_tablica::IsEmpty()const
{
	assert (_szczyt>=0);
	if(_szczyt==0)
		return true;
	else
		return false;
}

void Stos_tablica::Wypisz()
{
	cout<<"Zawartosc stosu: "<<endl;
	for(int i=0; i<_licznik; i++)
	{
		cout<<_tablica[i]<<endl;
	}
}
