#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
using namespace std;

/*!
 * \file
 * \brief Zawiera deklaracje funkcji oraz instrukcje 
 * zalaczenia bibliotek.
 */


/*!
 * \brief Funkcja uruchamiajaca algorytm.
 * 
 * Funkcja majaca na celu uruchomienie algorytmu zadana ilosc razy, 
 * zmierzenie czasu jego dzialania i porownanie wyniku z plikiem wzorcowym.
 * 
 * Parametry:
 * 
 * \param[in] ilosc_powtorzen - Ilosc powtorzen wykonania algorytmu.
 * \return czas - Czas wykonania algorytmu.
 */ 
double Uruchom(int ilosc_elementow);

/*!
 * \brief Funkcja zapisujaca do pliku.
 * 
 * Funkcja majaca na celu zapisanie informacji o srednim czasie wykonywania
 * algorytmu, ilosci powtorzen jego wykonania oraz ilosci elementow, na
 * ktorych zostala wykonana operacja do  pliku csv.
 * 
 * Parametry:
 * 
 * \param[in] czas_sredni - Sredni czas jednorazowego wykonania algorytmu.
 * \param[in] ilosc_elementow - ilosc elementow, na ktorych wykonano operacje.
 */ 
void Zapis (double czas_sredni, int ilosc_elementow);
