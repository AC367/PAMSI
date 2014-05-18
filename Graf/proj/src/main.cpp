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
	int *tab;
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
	//for(int i=0; i<9; i++)
		//graf.Dodaj_wierzcholek(i);
	//for(int i=0; i<7; i++)
		//graf.Dodaj_krawedz(i, i+1, rand() % 10 +1);
	//for(int i=0; i<8; i++)
		//graf.Dodaj_krawedz(rand() % 8,rand() % 8,rand() % 10 +1);
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
	
	graf.Dodaj_wierzcholek(0,1,1);
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
	
	graf.Wypisz_macierz();
	
	graf.DFS(poczatkowy, 28);
	graf.BFS(poczatkowy, 39);
	//tab=graf.Sasiedztwo(4);

	graf.A_star(poczatkowy, 8);
	return 0;
} 
