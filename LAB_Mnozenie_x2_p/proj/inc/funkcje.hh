#include <iostream>
#include <fstream>
using namespace std;

/*!
 * \file
 * \brief Zawiera deklaracje funkcji oraz instrukcje zalaczenia bibliotek
 */

/*!
 * \brief Wczytuje dane z pliku
 * 
 * Funkcja ta ma za zadanie wczytac dane, w postaci cyfr, ze wskazanego
 * pliku.
 * 
 * Parametry:
 * 
 * \param [in] *nazwa - nazwa wczytywanego pliku, przekazywana przez
 * wskaznik
 * \return Funkcja zwraca wskaznik na tablice wczytanych znakow.
 */ 
int* Wczytywanie(const char *nazwa);

/*!
 * \brief Wykonuje operacje mnozenia
 * 
 * Funkcja ta ma za zadanie przemnozyc wszystkie elementy podanej
 * tablicy przez 2.
 * 
 * Parametry:
 * 
 * \param [in] tablica[] - tablica wartosci, ktore maja zostac wymnozone
 * \return Funkcja zwraca wskaznik na tablice zawierajaca wyniki
 * dzialania.
 */ 
int* Mnozenie(int tablica[]);

/*!
 * \brief Porownuje dwie tablice
 * 
 * Funkcja ta ma za zadanie porownac odpowiadajace elementy dwoch tablic
 * o takich samych wymiarach. W przypadku znalezienia roznego elementu
 * operacja zostaje przerwana.
 * 
 * Parametry:
 * 
 * \param [in] wynik[] - pierwsza z porownywanych tablic
 * \param [in] porownanie[] - druga z porownywanych tablic
 * \return Funkcja zwraca wartosc true, jesli tablice sa takie same oraz
 * false, jesli posiadaja chociaz jeden rozny element.
 */ 
bool Porownanie(int wynik[], int porownanie[]);
