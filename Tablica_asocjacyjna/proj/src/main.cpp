#include "tablica_asocjacyjna.hh"

/*!
 * \mainpage
 * Wykonal Arkadiusz Cyktor, numer indeksu: 200367.
 * 
 * Program ma za zadanie przedstawić realizację tablicy asocjacyjnej.
 * 
 * Jako adresy w tablicy służą zmienne typu string, natomiast przechowywane
 * dane zostały zrealizowane na szablonie.
 * 
 * Wypisywanie zawartości poszczególnych pól zostało rozwiązane
 * na dwa sposoby - w obu przypadkach przeładowany został operator [].
 * Po szczegóły odsyłam do opisów poszczególnych funkcji.
 * 
 * W celu szybszego odczytu pól tablicy zastosowałem rozwiązanie polegające
 * na każdorazowym sortowaniu wektora po dodaniu nowego elementu, co
 * umożliwia wyszukiwanie ich przy użyciu metody wyszukiwania binarnego.
 * 
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
	TablicaAsocjacyjna<string>	tab;
	TablicaAsocjacyjna<int> tab_int;
	
	//=========Prezentacja dodawania elementów do tablicy===============
	
	tab.DodajElement("Zerowy", "Wiosna");
	tab.DodajElement("Pierwszy", "Lato");
	tab.DodajElement("Drugi", "Jesien");
	tab.DodajElement("Trzeci", "Zima");
	
	//==============Wypisywanie=========================================
	
	cout<<endl<<tab[0]<<endl;
	cout<<tab[1]<<endl;
	cout<<tab[2]<<endl;
	cout<<tab[3]<<endl;
	
	cout<<endl<<"Nieposortowane: "<<endl;
	cout<<endl<<tab["Zerowy"]<<endl;
	cout<<tab["Pierwszy"]<<endl;
	cout<<tab["Drugi"]<<endl;
	cout<<tab["Trzeci"]<<endl;
    
    //==================================================================
    //=====================Dla int======================================
    //==================================================================
    
    tab_int.DodajElement("Zerowy", 0);
	tab_int.DodajElement("Pierwszy", 10);
	tab_int.DodajElement("Drugi", 20);
	tab_int.DodajElement("Trzeci", 30);
	
		//==============Wypisywanie=========================================
	
	cout<<endl<<tab_int[0]<<endl;
	cout<<tab_int[1]<<endl;
	cout<<tab_int[2]<<endl;
	cout<<tab_int[3]<<endl;
	
	cout<<endl<<"Nieposortowane: "<<endl;
	cout<<endl<<tab_int["Zerowy"]<<endl;
	cout<<tab_int["Pierwszy"]<<endl;
	cout<<tab_int["Drugi"]<<endl;
	cout<<tab_int["Trzeci"]<<endl;
    
}
