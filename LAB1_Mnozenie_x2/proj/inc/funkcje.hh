#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/*!
 * \file
 * \brief Zawiera deklaracje funkcji, klase Dane oraz instrukcje 
 * zalaczenia bibliotek.
 */

/*!
 * \brief Klasa definiujaca obiekt Dane
 * 
 * Klasa ta zawiera jedno pole, bedace wektorem.
 */ 
class Dane
{
	public:
	vector<int> Wektor;
	
/*!
 * \brief Wczytuje dane z pliku.
 * 
 * Funkcja ta ma za zadanie wczytac dane, w postaci cyfr, ze wskazanego
 * pliku.
 * 
 * Parametry:
 * 
 * \param[in] nazwa - Nazwa wczytywanego pliku, przekazywana przez
 * wskaznik.
 * \param[out] wekt - Obiekt klasy Dane, przekazywany przez referencje,
 * do ktorego zostanie wczytana zawartosc pliku.
 */ 
	void Wczytywanie(const char *nazwa, Dane& wekt);
	
/*!
 * \brief Porownuje dwa obiekty klasy Dane.
 * 
 * Funkcja ta ma za zadanie porownac odpowiadajace elementy dwoch obiektow
 * klasy Dane o takich samych wymiarach. W przypadku znalezienia roznego
 * elementu operacja zostaje przerwana.
 * 
 * Parametry:
 * 
 * \param[in] wekt1 - Pierwszy z porownywanych obiektow.
 * \param[in] wekt2 - Drugi z porownywanych obiektow.
 * \return Funkcja zwraca wartosc true, jesli obiekty sa takie same oraz
 * false, jesli posiadaja chociaz jeden rozny element.
 */ 
	bool Porownanie(Dane wekt1, Dane wekt2);

/*!
 * \brief Wykonuje operacje zamiany miejscami dwoch elementow wektora.
 * 
 * Funkcja ta ma za zadanie zamienic ze soba miejscami dwa wskazane
 * elementy wektora.
 * 
 * Parametry:
 * 
 * \param[out] wekt - Obiekt klasy Dane, przekazywany przez referencje. 
 * To jego elementy zostana zamienione miejscami.
 * \param[in] pierwszy_el - Zmienna typu int okreslajaca numer pierwszej
 * z komorek majacych ulec zamianie.
 * \param[in] drugi_el - Zmienna typu int okreslajaca numer drugiej
 * z komorek majacych ulec zamianie.
 */ 
	void Zamien_elementy (Dane& wekt, int pierwszy_el, int drugi_el);
	
/*!
 * \brief Wykonuje operacje dodawania elementu do wektora.
 * 
 * Funkcja ta ma za zadanie dopisac wskazany element na koniec danego
 * wektora, bedacego polem obiektu klasy Dane.
 * 
 * Parametry:
 * 
 * \param[out] wekt - Obiekt klasy Dane przekazywany przez referencje. 
 * To do niego zostanie dopisana wartosc.
 * \param[in] element - Zmienna typu int majaca byc dopisana do wektora.
 */ 
	void Dodaj_element (Dane &wekt, int element);
	
/*!
 * \brief Wykonuje operacje dodawania dwoch wektorow.
 * 
 * Funkcja ta ma za zadanie dopisac elementy wskazanego wektora, bedacego
 * polem obiektu klasy Dane, na koniec innego.
 * 
 * Parametry:
 * 
 * \param[out] wekt1 - Obiekt klasy Dane, przekazywany przez referencje. 
 * To do niego zostanie dopisana zawartosc wektora wekt2.
 * \param[in] wekt2 - Obiekt klasy Dane, ktory ma zostac dopisany do wekt1.
 */ 
	void Dodaj_elementy (Dane &wekt1, Dane wekt2);
	
/*!
 * \brief Wykonuje operacje odwracania kolejnosci.
 * 
 * Funkcja ta ma za zadanie zapisac elementy wskazanego wektora, bedacego
 * polem obiektu klasy Dane, w odwrotnej kolejnosci.
 * 
 * Parametry:
 * 
 * \param[out] wekt1 - Obiekt klasy Dane, przekazywany przez referencje,
 * na ktorym zostanie wykonana operacja odwracania.
 */ 
	void Odwroc_kolejnosc (Dane& wekt);
	
/*!
 * \brief Wykonuje operacje mnozenia.
 * 
 * Funkcja ta ma za zadanie przemnozyc wszystkie elementy podanego
 * wektora przez 2.
 * 
 * Parametry:
 * 
 * \param[out] wekt - Obiekt klasy Dane przekazywany przez referencje. 
 * Jego pole Wektor zawiera liczby, ktore maja zostac wymnozone.
 */ 
	void Mnozenie(Dane& wekt);
	
/*!
 * \brief Przeciazony operator porownania.
 * 
 * Przeciazony operator majacy za zadanie porownywanie ze soba dwoch
 * obiektow klasy Dane.
 * 
 * Parametry:
 * 
 * \param[in] wekt2 - Drugi z porownywanych obiektow.
 * \return Funkcja zwraca wartosc true, jesli obiekty sa takie same oraz
 * false, jesli posiadaja chociaz jeden rozny element.
 */ 
	bool operator == (Dane wekt2);
	
/*!
 * \brief Przeciazony operator przypisania.
 * 
 * Przeciazony operator majacy za zadanie przypisanie jednemu obiektowi
 * klasy Dane inny.
 * 
 * Parametry:
 * 
 * \param[in] wekt2 - Przypisywany obiekt.
 * \return Funkcja zwraca przypisana wartosc.
 */ 
	Dane operator = (Dane wekt2);
	
/*!
 * \brief Przeciazony operator dodawania.
 * 
 * Przeciazony operator majacy za zadanie dopisac elementy wskazanego
 * wektora, bedacego polem obiektu klasy Dane, na koniec innego.
 * 
 * Parametry:
 * 
 * \param[in] wekt2 - Obiekt klasy Dane, ktory ma zostac dopisany.
 */ 
	Dane operator + (Dane wekt2);
	
/*!
 * \brief Przeciazony operator wejscia.
 * 
 * Przeciazony operator pozwalajacy na wpisywanie wartosci do pol obiektow
 * klasy Dane.
 * 
 * Parametry:
 * 
 * \param[in] in - Przekazywany przez referencje strumien danych wejsciowych.
 * \param[out] wekt - Obiekt klasy Dane, ktorego pola maja zostac uzupelnione
 * danymi wjesciowymi.
 */ 
	friend istream& operator >> (istream &in, Dane& wekt);
	
/*!
 * \brief Przeciazony operator wyjscia.
 * 
 * Przeciazony operator pozwalajacy na wypisywanie wartosci pol obiektow
 * klasy Dane.
 * 
 * Parametry:
 * 
 * \param[out] out - Przekazywany przez referencje strumien danych wyjsciowych.
 * \param[out] wekt - Obiekt klasy Dane, przekazywany przez referencje,
 * ktorego pola maja zostac wypisane.
 */ 
	friend ostream& operator << (ostream &out, const Dane& wekt);
};

/*!
 * \brief Funkcja uruchamiajaca algorytm.
 * 
 * Funkcja majaca na celu uruchomienie algorytmu zadana ilosc razy, 
 * zmierzenie czasu jego dzialania i porownanie wyniku z plikiem wzorcowym.
 * 
 * Parametry:
 * 
 * \param[in] ilosc_powtorzen - Ilosc powtorzen wykonania algorytmu.
 * \param[in] wektor1 - Obiekt klasy Dane zawierajacy dane, na ktorych
 * maja byc wykonane operacje przez algorytm.
 * \param[in] wektor2 - Obiekt klasy Dane zawierajacy dane pobrane z pliku
 * wzorcowego, w celu porownania wynikow.
 * \return czas - Czas wykonania algorytmu.
 */ 
double Uruchom(int ilosc_powtorzen, Dane wektor1, Dane wektor2);

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
 * \param[in] ilosc_powt - Ilosc powtorzen wykonania algorytmu.
 * \param[in] ilosc_elementow - ilosc elementow, na ktorych wykonano operacje.
 */ 
void Zapis (double czas_sredni, int ilosc_powt, int ilosc_elementow);
