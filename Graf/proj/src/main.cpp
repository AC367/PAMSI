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
	
	srand(time(NULL));
	
	int ilosc_wierzcholkow=10;
	int ilosc_krawedzi=9;
	int ilosc_powt=1;
	
	for(int i=0; i<ilosc_wierzcholkow; i++)
		graf.Dodaj_wierzcholek(i, rand() %100, rand() %100);
	for(int i=0; i<ilosc_krawedzi; i++)
		graf.Dodaj_krawedz(rand() %ilosc_krawedzi,rand() % ilosc_krawedzi,1);
	
	graf.Wypisz_macierz();

	for(int i=0; i<ilosc_powt; i++)
	{
		wynik=graf.A_star(poczatkowy, 5);
		//graf.DFS(poczatkowy, 5);
		//graf.BFS(poczatkowy, 5);
	}

	return 0;
} 


