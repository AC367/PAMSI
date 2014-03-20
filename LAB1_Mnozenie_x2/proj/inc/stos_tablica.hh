#include <cassert>
#include "stos_lista.hh"

/*!
 * \file
 * \brief Zawiera deklaracje metod, klase Stos_lista oraz instrukcje 
 * zalaczenia bibliotek.
 */

const int wartosc_pocz=1;

/*!
 * \brief Klasa definiujaca stos zaimplementowana przy pomocy tablicy.
 * 
 * Klasa ta zawiera pole trzy pola: wskaznik na tablice elementow oraz
 * dwa pola typu int. Pierwsze z nich przechowujace wartosc szczytowego
 * elementu stosu, a drugie zawiera informacje orozmiarze tablicy.
 */ 
class Stos_tablica
{
	int* _tablica;
	int _szczyt;
	int _rozmiar;
	int _licznik;

/*!
 * \brief Powieksza tablice.
 * 
 * Metoda ta - w razie potrzeby - powieksza tablice przechowujaca elementy
 * stosu. Domyslnie zaimplementowanym sposobem jest dodawanie w razie potrzeby
 * po jednym polu, druga opcja - zwiekszanie wielkosci tablicy dwukrotnie - jest
 * "wykomentowana".
 */
	void Powieksz ();
	
public:

/*!
 * \brief Konstruktor.
 * 
 * Kostruktor ten ma za zadanie tworzyc stos.
 */
	Stos_tablica();
	
/*!
 * \brief Destruktor.
 * 
 * Destruktor ten ma za zadanie usuwac stos z pamieci komputera.
 * 
 */
	~Stos_tablica();
	
/*!
 * \brief Dodaje elementy do stosu.
 * 
 * Funkcja ta ma za zadanie dodac element na szczyt stosu.
 * 
 * Parametry:
 * 
 * \param[in] wekt - obiekt klasy Dane zawierajacy liczby, ktore maja
 * znalezc sie na stosie.
 */
	void Push(Dane wekt);
	
/*!
 * \brief Wyswietla stos.
 * 
 * Funkcja ta ma za zadanie wyswietlic zawartosc stosu.
 * 
 */
	void Wypisz();
	
/*!
 * \brief Zdejmuje element ze stosu.
 * 
 * Funkcja ta ma za zadanie zdjac pierwszy element ze szczytu stosu oraz
 * zmniejszyc wielkosc tablicy przechowujacej elementy stosu. Zmniejszenie
 * o polowe nastepuje w momencie, gdy ilosc elementow jest mniejsza niz
 * polowa wielkosci tablicy.
 * 
 */
	void Pop();
	
/*!
 * \brief Sprawdza czy stos jest pusty.
 * 
 * Funkcja ta ma za zadanie sprawdzic czy stos jest pusty, jesli tak
 * zwraca true, jesli nie - false.
 * 
 * \return true\false
 */
	bool IsEmpty()const;
};
