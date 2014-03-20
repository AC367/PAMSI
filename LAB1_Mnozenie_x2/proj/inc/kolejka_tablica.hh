#include "funkcje.hh"

/*!
 * \file
 * \brief Zawiera deklaracje metod, klase Kolejka_tablica oraz instrukcje 
 * zalaczenia bibliotek.
 */

const int wartosc_pocz_kolejki=0;

/*!
 * \brief Klasa definiujaca kolejke zaimplementowana przy pomocy tablicy.
 * 
 * Klasa ta zawiera pole trzy pola: wskaznik na tablice elementow,
 * pole typu int, przechowujace informacje o rozmiarze tablicy oraz
 * zmienna typu unsigned int bedaca licznikiem elementow tablicy.
 */ 
class Kolejka_tablica
{
private:
	int *tab;
	int _rozmiar;
	unsigned int Licznik_elementow;
   
/*!
 * \brief Powieksza tablice.
 * 
 * Metoda ta - w razie potrzeby - powieksza tablice przechowujaca elementy
 * kolejki o jedno pole.
 */
	void Powieksz();
  
public:
/*!
 * \brief Konstruktor.
 * 
 * Kostruktor ten ma za zadanie tworzyc kolejke.
 */
	Kolejka_tablica();
	
/*!
 * \brief Destruktor.
 * 
 * Destruktor ten ma za zadanie usuwac kolejke z pamieci komputera.
 * 
 */
	~Kolejka_tablica();
	
/*!
 * \brief Dodaje elementy do kolejki.
 * 
 * Funkcja ta ma za zadanie dodac element na koniec kolejki.
 * 
 * Parametry:
 * 
 * \param[in] wekt - obiekt klasy Dane zawierajacy liczby, ktore maja
 * znalezc sie w kolejce.
 */
	void Enqueue(Dane wekt);
	
/*!
 * \brief Wyswietla kolejke.
 * 
 * Funkcja ta ma za zadanie wyswietlic zawartosc kolejki.
 * 
 */
	void Wypisz();
	
/*!
 * \brief Zabiera elementy z kolejki.
 * 
 * Funkcja ta ma za zadanie zabrac pierwszy element z kolejki.
 * 
 */
	void Dequeue();
	
/*!
 * \brief Sprawdza czy kolejka jest pusta.
 * 
 * Funkcja ta ma za zadanie sprawdzic czy kolejka jest pusta, jesli tak
 * zwraca true, jesli nie - false.
 * 
 * \return true\false
 */
	bool IsEmpty();
}; 
