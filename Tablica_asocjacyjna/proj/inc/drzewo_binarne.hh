#include <iostream>
#include <stdlib.h>
using namespace std;

 /*!
 * \file
 * \brief Zawiera definicje klasy Drzewo_binarne, jej metody oraz 
 * polecenia załączenia niezbędnych bibliotek.
 */

/*!
 * \brief Klasa definiująca drzewo binarne realizujące implementację
 * tablicy asocjacyjnej.
 * 
 * Klasa ta zawiera wewnętrzną strukturę galaz, która odpowiada za
 * przechowywanie adresu oraz zawartości określonego pola oraz wskaźniki
 * na jego lewą i prawą odnogę. 
 * Ponadto zawarte są w niej deklarace metod oraz konstruktor. 
 */ 
class Drzewo_binarne
{
    public:
    
/*!
 * \brief Struktura realizująca "gałęzie" drzewa binarnego.
 * 
 * Struktura ta zawiera wskaźniki na lewą i prawą odnogę oraz pola
 * przechowujące informacje o adresie i zawartości gałęzi.
 */ 
        struct galaz
        {
           galaz* lewa;
           galaz* prawa;
		   string adres;
           string dane;
        };
        
        galaz* korzen;
    
    public:
    
		int rozmiar;
		
/*!
 * \brief Konstruktor.
 * 
 * Konstruktor odpowiedzialny za inicjowanie pól obiektu typu Drzewo_binarne.
 */ 
        Drzewo_binarne()
        {
           korzen = NULL;
           rozmiar = 0;
        }
       
/*!
 * \brief Czy drzewo jest puste.
 * 
 * Metoda sprawdzająca czy drzewo binarne jest puste.
 */
        bool Czy_puste() const;
        
/*!
 * \brief Wyświetla zawartość.
 * 
 * Metoda odpowiedzialna za wyświetlenie zawartości drzewa binarnego.
 */
        void wyswietl_kolejno();
        
/*!
 * \brief Pobiera kolejne wartości.
 * 
 * Metoda ta ma za zadanie pobrać kolejne wartości z drzewa.
 * 
 * @param [in] gal - gałąź, od której zaczyna się pobieranie.
 */ 
        void kolejno(galaz* gal);
        
/*!
 * \brief Dodaje elementy.
 * 
 * Metoda ta ma za zadanie dodać element o podanym adresie do tablicy asocjacyjnej.
 * Jeśli podany adres jest już zajęty, to wartość do niego przypisana
 * zostanie podmieniona.
 * 
 * @param [in] adres - adres, pod którym zostanie zapisany element.
 * @param [in] d - zmienna typu string, która ma zostać zapisana w tablicy.
 */ 
        void dodaj(string adres, string d);
        
/*!
 * \brief Usuwa elementy.
 * 
 * Metoda ta ma za zadanie usunąć element o podanym adresie z tablicy asocjacyjnej.
 * Pod warunkiem, że dany adres istnieje.
 * 
 * @param [in] adres - adres elementu, który ma zostać usunięty.
 */ 
        void usun(string adres);
        
/*!
 * \brief Sprawdza istnienie elementu.
 * 
 * Metoda ta ma za zadanie sprawdzić czy element o podanym adresie występuje
 * w tablicy asocjacyjnej.
 * 
 * @param [in] adres - szukany adres.
 * 
 * \return true - gdy element o podanym adresie znajduje się w tablicy.
 * 			false - gdy elementu o podanym adresie nie ma w tablicy.
 */ 
        bool czy_jest(string adres);
};
