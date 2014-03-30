#include "sortowanie.hh"



/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w programie.
 */

istream& operator >> (istream &in, Dane& wekt)
{
	int tmp, wartosc;
	
	in>>tmp;
	wekt.Wektor.push_back(tmp);
	for (int i=0; i<tmp; i++)
	{
		in>>wartosc;
		wekt.Wektor.push_back(wartosc);
		
	}
	return in;
}	

ostream& operator << (ostream &out, const Dane& wekt)
{	
	for(vector<int>::const_iterator Iter=wekt.Wektor.begin()+1; Iter<wekt.Wektor.end(); ++Iter)
		out << *Iter << endl;
	return out;
}

void Dane::Wczytywanie(const char *nazwa, Dane& wekt)
{
	fstream plik;
	
	plik.open(nazwa, ios::in);
	if(!plik.is_open())
		cout<<"Nie udalo sie otworzyc pliku!"<<endl;
	plik>>wekt;
}

void Dane::Mnozenie(Dane& wekt)
{
	int wielkosc=wekt.Wektor[0];
	Dane wekt_wynik;
	
	wekt_wynik.Wektor.push_back(wielkosc);
	for(int i=1; i<=wielkosc; i++)
	{
		wekt_wynik.Wektor.push_back(wekt.Wektor[i]*2);
	}
	wekt.Wektor.clear();
	for(int i=0; i<=wielkosc; i++)
	{
		wekt.Wektor.push_back(wekt_wynik.Wektor[i]);
	}
}

bool Dane::Porownanie(Dane wekt1, Dane wekt2)
{
	for(int i=1; i<wekt1.Wektor[0]; i++)
	{
			if(wekt1.Wektor[i]==wekt2.Wektor[i])
			{
				continue;
			}
			else
			{
				cout<<"Wyniki rozne od pliku porownawczego "<<endl;
				cout<<"Ustaw ilosc powtorzen algorytmu na 1 i sprobuj jeszcze raz"<<endl;
				return false;
			}
	}
	cout<<"Wyniki zgodne z plikiem porownawczym"<<endl;
	return true;
}

void Dane::Zamien_elementy (Dane& wekt, int pierwszy_el, int drugi_el)
{
	int tmp, tmp2;
	
	tmp=wekt.Wektor[pierwszy_el];
	tmp2=wekt.Wektor[drugi_el];
	wekt.Wektor[pierwszy_el]=tmp2;
	wekt.Wektor[drugi_el]=tmp;
}

void Dane::Odwroc_kolejnosc (Dane& wekt)
{
	int wielkosc;
	Dane wektor_temp;
	
	wielkosc=wekt.Wektor[0];
	wektor_temp.Wektor.reserve(wielkosc);
	for(int j=1; j<=wielkosc; j++)
	{
		wektor_temp.Wektor[j]=wekt.Wektor[j];
	}
	for(int j=1; j<=wielkosc; j++)
	{
		wekt.Wektor[j]=wektor_temp.Wektor[wielkosc-j+1];
	}
}

void Dane::Dodaj_element (Dane &wekt, int element)
{
	wekt.Wektor.push_back(element);
}

void Dane::Dodaj_elementy (Dane &wekt1, Dane wekt2)
{
	int wielkosc2;
	
	
	wielkosc2=wekt2.Wektor[0];
	
	for(int i=1; i<=wielkosc2; i++)
	{
		wekt1.Wektor.push_back(wekt2.Wektor[i]);
	}
}

bool Dane::operator == (Dane wekt2)
{
	int rozmiar1, rozmiar2;
	
	
	rozmiar1=Wektor[0];
	rozmiar2=wekt2.Wektor[0];
	if(rozmiar1==rozmiar2)
	{
		for(int i=1; i<=rozmiar1; i++)
		{
			if(Wektor[i]==wekt2.Wektor[i])
				continue;
			else
			{
				cout<<"Wektory nie sa takie same."<<endl;
				return false;
			}
		}
	}
	else
	{
		cout<<"Wektory sa roznych wielkosci! Nie mozna ich porownac."<<endl;
		return false;
	}
	return true;
}

Dane Dane::operator = (Dane wekt2)
{
	int rozmiar;
	
	Wektor.clear();
	rozmiar=wekt2.Wektor[0];
	for(int i=0; i<=rozmiar; i++)
	{
		Wektor.push_back(wekt2.Wektor[i]);
	}
	return wekt2;
}

Dane Dane::operator + (Dane wekt2)
{
	int wielkosc1, wielkosc2, rozmiar;
	Dane wynik;
	
	wielkosc1=Wektor[0];
	wielkosc2=wekt2.Wektor[0];
	rozmiar=wielkosc1+wielkosc2;
	
	for(int i=1; i<=wielkosc2; i++)
	{
		Wektor.push_back(wekt2.Wektor[i]);
	}
	Wektor[0]=rozmiar;
	for(int i=0; i<=rozmiar; i++)
	{
		wynik.Wektor.push_back(Wektor[i]);
	}
	return wynik;
}

void Zapis (double czas_sredni, int ilosc_powt, int ilosc_elementow)
{
	ofstream plik_zapisany;
	
	plik_zapisany.open("Wynik_quicksort.csv", ios::app);
	//plik_zapisany<<"Ilosc elementow;"<<"Ilosc powtorzen algorytmu;"<<"Sredni czas wykonywania algorytmu;"<<endl;
	plik_zapisany<<ilosc_elementow<<";"<<ilosc_powt<<";"<<czas_sredni<<";sekund;"<<endl;
	
	plik_zapisany.close();
}

double Uruchom(int ilosc_powtorzen, Dane wektor1, Dane wektor2)
{
	clock_t s,f;
	double czas=0;
	int pierwszy_el, drugi_el, element;
	Stos_tablica stos_tablica;
	Stos_lista stos_lista;
	Kolejka_tablica kolejka_tablica;
	Kolejka_lista kolejka_lista;
	Dane wektor_p=wektor1;
	
	//********ELEMENTY INTERFEJSU WLACZANE DO PROGRAMU W ZALEZNOSCI OD TESTOWANEJ FUNKCJI********
	//cout<<endl<<"Podaj element, ktory ma zostac dodany do wektora: ";
	//cin>>element;
	//cout<<endl<<"Podaj elementy do zamiany"<<endl;
	//cout<<"Pierwszy element: ";
	//cin>>pierwszy_el;
	//cout<<endl<<"Drugi element: ";
	//cin>>drugi_el;
	//********************************************************************************************
	
	s=clock();
	for(int i=0; i<ilosc_powtorzen; i++)
		sort_quicksort(wektor1, 1, wektor1.Wektor[0]+1);
		//sort_mergesort(wektor1, wektor_p, 1, wektor1.Wektor[0]);
		//sort_heapsort(wektor1, wektor1.Wektor[0]);
	f=clock();
	//cout<<endl<<"Wektor koncowy: "<<endl<<wektor1<<endl<<endl;
	wektor1.Porownanie(wektor1, wektor2);
	czas=(double)(f-s)/(double)(CLOCKS_PER_SEC);
	cout<<endl<<endl<<"CZAS: "<<czas<<" sekund"<<endl;
	return czas;
}
/*
void Generator(int ilosc_liczb)
{
	ofstream plik;
	int losowa;
	
	plik.open("generowany.txt");
	plik<<ilosc_liczb<<endl;
	srand((int)time(NULL));
	for(int i=0; i<ilosc_liczb; i++)
	{
		losowa=rand()% ilosc_liczb+1;
		plik<<losowa<<endl;
	}
	plik.close();
}
*/
