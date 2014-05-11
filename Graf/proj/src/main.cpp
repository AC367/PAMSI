#include "graf.hh"

/*!
 * \mainpage
 * Wykonal Arkadiusz Cyktor, numer indeksu: 200367.
 * 
 * Program ma za zadanie przedstawić realizację grafu oraz algorytmów wyszukujących
 * DFS i BFS.
 */
 
 /*!
 * \file
 * \brief Zawiera definicje glownej funkcji programu.
 */

int main()
{
	Graf graf;
	int poczatkowy=0;
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
	for(int i=0; i<40; i++)
		graf.Dodaj_wierzcholek(i);
	for(int i=0; i<39; i++)
		graf.Dodaj_krawedz(i, i+1, 1);
		
	graf.Wypisz_macierz();
	
	graf.DFS(poczatkowy, 28);
	graf.BFS(poczatkowy, 39);
	return 0;
} 
