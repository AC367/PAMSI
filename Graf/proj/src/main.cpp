#include "graf.hh"

/*!
 * \mainpage
 * Wykonal Arkadiusz Cyktor, numer indeksu: 200367.
 * 
 * Program ma za zadanie przedstawić realizację grafu oraz algorytmów wyszukujących
 * DFS, BFS oraz A*.
 */
 
 /*!
 * \file
 * \brief Zawiera definicje glownej funkcji programu.
 */



int main()
{
	Graf graf;
	int poczatkowy=0;
	clock_t s,f;
	double czas=0;
	//int wierzcholek;
	
	//cout<<"Podaj wierzcholek:"<<endl;
	//cin>>wierzcholek;
	/*
	graf.Dodaj_wierzcholek(0);//wierzcholek);
	graf.Wypisz_macierz();
	
	graf.Dodaj_wierzcholek(1);
	graf.Wypisz_macierz();
	graf.Dodaj_wierzcholek(2);
	graf.Dodaj_krawedz(0, 1, 1);
	graf.Dodaj_krawedz(1, 2, 1);
	graf.Wypisz_macierz();
	//graf.Usun_krawedz(1, 2);
	//graf.Wypisz_macierz();
	graf.Sasiedztwo(1);
	if(graf.Czy_istnieje(1))
		cout<<"Wierzcholek numer 1 istnieje"<<endl;
	graf.Usun_wierzcholek(1);
	if(!graf.Czy_istnieje(1))
		cout<<"Wierzcholek numer 1 nie istnieje"<<endl;
	graf.DFS(poczatkowy, 2);
	graf.BFS(poczatkowy, 1);
	*/
	for(int i=0; i<30; i++)
		graf.Dodaj_wierzcholek(i, 1, 1);
	//for(int i=0; i<7; i++)
		//graf.Dodaj_krawedz(i, i+1, rand() % 10 +1);
	for(int i=0; i<29; i++)
		graf.Dodaj_krawedz(rand() % 29,rand() % 29,1);
	/*
	graf.Dodaj_krawedz(0, 1, 1);
	graf.Dodaj_krawedz(1, 2, 3);
	graf.Dodaj_krawedz(2, 4, 6);
	graf.Dodaj_krawedz(1, 3, 2);
	graf.Dodaj_krawedz(3, 7, 5);
	graf.Dodaj_krawedz(7, 5, 1);
	graf.Dodaj_krawedz(5, 6, 2);
	graf.Dodaj_krawedz(6, 8, 1);
	graf.Dodaj_krawedz(2, 5, 1);*/
	
/*	graf.Dodaj_wierzcholek(0,1,1);
	graf.Dodaj_wierzcholek(1,1,7);
	graf.Dodaj_wierzcholek(2,3,2);
	graf.Dodaj_wierzcholek(3,7,4);
	graf.Dodaj_wierzcholek(4,5,5);
	graf.Dodaj_wierzcholek(5,9,3);
	graf.Dodaj_wierzcholek(6,2,4);
	graf.Dodaj_wierzcholek(7,3,6);
	graf.Dodaj_wierzcholek(8,6,2);
	graf.Dodaj_krawedz(0, 2, 4);
	graf.Dodaj_krawedz(2, 4, 3);
	graf.Dodaj_krawedz(4, 3, 3);
	graf.Dodaj_krawedz(8, 5, 1);
	graf.Dodaj_krawedz(5, 3, 7);
	graf.Dodaj_krawedz(4, 1, 2);
	graf.Dodaj_krawedz(1, 6, 2);
	graf.Dodaj_krawedz(6, 7, 4);
	graf.Dodaj_krawedz(7, 8, 4);
	graf.Dodaj_krawedz(7, 3, 5);
	*/
	//graf.Wypisz_macierz();
	
	int ilosc_powt=100000;
	
	s=clock();
	
	
	for(int i=0; i<ilosc_powt; i++)
	{
		//graf.A_star(poczatkowy, 5);
		//graf.DFS(poczatkowy, 5);
		graf.BFS(poczatkowy, 5);
	}
	f=clock();
	
	czas=(double)(f-s)/(double)(CLOCKS_PER_SEC);
	cout<<endl<<endl<<"CZAS: "<<czas<<" sekund"<<endl;

	double czas_sredni=czas/ilosc_powt;
	
	cout<<endl<<endl<<"CZAS SREDNI: "<<czas_sredni<<" sekund"<<endl;

	ofstream plik_zapisany;
	
	plik_zapisany.open("Wynik_BFS.csv", ios::app);
	plik_zapisany<<ilosc_powt<<";"<<czas_sredni<<";sekund;"<<endl;
	
	plik_zapisany.close();

	
	return 0;
} 


