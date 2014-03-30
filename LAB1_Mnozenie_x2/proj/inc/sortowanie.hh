#include "kolejka_lista.hh"

/*!
 * \file
 * \brief Zawiera deklaracje funkcji sortujacych oraz instrukcje 
 * zalaczenia bibliotek.
 */

/*!
 * \brief Realizuje sortowanie sybkie.
 * 
 * Funkcja ta ma za zadanie posortowac wektor metoda quicksort.
 * 
 * Parametry:
 * 
 * \param[in] left - zmienna typu int okresleslajaca poczatkowe pole
 * sortowanej tablicy.
 * \param[in] right - zmienna typu int okresleslajaca koncowe pole
 * sortowanej tablicy.
 * \param[out] wekt - Obiekt klasy Dane, zawierajacy wektor, ktorego
 * zawartosc ma zostac posortowana.
 */ 
void sort_quicksort(Dane &wekt, int left, int right);

/*!
 * \brief Realizuje sortowanie przez kopcowanie.
 * 
 * Funkcja ta ma za zadanie stworzyc poczatkowy kopiec, a nastepnie posortowac
 * zawartosc wektora metoda heapsort.
 * 
 * Parametry:
 * 
 * \param[in] rozmiar - zmienna typu int przechowujaca informacje o rozmiarze
 * sortowanej tablicy.
 * \param[out] wekt - Obiekt klasy Dane, zawierajacy wektor, ktorego
 * zawartosc ma zostac posortowana.
 */
void sort_heapsort(Dane &wekt, int rozmiar);

/*!
 * \brief Realizuje sortowanie przez scalanie.
 * 
 * Funkcja ta zajmuje sie obsluga kopca.
 * 
 * Parametry:
 * 
 * \param[in] rozmiar - zmienna typu int przechowujaca informacje o rozmiarze
 * sortowanej tablicy.
 * \param[in] i - pozwalajaca na poruszanie sie po kopcu.
 * \param[out] wekt - Obiekt klasy Dane, zawierajacy tablice, ktorej
 * zawartosc ma zostac posortowana.
 */ 
void sort_kopiec (Dane &wekt, int rozmiar, int i);

/*!
 * \brief Realizuje sortowanie przez scalanie.
 * 
 * Funkcja ta ma za zadanie podzielic wektor na mniejsze wektory.
 * 
 * Parametry:
 * 
 * \param[in] poczatek - zmienna typu int okresleslajaca poczatkowe pole
 * sortowanej tablicy.
 * \param[in] koniec - zmienna typu int okresleslajaca koncowe pole
 * sortowanej tablicy.
 * \param[in] wekt - Pomocniczy obiekt klasy Dane.
 * \param[out] wekt - Obiekt klasy Dane, zawierajacy tablice, ktorej
 * zawartosc ma zostac posortowana.
 */ 
void sort_mergesort(Dane &wekt, Dane wekt_p, int poczatek, int koniec);

/*!
 * \brief Realizuje sortowanie przez scalanie.
 * 
 * Funkcja ta ma za zadanie scalic wektory, jednoczesnie je sortujac, az
 * do uzyskania jednego w pelni posortowanego wektora.
 * 
 * Parametry:
 * 
 * \param[in] poczatek - zmienna typu int okresleslajaca poczatkowe pole
 * sortowanej tablicy.
 * \param[in] pivot - zmienna typu int okresleslajaca punkt podzialu tablicy.
 * \param[in] koniec - zmienna typu int okresleslajaca koncowe pole
 * sortowanej tablicy.
 * \param[in] wekt - Pomocniczy obiekt klasy Dane.
 * \param[out] wekt - Obiekt klasy Dane, zawierajacy wektor, ktorego
 * zawartosc ma zostac posortowana.
 */ 
void sort_scal(Dane &wekt, Dane wekt_p, int poczatek, int pivot, int koniec);
