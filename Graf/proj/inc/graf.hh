#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>

using namespace std;

/*!
 * \file
 * \brief Zawiera definicje klasy Graf, jej metody oraz 
 * polecenia załączenia niezbędnych bibliotek.
 */
 

/*!
 * \brief Klasa definiująca graf.
 * 
 * Klasa ta zawiera wewnętrzne struktury: _wierzcholek, _krawedz oraz _lista_BFT.
 * Dwie pierwsze odpowiadają za defniowanie wierzchołków i krawędzi grafu, a tarzecia
 * z nich tworzy listę jednokierunkową wykorzystywaną przez algorytm BFT.
 * W klasie Graf przechowywana jest też tablica sąsiedztwa oraz wektory
 * krawędzi i wierzchołków. Ponadto zawarte są w niej deklarace metod. 
 */ 
class Graf
{
	public:
	
	char ** _tab_sasiedztwa;
	//int *_tab_wierzcholkow;
	//int _liczba_wierzcholkow;
	
/*!
 * \brief Struktura realizująca wierzchołki grafu.
 * 
 * Struktura ta zawiera dwie zmienne typu bool, które przechowują informację
 * o istnieniu danego wierzchołka oraz o tym czy został on już odwiedzony przez
 * algorytm wyszukujący oraz pole przechowujące numer jego numer.
 */ 
	struct _wierzcholek
	{
		bool _czy_istnieje;
		bool _czy_odwiedzony;
		int _numer;
		//char _dane;
	};
	
/*!
 * \brief Struktura realizująca krawędzie grafu.
 * 
 * Struktura ta zawiera wskaźniki na wierzchołki, które łączy oraz zmienną
 * typu int przechowującą informację o wadze danej krawędzi.
 */ 
	struct _krawedz
	{
		_wierzcholek * pierwszy;
		_wierzcholek * drugi;
		int waga;
	};
	
/*!
 * \brief Struktura realizująca listę jednokierunkową dla algorytmu
 * wyszukującego BFT.
 * 
 * Struktura ta zawiera wskaźnik na następny element oraz pole typu int
 * przechowujące dane.
 */ 
	struct _lista_BFS
	{
		_lista_BFS * _nastepny;
		int _dane;
	};
	
	stack<int> _stos_DFS;
	vector<_wierzcholek> _wektor_wierzcholkow;
	vector<_krawedz> _wektor_krawedzi;

/*!
 * \brief Dodaje wierzchołek.
 * 
 * Metoda ta ma za zadanie dodać wierzchołek o zadanym numerze do grafu.
 * 
 * @param [in] v - numer dodawanego wierzchołka.
 */ 
	void Dodaj_wierzcholek(int v);
	
/*!
 * \brief Usuwa wierzchołek.
 * 
 * Metoda ta ma za zadanie usunąć wierzchołek o zadanym numerze z grafu.
 * 
 * @param [in] wierzcholek - numer usuwanego wierzchołka.
 */ 
	void Usun_wierzcholek(int wierzcholek);
	
/*!
 * \brief Dodaje krawędź.
 * 
 * Metoda ta ma za zadanie dodać krawędź o zadanej wadze do grafu.
 * 
 * @param [in] v1 - numer pierwszego łączonego wierzchołka.
 * @param [in] v2 - numer drugiego łączonego wierzchołka.
 * @param [in] waga - waga tworzonej krawędzi.
 */ 
	void Dodaj_krawedz(int v1, int v2, int waga);
	
/*!
 * \brief Usuwa krawędź.
 * 
 * Metoda ta ma za zadanie usunąć krawędź łączącą podane wierzchołki.
 * 
 * @param [in] v1 - numer pierwszego wierzchołka.
 * @param [in] v2 - numer drugiego wierzchołka.
 */ 
	void Usun_krawedz(int v1, int v2);
	
/*!
 * \brief Sprawdza połączenie między dwoma wierzchołkami.
 * 
 * Metoda ta ma za zadanie sprawdzić czy dane dwa wierzchołki są ze sobą
 * połączone.
 * 
 * @param [in] v1 - numer pierwszego wierzchołka.
 * @param [in] v2 - numer drugiego wierzchołka.
 * 
 * \return true - gdy są połączone
 * 		   false - gdy nie są połączone
 */ 
	bool Czy_polaczone(int v1, int v2);
	
/*!
 * \brief Sprawdza istnienie wierzchołka.
 * 
 * Metoda ta ma za zadanie sprawdzić czy wierzchołek o podanym numerze
 * istnieje.
 * 
 * @param [in] v - numer wierzchołka.
 * \return true - gdy istnieje.
 * 		   false - gdy nie istnieje.
 */ 
	bool Czy_istnieje(int v);
	
/*!
 * \brief Wypisuje macierz sąsiedztwa.
 * 
 * Metoda ta ma za zadanie wypisać na standardowe wyjście zawartość
 * macierzy sąsiedztwa.
 */
	void Wypisz_macierz();
	
/*!
 * \brief Sprawdza sąsiedztwo wierzchołka.
 * 
 * Metoda ta ma za zadanie wypisać, z którymi wierzchołkami jest połączony
 * wierzchołek o zadanym numerze.
 * 
 * @param [in] v - numer wierzchołka.
 */
	void Sasiedztwo(int v);
	
/*!
 * \brief Funkcja pomocnicza dla algorytmu DFS.
 * 
 * Metoda ta realizuje dobieranie następnego wierzchołka dla algorytmu
 * DFS.
 * 
 * @param [in] v - numer wierzchołka, od którego algorytm zaczyna przebieg.
 * \return i - numer następnego wierzchołka.
 * 		  -1 - gdy nie istnieje następny wierzchołek.
 */
	int Nastepny_DFS(int v);
	
/*!
 * \brief Algorytm DFS.
 * 
 * Metoda ta realizuje wyszukiwanie weirzchołka metodą DFS.
 * 
 * @param [in] początkowy - numer wierzchołka, od którego algorytm zaczyna przebieg.
 * @param [in] szukany - numer szukanego wierzchołka.
 */
	void DFS(int poczatkowy, int szukany);
	
/*!
 * \brief Algorytm BFS.
 * 
 * Metoda ta realizuje wyszukiwanie weirzchołka metodą BFS.
 * 
 * @param [in] początkowy - numer wierzchołka, od którego algorytm zaczyna przebieg.
 * @param [in] szukany - numer szukanego wierzchołka.
 */
	void BFS(int poczatkowy, int szukany);
};
