#include <iostream>
#include <string>
#include <sstream>

/*!
 * \file
 * \brief Zawiera definicje klase Tablica_haszujaca oraz Element, ich metod oraz
 * instrukcje załączenia poszczególnych bibliotek.
 */


using namespace std;

/*!
 * \brief Klasa definiująca element umieszczany w tablicy asocjacyjnej.
 * 
 * Klasa ta zawiera wskaźnik na następny element oraz pola przechowujące adres
 * i dane elementu. Jest tu również pole, "zajety" decydujące o możliwości
 * nadpisania danego elementu. 
 * Ponadto zawarte są w niej deklaracje metod oraz konstruktor.
 */ 
class Element
{
private:
	string dane;

public:
	string adres;
	bool zajety;
	Element *nastepny;
	
	Element()
	:zajety(NULL), nastepny(NULL)
	{
	}
	
	friend class Tablica_haszujaca;
/*!
 * \brief Przeładowanie operatora wyjścia.
 * 
 * Ten przeładowany operator wyjścia odpowiada za podwanie na standardowe
 * wyjście zawartości obiektu klasy Element.
 * 
 * @param [out] ostr - strumień wyjściowy.
 * @param [in] elem - drukowany obiekt.
 */ 
	friend ostream& operator <<(ostream& ostr, Element& elem);
};

/*!
 * \brief Klasa definiująca tablicę haszującą realizującą implementację
 * tablicy asocjacyjnej.
 * 
 * Klasa ta zawiera wskaźnik na obiekt klasy Element, pole przechowujące
 * informację o rozmairze oraz deklaracje konstruktora i metod. 
 */ 
class Tablica_haszujaca
{
private:
	Element * _element;
	int rozmiar;
public:
	

	friend class Element;
	
/*!
 * \brief Kostruktor.
 * 
 * Inicjuje pola obiektu klasy Tablica_haszujaca.
 */ 
	Tablica_haszujaca(int il);
	
/*!
 * \brief Przeładowanie operatora [].
 * 
 * Ten przeładowany operator odpowiada za zwrócenie obiektu klasy
 * Element o podanym adresie.
 * 
 * @param [in] adres - adres wywoływanego obiektu.
 */ 
	Element* operator [](string adres);
	
/*!
 * \brief Dodaje elementy.
 * 
 * Ta metoda ma za zadanie dodać element o określonym adresie do tablicy
 * asocjacyjnej.
 * W przypaku, gdy element o podanym adresie (lub kluczu) już istnieje następuje dopisanie
 * kolejnej wartości do listy przypisanej danemu adresowi.
 *
 * @param [in] adres - adres pod którym ma zostać umieszczony element.
 * @param [in] dane - wartość, która ma zostać umieszczona w tablicy.
 */ 
	void dodaj(string adres, string dane);
	
/*!
 * \brief Usuwa elementy.
 * 
 * Ta metoda ma zmienia zawartość pola "zajety" elementu tablicy, przez
 * co umożliwia jego nadpisanie.
 *
 * @param [in] adres - adres usuwanego elementu.
 */ 
	void usun(string adres);
	
/*!
 * \brief Znajduje elementy.
 * 
 * Ta metoda ma za zadanie znaleźć i zwrócić obiekt o podanym adresie.
 *
 * @param [in] adres - adres szukanego elementu.
 */ 
	Element* znajdz(string adres);
	
/*!
 * \brief Tworzy klucz.
 * 
 * Ta metoda tworzy klucz (indeks) na podstawie adresu elementu.
 *
 * @param [in] adres - adres elementu.
 */ 
	int haszuj(string adres);
};
