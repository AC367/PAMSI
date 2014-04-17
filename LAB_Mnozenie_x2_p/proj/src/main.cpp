#include "funkcje.hh"

/*!
 * \mainpage
 * Wykonal Arkadiusz Cyktor, numer indeksu: 200367.
 * 
 * Program ma za zadanie wczytac dane wejsciowe z pliku, wykonac zadany
 * algorytm, ktory w tym wypadku mnozy wczytane liczby przez 2,
 * a nastepnie porownac otrzymane wyniki z rozwiazaniami zawartymi
 * w pliku wzorcowym. Na koniec ma zostac podany czas realizacji
 * algorytmu.
 * 
 * \section etykieta-Wazne-cechy Najwazniejsze chechy
 * Poprawnosc realizacji poszczegolnych krokow jest kontrolowana przez
 * wyswietlanie stosownych komunikatow.
 * 
 * Pomiar czasu dokonywany jest przy uzyciu odpowiednio
 * zaimplementowanej funkcji clock(). Wynik pomiaru wswietlany na
 * wyjsciu podawany jest w sekundach, z dokladnoscia do 0.01.
 * 
 * Mierzony jest tylko czas wykonania algorytmu mnozenia. Okres ten jest
 * tak maly, ze zostaje przez program zaokraglony do zera, aby uzyskac 
 * inne wartosci nalezy powtarzac mnozenie co najmniej 200000 razy (0.01s).
 * 
 */
 
 /*!
 * \file
 * \brief Zawiera definicje glownej funkcji programu.
 */

/*!
 * \brief Wywoluje odpowiednie funkcje
 * 
 * Jest to glowna funkcja programu odpowiedzialna za wywolanie
 * w odpowiedniej kolejnosci innych funkcji z okreslonymi parametrami.
 * Odpowiada rowniez za informowanie uzytkownika o poprawnosci wyniku
 * oraz czasie dzialania algorytmu mnozenia.
 */ 
int main()
{
	clock_t s,f;
	double czas=0;
	int *tablicamnozona;
	fstream plikporown;
	int wielkosc=10;
	int *tablicaporown;
	
	tablicamnozona=Wczytywanie("plik1.txt");
	s=clock();
	//for(int i=0; i<=200000; i++)
	tablicamnozona=Mnozenie(tablicamnozona);
	f=clock();
	tablicaporown=Wczytywanie("plik2.txt");
	if(Porownanie(tablicamnozona, tablicaporown)==true)
		cout<<endl<<endl<<"WYNIK POPRAWNY"<<endl;
	else
		cout<<endl<<endl<<"BLAD!"<<endl;

	czas=(double)(f-s)/(double)(CLOCKS_PER_SEC);
	cout<<endl<<endl<<"CZAS: "<<czas<<" sekund"<<endl;
	
	return 0;
}
