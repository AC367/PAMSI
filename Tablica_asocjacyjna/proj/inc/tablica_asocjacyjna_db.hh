#include "funkcje.hh"
#include "drzewo_binarne.hh"

class TablicaAsocjacyjna_db
{
public:
Drzewo_binarne drzewo;

/*!
 * \brief Metoda zwracająca informację o ilości danych w tablicy.
 */ 
int Rozmiar();

/*!
 * \brief Metoda sprawdzająca istnienie elementu.
 * 
 * Metoda ta ma za zadanie sprawdzić czy w tablicy jest już zawarty
 * element o podanym adresie.
 * 
 * @param [in] adres - adres, którego istnienie w tablicy ma sprawdzić
 * funkcja.
 * 
 * \return true - gdy element o podanym adresie znajduje się już w tablicy.
 * 			false - gdy elementu o podanym adresie nie ma w tablicy.
 */ 
bool Czy_jest(string adres);

/*!
 * \brief Metoda dodająca elementy do tablicy.
 * 
 * Metoda ta ma za zadanie dodać zadaną daną pod określonym adresem do
 * tablicy. 
 * 
 * @param [in] adres - adres, pod którym ma zostać umieszczona dana.
 * @param [in] dane - wartość, która ma zostać umieszczona w tablicy.
 * 
 * \return true - gdy element został dodany.
 * 			false - gdy elementu nie został dodany.
 */ 
bool DodajElement(string adres_dod, int dane);

/*!
 * \brief Metoda usuwająca element z tablicy.
 * 
 * Metoda ta ma za zadanie usunąć element o zadanym adresie z tablicy.
 * W przypadku gdy element o takiej nazwie już istnieje zostaje on podmieniony
 * na nowy.
 * 
 * @param [in] adres - adres komórki, która ma zostać usunięta.
 * 
 * \return true - gdy element został podmieniony.
 * 			false - gdy elementu nie nie został usunięty.
 */ 
bool UsunElement(string adres);

/*!
 * \brief Metoda zamieniająca elementy w tablicy.
 * 
 * Metoda ta ma za zadanie zamienić miejscami dwa podane elementy tablicy.
 * 
 * @param [in] pierwszy - numer pola tablicy zajmowanego przez pierwszy
 * z elementów.
 * @param [in] drugi - numer pola tablicy zajmowanego przez drugi
 * z elementów.
 * \return true - gdy elementy zostały zamienione miejscami.
 * 			false - gdy elementy nie zostały zamienione miejscami.
 */ 
//bool Zamien(int pierwszy, int drugi);

/*!
 * \brief Metoda pobierająca adres.
 * 
 * Metoda ta pobiera adres w postaci string z pola o zadanym indeksie.
 * 
 * @param [in] index - indeks liczbowy danego pola.
 * \return adres pola.
 */
//string PobierzAdres(long index);

/*!
 * \brief Przeciążenie operatora [].
 * 
 * Przeciążenie tego operatora zwraca wartość pola o podanym adresie.
 * 
 * @param [in] adres - adres pola, które ma zostać zwrócone.
 * \return dane - wartość danego pola.
 */
//int operator [](string adres);

/*!
 * \brief Przeciążenie operatora [].
 * 
 * Przeciążenie tego operatora zwraca wartość pola o podanym indeksie.
 * 
 * @param [in] index - indeks pola, które ma zostać zwrócone.
 * \return dane - wartość danego pola.
 */
//T& operator [](long index);
};