#include "stos_tablica.hh"

/*!
 * \file
 * \brief Zawiera deklaracje metod, klase Kolejka_lista oraz instrukcje 
 * zalaczenia bibliotek.
 */

/*!
 * \brief Klasa definiujaca kolejke zaimplementowana przy pomocy listy.
 * 
 * Klasa ta zawiera wewnwtrzna klase definiujaca element kolejki zawierajacy
 * informacje o przechowywanej wartosci oraz wskaznik na nastepny element.
 */ 
class Kolejka_lista
{
private:

/*!
 * \brief Klasa definiujaca elementy kolejki.
 * 
 * Zawiera dwa pola: pole typu int, odpowiedzialne za przechowywanie
 * liczby umieszczonej w kolejce oraz wskaznik na nastepny element kolejki.
 */ 
	class Element_kolejki
	{
	public:
	
		int wartosc;
		Element_kolejki *nastepny;
		
/*!
 * \brief Konstruktor.
 * 
 * Kostruktor ten ma za zadanie tworzyc elementy kolejki.
 */
		Element_kolejki();
	};
	
	Element_kolejki *pierwszy;

public:

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
 * \brief Zabiera elementy z kolejki.
 * 
 * Funkcja ta ma za zadanie zabrac pierwszy element z kolejki.
 * 
 */
	void Dequeue();
	
/*!
 * \brief Wyswietla kolejke.
 * 
 * Funkcja ta ma za zadanie wyswietlic zawartosc kolejki.
 * 
 */
	void Wyswietl();
	
/*!
 * \brief Podaje rozmiar kolejki.
 * 
 * Funkcja ta ma za zadanie podac i wyswietlic rozmiar kolejki.
 * 
 */
	void Size();
	
/*!
 * \brief Sprawdza czy kolejka jest pusta.
 * 
 * Funkcja ta ma za zadanie sprawdzic czy kolejka jest pusta, jesli tak
 * zwraca true, jesli nie - false.
 * 
 * \return true\false
 */
	bool IsEmpty(); 

/*!
 * \brief Konstruktor.
 * 
 * Kostruktor ten ma za zadanie tworzyc kolejke.
 */
	Kolejka_lista();
	
/*!
 * \brief Destruktor.
 * 
 * Destruktor ten ma za zadanie usuwac kolejke z pamieci komputera.
 * 
 */
	~Kolejka_lista();
};


