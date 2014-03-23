#include "sortowanie.hh"

/*!
 * \mainpage
 * Wykonal Arkadiusz Cyktor, numer indeksu: 200367.
 * 
 * Program ma za zadanie wczytac dane wejsciowe z pliku, wykonac zadany
 * algorytm (dostepnych jest kilka funkcji, aby wybrac ktoras z nich
 * nelzy usunac komentarz)a nastepnie porownac otrzymane wyniki z 
 * rozwiazaniami zawartymi w pliku wzorcowym. Na koniec ma zostac podany
 * czas realizacji algorytmu.
 * 
 * \section etykieta-Wazne-cechy Najwazniejsze chechy
 * Interakcja programu z uzytkownikiem ogranicza sie do podania przez
 * tego drugiego zadanej ilosci powtorzen wykonania algorytmu oraz
 * ilosci liczb, na ktorych ma on pracowac, dlasza czesc wykonywana jest
 * automatycznie i konczy sie wyswietleniem wyniku (w przypadku mnozenia
 * duza ilosc powtorzen moze powodowac wyswietlenie samych zer, poniewaz
 * wartosci sa zbyt duze) oraz czasu trwania calej operacji.
 * Dokladniejsze dane, takie jak sredni czas pojedynczego wykonania
 * algorytmu, ilosc liczb oraz liczbe powtorzen algorytmu, zostaja
 * zapisane do pliku csv o nazwie Wynik. 
 * 
 * Poprawnosc realizacji poszczegolnych moze byc kontrolowana przez
 * wyswietlanie stosownych komunikatow, domyslnie sa one "wykomentowane",
 * jendak nic nie stoi na przeszkodzie, aby przed kompilacja usunac
 * znaczniki komentarzy. Takie rozwiazanie powoduje kilka ostrzezen
 * podczas kompilacji, mowiacych o nieuzytych zmiennych, znikaja one
 * po "odkomentowaniu" poszczegolnych petli. 
 * 
 * Zalaczony plik porownawczy stworzony jest z mysla o algorytmie 
 * mnozenia, dla pojedynczej jego realizacji oraz dzialania na 10 wartosciach.   
 * 
 * Pomiar czasu dokonywany jest przy uzyciu odpowiednio
 * zaimplementowanej funkcji clock(). Wynik pomiaru wswietlany na
 * wyjsciu podawany jest w sekundach, z dokladnoscia do 0.01.
 * 
 * Mierzony jest tylko czas wykonania danego algorytmu. Okres ten jest
 * tak maly, ze zostaje przez program zaokraglony do zera, aby uzyskac 
 * inne wartosci nalezy powtarzac mnozenie kilka tysiecy razy.
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
 * funkcji uruchamiajacej algorytm oraz czesciowa komunikacje z
 * uzytkownikiem i kontrole bledow.
 */ 
int main()
{	
	Dane wektor1, wektor2, wekt_tmp;
	int ilosc_powtorzen, ilosc_elementow, ilosc_liczb;
	double czas, czas_sredni;
	
	cout<<endl<<"Podaj ilosc powtorzen algorytmu: ";
	cin>>ilosc_powtorzen;
	miejsce_skoku1:
	if(ilosc_powtorzen<=0)
	{
		cout<<"Ilosc powtorzen musi wynosic przynajmniej 1"<<endl;
		cout<<"Podaj ilosc powtorzen algorytmu: ";
		cin>>ilosc_powtorzen;
		goto miejsce_skoku1;
	}
	wektor1.Wczytywanie("sortowanie.txt", wektor1);
	wekt_tmp=wektor1;
	ilosc_elementow=wektor1.Wektor[0];
	wektor2.Wczytywanie("plik2.txt", wektor2);
	cout<<endl<<"Ile liczb ma sie znalezc w pliku?: ";
	cin>>ilosc_liczb;
	miejsce_skoku2:
	if(ilosc_liczb!=ilosc_elementow && ilosc_liczb>0)
	{
		if(ilosc_liczb>ilosc_elementow)
		{
			for(int i=1; i<=(ilosc_liczb-ilosc_elementow)/10; i++)
			{
				wektor1=wektor1+wekt_tmp;
			}
		}
		else if(ilosc_liczb<ilosc_elementow)
		{
			wektor1.Wektor[0]=ilosc_liczb;
			for(int i=0; i<=ilosc_liczb; i++)
			{
				wektor1.Wektor.pop_back();
			}
		}
	}
	if(ilosc_liczb<=0)
	{
		cout<<"Ilosc liczb moze wynosic od 1 do 10 lub wielokrotnosci dziesiatki"<<endl;
		cout<<"Ile liczb ma sie znalezc w pliku?: ";
		cin>>ilosc_liczb;
		goto miejsce_skoku2;
	}
	
	//cout<<"Wektor pierwszy po wczytaniu: "<<endl<<wektor1<<endl<<endl;
	//cout<<"Wektor drugi po wczytaniu: "<<endl<<wektor2<<endl<<endl;
	czas=Uruchom(ilosc_powtorzen, wektor1, wektor2);
	czas_sredni=czas/ilosc_powtorzen;
	Zapis(czas_sredni, ilosc_powtorzen, ilosc_liczb);
	return 0;
}
