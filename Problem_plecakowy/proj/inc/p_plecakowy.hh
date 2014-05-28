#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
using namespace std;

/*!
 * \file
 * \brief Zawiera definicje klas i deklaracje funkcji użytych w programie oraz instrukcje 
 * zalaczenia bibliotek.
 */
 
 
 /*!
 * \brief Klasa definiująca przedmioty.
 * 
 * Klasa ta zawiera trzy prywatne pola typu int przechowujące informacje o numerze,
 * wartości i wadze reprezentowanego przedmiotu.
 * Ponadto znajduje się w niej deklaracja metody przypisującej wartości do
 * wymienionych wyżej pól.
 */ 
 class Przedmiot
 {
	 int _numer;
	 int _wartosc;
	 int _waga;
	 
	public:
	
	 friend class Glowna;
	
	
 /*!
 * \brief Funkcja przypisująca wartości obiektom klasy Przedmiot.
 * 
 * Funkcja majaca na celu przypisanie określonej wartości do każdego pola
 * w obiekcie klasy przedmiot.
 * 
 * Parametry:
 * 
 * \param[in] numer - Indeks danego przedmiotu, przy pomocy, którego jest on identyfikowany.
 * \param[in] wartość - Wartość danego przedmiotu.
 * \param[in] waga - Waga danego przedmiotu.
 */ 
	 void Wartosci(int numer, int wartosc, int waga);
 };
 
  /*!
 * \brief Klasa definiująca pola tablicy wyników.
 * 
 * Klasa ta zawiera dwa prywatne pola, pierwsze z nich jest typu int i 
 * przechowujące informację o sumarycznej wartości przedmiotów, które 
 * eprezentuje. Drugie pole to obiekt klasy wektor, przechowujący indeksy
 * przedmiotów, których wybór reprezentuje to pole.
 * Ponadto znajdują się w tutaj deklaracja przeładowania operatorów.
 */ 
 class Pole_tablicy
 {
	 int _suma_wart;
	 vector<int> _wybrane_przedmioty;
	 
/*!
 * \brief Przeciążenie operatora przypisania.
 * 
 * Jest to przeciążenie operatora przypisania dla obiektów klasy Pole_tablicy.
 * 
 * Parametry:
 * 
 * \param[in] pole - przypisywany obiekt klasy Pole_tablicy.
 */
	 Pole_tablicy operator = (const Pole_tablicy & pole);
	 
/*!
 * \brief Przeciążenie operatora porównania.
 * 
 * Jest to przeciążenie operatora porównania dla obiektów klasy Pole_tablicy.
 * 
 * Parametry:
 * 
 * \param[in] pole - obiekt klasy Pole_tablicy stojący po prawej stronie operatora.
 * \return true - gdy pole _suma_wart przyjmuje większą wartość w porównywanym obiekcie.
 * 		   false -  gdy pole _suma_wart przyjmuje mniejszą wartość w porównywanym obiekcie.
 */
	 bool operator > (const Pole_tablicy & pole);
	
	public:
		
		friend class Glowna;
 };

  /*!
 * \brief Główna klasa programu.
 * 
 * Klasa ta zawiera trzy prywatne pola, pierwsze dwa z nich są typu int i 
 * przechowują informacje o pojemności plecaka oraz ilości przedmiotów. 
 * Trzecie pole to dwuwymiarowa tablica obiektów klasy Pole_tablicy.
 * Ponadto znajdują się tutaj deklaracje metod tej klasy.
 */  
 class Glowna
 {
	 int _pojemnosc_plecaka;
	 int _ilosc_elementow;
	 Pole_tablicy _tab_rozw [5][6];
	 
/*!
 * \brief Funkcja obliczająca wartość pola.
 * 
 * Funkcja majaca na celu obliczenie sumarycznej wartości przedmiotów zawartych
 * w danym polu.
 * 
 * Parametry:
 * 
 * \param[in] pole - Obiekt klasy Pole_tablicy, którego wartość ma zostać obliczona.
 * 
 * \return wartość - sumaryczna wartość przedmiotów zawartych w tym polu.
 */ 
 	 int Oblicz_wartosc(Pole_tablicy pole);
 
	public:
	 
	 vector<Przedmiot> _wektor_p;
 
/*!
 * \brief Funkcja rozwiązująca problem plecakowy.
 * 
 * Funkcja majaca na celu realizację algorytmu rozwiązującego problem plecakowy.
 * 
 * Parametry:
 * 
 * \param[in] ilosc_elementow - Ilosc elementów mogących zostać umieszczonych w plecaku.
 * \param[in] pojemnosc_plecaka - Pojemność plecaka.
 */ 
	 void Rozwiaz(int ilosc_elementow, int pojemnosc_plecaka);
 };
 
 
 /*!
 * \brief Funkcja uruchamiajaca algorytm.
 * 
 * Funkcja majaca na celu uruchomienie algorytmu
 * Parametry:
 * 
 * \param[in] ilosc_elementow - Ilosc elementów mogących zostać umieszczonych w plecaku.
 * \param[in] pojemnosc_plecaka - Pojemność plecaka.
 */ 
 void Uruchom(int ilosc_elementow, int pojemnosc_plecaka);
