#include "stos_tablica.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzywanych przez stos zaimplementowana
 * przy pomocy listy - klasa Stos_lista.
 */

Stos_lista::Stos_lista()
{
	_pierwszy=NULL;
}

Stos_lista::~Stos_lista() 
{ 	
	if (_pierwszy==NULL) 
		return;
	else
	{	
		Element_stosu* tmp=new Element_stosu(); 	
		
		while(_pierwszy)
		{
			tmp=_pierwszy;
			_pierwszy=tmp->_nastepny;
			delete tmp;
		}
	}
}

void Stos_lista::Push(Dane wekt)
{	
	for(int i=1; i<=wekt.Wektor[0]; i++)
	{
		Element_stosu *nowy=new Element_stosu();
		nowy->_wartosc=wekt.Wektor[i];
		if(_pierwszy==0)
			_pierwszy=nowy;
		else
		{
			Element_stosu *temp=_pierwszy;
			while(temp->_nastepny)
			{
				temp=temp->_nastepny;
			}
			nowy->_nastepny=_pierwszy;
			_pierwszy=nowy;
		}
	}
}

int Stos_lista::Pop()
{	
	int liczba;
	Element_stosu* element=_pierwszy;
	
	if(_pierwszy==NULL)
		cout<<endl<<"BLAD! Stos pusty. Nie mozna usunac elementu."<<endl;
	_pierwszy=_pierwszy->_nastepny;
	liczba=element->_wartosc;
	delete(element);
	return liczba;
}

bool Stos_lista::IsEmpty() 
{ 	
	if(_pierwszy==NULL)
		return true;
	else
		return false;
}

void Stos_lista::Wypisz()
{
	Element_stosu *temp=new Element_stosu();
	
	temp=_pierwszy;
	cout<<"Zawartosc stosu: "<<endl;
	while(temp)
	{
		cout<<temp->_wartosc<<endl;
		temp=temp->_nastepny;
	}
}

void Stos_lista::Wielkosc_stosu()
{
	Element_stosu *temp=new Element_stosu();
	int licznik=0;
	
	temp=_pierwszy;
	while(temp)
	{
		temp=temp->_nastepny;
		licznik++;
	}
	cout<<"Wielkosc stosu: "<<licznik<<endl;
}
