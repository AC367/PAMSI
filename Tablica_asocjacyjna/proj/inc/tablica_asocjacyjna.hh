/*!
 * \file
 * \brief Zawiera definicję klasy TablicaAsocjacyjna, jej metod oraz
 * instrukcje załączenia poszczególnych bibliotek.
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

/*!
 * \brief Klasa definiujaca kolejke zaimplementowana przy pomocy tablicy.
 * 
 * Klasa ta zawiera wewnętrzną strukturę _Dane, która odpowiada za
 * przechowywanie adresu oraz zawartości określonego pola w tablicy
 * oraz vector, przechowujący obiekty struktury Dane. Dodatkowo w klasie
 * znajduje się pole typu int - miejsce - na potrzeby wyszukiwania binarnego. 
 */ 
template <typename T>
class TablicaAsocjacyjna
{
private:

typedef struct _Dane
{
	T dane;
	string adres;
} Dane ;

vector<Dane> wektor;
int miejsce;

public:

/*!
 * \brief Metoda zwracająca informację o ilości danych w tablicy.
 */ 
long Rozmiar();

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
bool DodajElement(string adres, T dane);

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
bool Zamien(int pierwszy, int drugi);

/*!
 * \brief Metoda wyszukująca elementy w tablicy.
 * 
 * Metoda ta realizuje wyszukiwanie binarne w posortowanej tablicy.
 * Efekt jej działania, czyli numer pola, w którym znajduje się szukany
 * element, zapisywany jest w polu "miejsce" w klasie TablicaAsocjacyjna.
 * 
 * @param [in] szukany - adres szukanego pola.
 * @param [in] lewy - lewa granica przeszukiwanej tablicy.
 * @param [in] piwot - element dzielący tablicę.
 * @param [in] prawy - prawa granica przeszukiwanej tablicy.
 * \return true - gdy element został znaleziony.
 * 			false - gdy elementy nie został znaleziony.
 */
bool Wyszukaj(string szukany, int lewy, int& piwot, int prawy);

/*!
 * \brief Metoda pobierająca adres.
 * 
 * Metoda ta pobiera adres w postaci string z pola o zadanym indeksie.
 * 
 * @param [in] index - indeks liczbowy danego pola.
 * \return adres pola.
 */
string PobierzAdres(long index);

/*!
 * \brief Przeciążenie operatora [].
 * 
 * Przeciążenie tego operatora zwraca wartość pola o podanym adresie.
 * 
 * @param [in] adres - adres pola, które ma zostać zwrócone.
 * \return dane - wartość danego pola.
 */
T& operator [](string adres);

/*!
 * \brief Przeciążenie operatora [].
 * 
 * Przeciążenie tego operatora zwraca wartość pola o podanym indeksie.
 * 
 * @param [in] index - indeks pola, które ma zostać zwrócone.
 * \return dane - wartość danego pola.
 */
T& operator [](long index);

/*!
 * \brief Realizuje sortowanie sybkie.
 * 
 * Funkcja ta ma za zadanie posortowac wektor metoda quicksort.
 * 
 * @param [in] left - zmienna typu int okresleslajaca poczatkowe pole
 * sortowanej tablicy.
 * @param [in] right - zmienna typu int okresleslajaca koncowe pole
 * sortowanej tablicy.
 */ 
void sort_quicksort(int left, int right);
};

template <typename T>
long TablicaAsocjacyjna<T>::Rozmiar()
{
	return wektor.size();
}

template <typename T>
bool TablicaAsocjacyjna<T>::Czy_jest(string adres)
{
	for(int i=0; i<Rozmiar(); i++)
    {
		if(wektor[i].adres==adres)
			return true;
    }
    return false;
}

template <typename T>
bool TablicaAsocjacyjna<T>::DodajElement(string adres, T dane)
{
	Dane d;
	
	if(Czy_jest(adres))
	{
		int a;
		cout<<"Podana nazwa juz istnieje - elementy zostały zamienione"<<endl;
		Wyszukaj(adres, 0, a, Rozmiar()-1);
		wektor[miejsce].dane=dane;
		sort_quicksort(0, Rozmiar()-1);
		return false;
	}
	d.adres = adres;
	d.dane = dane;
	wektor.push_back(d);
	sort_quicksort(0, Rozmiar()-1);
	return true;
}

template <typename T>
bool TablicaAsocjacyjna<T>::UsunElement(string adres)
{
	if(Czy_jest(adres))
	{
		int prawy=Rozmiar()-1;
		int pivot=0;
		
		Wyszukaj(adres,0,pivot,prawy);
		wektor.erase(wektor.begin()+miejsce);
		return true;
	}
	else
		return false;
}

template <typename T>
bool TablicaAsocjacyjna<T>::Wyszukaj(string szukany, int lewy, int& pivot, int prawy)
{
	pivot=(prawy+lewy)/2;
	if(szukany==wektor[0].adres)
	{
		miejsce=0;
		return true;
	}
	else if(szukany==wektor[Rozmiar()-1].adres)
	{
		miejsce=Rozmiar()-1;
		return true;
	}
	if(szukany==wektor[pivot].adres)
	{
		miejsce=pivot;
		return true;
	}
	else if(szukany<wektor[pivot].adres)
		Wyszukaj(szukany,lewy,pivot,pivot);

	else if(szukany>wektor[pivot].adres)
		Wyszukaj(szukany,pivot,pivot,prawy);
	return false;
}

template <typename T>
string TablicaAsocjacyjna<T>::PobierzAdres(long index)
{
	for(int i=0; i<Rozmiar(); i++)
		if(i==index)
		  return wektor[i].adres;
	return "";
}

template <typename T>
T& TablicaAsocjacyjna<T>::operator [](string adres)
{
	long idx=Rozmiar();
    Dane d;
	
	for(int i=0; i<Rozmiar(); i++)
	{
		if(wektor[i].adres==adres)
			return wektor[i].dane;
    }
    d.adres=adres;
    wektor.push_back(d);
    return wektor[idx].dane;
}

template <typename T>
T& TablicaAsocjacyjna<T>::operator [](long index)
{
	for(int i=0; i<Rozmiar(); i++)
		if(i==index)
			return wektor[i].dane;
	cout<<"W tej tablicy nie isnieje pole o podanym indeksie."<<endl;
	cout<<"Ostatnie z nich ma numer: "<<Rozmiar()-1<<" I przyjmuje wartosc: "<<endl;
	return wektor[Rozmiar()-1].dane;
}

template <typename T>
bool  TablicaAsocjacyjna<T>::Zamien(int pierwszy, int drugi)
	{
		Dane d1;
		Dane d2;
		
		if(pierwszy==drugi)
			return true;
		if(pierwszy>Rozmiar()||drugi>Rozmiar())
			return false;
		d1=wektor[pierwszy];
		d2=wektor[drugi];
		wektor[pierwszy]=d2;
		wektor[drugi]=d1;
		return true;
	}

template <typename T>
void TablicaAsocjacyjna<T>::sort_quicksort(int left, int right)
{
    int l=left;
    int r=right-1;
    int size=right-left;

    if (size > 1)
    {
        Dane pivot = wektor[rand() % size + l];
        //Dane pivot = wektor[size/2];
        while (l<r)
        {
            while (wektor[r].adres > pivot.adres && r>l)
                r--;
            while (wektor[l].adres < pivot.adres && l<=r)
                l++;
            if (l<r) 
            {
                Zamien(l, r);
                l++;
            }
        }

        sort_quicksort(left, l);
        sort_quicksort(r, right);
    }
}
