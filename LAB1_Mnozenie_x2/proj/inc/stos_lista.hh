#include "kolejka_tablica.hh"

/*!
 * \file
 * \brief Zawiera deklaracje metod, klase Stos_lista oraz instrukcje 
 * zalaczenia bibliotek.
 */

/*!
 * \brief Klasa definiujaca stos zaimplementowany przy pomocy listy.
 * 
 * Klasa ta zawiera wskaznik na szczyt stosu oraz
 * wewnwtrzna klase definiujaca element  zawierajacy
 * informacje o przechowywanej wartosci oraz wskaznik na nastepny element.
 */ 
class Stos_lista
{
public:

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
 * \brief Zdejmuje element ze stosu.
 * 
 * Funkcja ta ma za zadanie zdjac pierwszy element ze szczytu stosu.
 * 
 */
	int Pop();
	
/*!
 * \brief Konstruktor.
 * 
 * Kostruktor ten ma za zadanie tworzyc stos.
 */
	Stos_lista();
	
/*!
 * \brief Destruktor.
 * 
 * Destruktor ten ma za zadanie usuwac stos z pamieci komputera.
 * 
 */
	~Stos_lista();
	
/*!
 * \brief Sprawdza czy stos jest pusty.
 * 
 * Funkcja ta ma za zadanie sprawdzic czy stos jest pusty, jesli tak
 * zwraca true, jesli nie - false.
 * 
 * \return true\false
 */
	bool IsEmpty();
	
/*!
 * \brief Wyswietla stos.
 * 
 * Funkcja ta ma za zadanie wyswietlic zawartosc stosu.
 * 
 */
	void Wypisz();
	
/*!
 * \brief Podaje rozmiar stosu.
 * 
 * Funkcja ta ma za zadanie podac i wyswietlic rozmiar stosu.
 * 
 */
	void Wielkosc_stosu();
	
private:
	
/*!
 * \brief Klasa definiujaca elementy stosu.
 * 
 * Zawiera dwa pola: pole typu int, odpowiedzialne za przechowywanie
 * liczby umieszczonej w kolejce oraz wskaznik na nastepny element stosu.
 */ 
	class Element_stosu
	{	
	public:
	
		int _wartosc;
		Element_stosu* _nastepny;
	};

	Element_stosu *_pierwszy;
};

	
