#include "tablica_asocjacyjna.hh"
#include "tablica_asocjacyjna_db.hh"
#include "tablica_haszujaca.hh"
#include "funkcje.hh"

/*!
 * \mainpage
 * Wykonal Arkadiusz Cyktor, numer indeksu: 200367.
 * 
 * Program ma za zadanie przedstawić realizację tablicy asocjacyjnej.
 * 
 * Jako adresy w tablicy służą zmienne typu string, natomiast przechowywane
 * dane zostały zrealizowane na szablonie (w przypadku implementacji wektorowej) 
 * oraz na zmiennych typu strnig (implementacja drzewem binarnym i tablica
 * haszujaca).
 */
 
 /*!
 * \file
 * \brief Zawiera definicje glownej funkcji programu.
 */

/*!
 * \brief Prezentuje działanie tablicy
 * 
 * Jest to glowna funkcja programu odpowiedzialna za wprowadzenie przykładowych
 * danych do tablicy oraz demonstrację działania niektórych jego funkcji.
 */ 
int main()
{
	int ilosc_elementow, ilosc_powtorzen;
	 
	cout<<"Podaj ilosc elementow: ";
	cin>>ilosc_elementow;
	cout<<"Podaj ilosc powtorzen: ";
	cin>>ilosc_powtorzen;
	
	Uruchom(ilosc_elementow, ilosc_powtorzen);
}
