#include "tablica_haszujaca.hh"

 /*!
 * \file
 * \brief Zawiera definicje metod klasy Tablica_haszujaca i Element.
 */

Tablica_haszujaca::Tablica_haszujaca(int il)
	{
		_element=new Element[il];
		rozmiar=il;
	}

void Tablica_haszujaca::dodaj(string nazwa, string dane)
{
	Element dodawany;
	int indeks=haszuj(nazwa);
	
	dodawany.adres=nazwa;
	dodawany.dane=dane;
	
	if(_element[indeks].zajety==true)
	{
		Element *nastepny=new Element;
		Element* pomocniczy=&_element[indeks];
		*nastepny=dodawany;
		while(pomocniczy->nastepny!=NULL) 
			pomocniczy=pomocniczy->nastepny;
		pomocniczy->nastepny=nastepny;
		nastepny->zajety=true;
	}
	else if(_element[indeks].zajety==false)
	{
		_element[indeks]=dodawany;
		_element[indeks].zajety=true;
	}
}

void Tablica_haszujaca::usun(string adres)
{
	znajdz(adres)->zajety=false;
}

int Tablica_haszujaca::haszuj(string adres)
{
	int indeks;
	int dlugosc=adres.size();
	for(int i=0;i<dlugosc;i++)
		indeks=(int)adres[i]*(i+1)%(rozmiar);
return indeks;
}
	
Element* Tablica_haszujaca::znajdz(string adres)
{
	int indeks=haszuj(adres);
	return &_element[indeks];
}

Element* Tablica_haszujaca::operator [](string adres)
{
	Element* pomocniczy=znajdz(adres);
	return pomocniczy;
}

ostream& operator <<(ostream& ostr, Element& elem)
{
	ostr<<"Adres: "<<elem.adres<<endl;
	while(elem.zajety!=false)
	{
		ostr<<"Wartosc: "<<elem.dane<<endl;
		if(elem.nastepny!=NULL)
			elem=*elem.nastepny;
		else
			return ostr;
	}
	return ostr;
}
