#include "sortowanie.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzywanych przez kolejke zaimplementowana
 * przy pomocy listy - klasa Kolejka_lista.
 */

Kolejka_lista::Element_kolejki::Element_kolejki()
{
	nastepny=0;
}

Kolejka_lista::Kolejka_lista()
{
	pierwszy=0;
}

Kolejka_lista::~Kolejka_lista()
{ 	
	if (pierwszy==0) 
		return;
	else
	{	
		Element_kolejki* tmp=new Element_kolejki(); 	
		
		while(pierwszy)
		{
			tmp=pierwszy;
			pierwszy=tmp->nastepny;
			delete tmp;
		}
	}
}

void Kolejka_lista::Enqueue(Dane wekt)
{
	for(int i=1; i<=wekt.Wektor[0]; i++)
	{
		Element_kolejki *nowa=new Element_kolejki;
		
		nowa->wartosc=wekt.Wektor[i];
		if(pierwszy==0)
			pierwszy=nowa;
		else
		{
			Element_kolejki *temp=pierwszy;
			
			while(temp->nastepny)
				temp=temp->nastepny;
			temp->nastepny=nowa;
			nowa->nastepny=0;
		}
	}
}

void Kolejka_lista::Dequeue()
{
	Element_kolejki *temp = pierwszy;
	
    if (temp->nastepny->nastepny==0)
    {
		temp->nastepny=0;
	}
	if (temp->nastepny==0)
	{
		pierwszy=0;
	}
	else
		pierwszy=temp->nastepny;
}

void Kolejka_lista::Wyswietl()
{
	Element_kolejki *temp=pierwszy;

	cout<<"Zawartosc kolejki: "<<endl;
    while(temp)
    {
        cout<<temp->wartosc<<endl;
        temp=temp->nastepny;
    }
}

bool Kolejka_lista::IsEmpty() 
{ 	
	if(pierwszy==NULL)
		return true;
	else
		return false;
}

void Kolejka_lista::Size()
{
Element_kolejki *temp=new Element_kolejki();
	int licznik=0;
	
	temp=pierwszy;
	while(temp)
	{
		temp=temp->nastepny;
		licznik++;
	}
	cout<<"Wielkosc kolejki: "<<licznik<<endl;
}
