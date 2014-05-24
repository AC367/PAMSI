#include "graf.hh"

 /*!
 * \file
 * \brief Definicje metod klasy Graf.
 */

void Graf::Dodaj_wierzcholek(int v, int wsp_x, int wsp_y)
{	
	_wierzcholek wierzcholek;

	_wektor_wierzcholkow.push_back(wierzcholek);
	_wektor_wierzcholkow[v]._czy_istnieje=true;
	_wektor_wierzcholkow[v]._numer=v;
	_wektor_wierzcholkow[v]._wsp_x=wsp_x;
	_wektor_wierzcholkow[v]._wsp_y=wsp_y;
	
	if(_wektor_wierzcholkow.size()==0)
	{
		_tab_sasiedztwa = new char * [_wektor_wierzcholkow.size()];    // Tworzymy tablicę wskaźników
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++)
			_tab_sasiedztwa[i] = new char [_wektor_wierzcholkow.size()]; // Tworzymy wiersze

		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++) // Macierz wypełniamy zerami
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++)
				_tab_sasiedztwa[i][j] = 0;
	}
	else
	{
		char ** B;
		
		B = new char * [_wektor_wierzcholkow.size()]; //tworze tablice pomocnicza
		
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++) 
		{
			B[i] = new char [_wektor_wierzcholkow.size()]; //tworze wiersze
			
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++)
				B[i][j] = 0;
		}
		
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size()-1; i++)
		{
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size()-1; j++)
				B[i][j]=_tab_sasiedztwa[i][j];
		}
		
	
		_tab_sasiedztwa = new char * [_wektor_wierzcholkow.size()]; //tworze nowa tablice
		
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++)
		{
			_tab_sasiedztwa[i] = new char [_wektor_wierzcholkow.size()]; //tworze wiersze
			
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++) //przepisuje dane
				_tab_sasiedztwa[i][j]=B[i][j];
		}
	}
}

void Graf::Usun_wierzcholek(int v)
{	
	_wektor_wierzcholkow[v]._czy_istnieje=false;
}
	
void Graf::Dodaj_krawedz(int v1, int v2, int waga)
{
	_krawedz krawedz;
	
	_tab_sasiedztwa[v1][v2] = 1;  // Krawędź v1->v2 obecna
	_tab_sasiedztwa[v2][v1] = 1;  // Krawędź v2->v1 obecna
	
	krawedz.pierwszy=&_wektor_wierzcholkow[v1];
	krawedz.drugi=&_wektor_wierzcholkow[v2];
	krawedz.waga=waga;
	
	_wektor_krawedzi.push_back(krawedz);
}

void Graf::Usun_krawedz(int v1, int v2)
{
	_tab_sasiedztwa[v1][v2]=0;
	_tab_sasiedztwa[v2][v1]=0;
	
	for(unsigned int i=0; i<_wektor_krawedzi.size(); i++)
	{
		if((_wektor_krawedzi[i].pierwszy->_numer==v1 && _wektor_krawedzi[i].drugi->_numer==v2)
		||(_wektor_krawedzi[i].pierwszy->_numer==v2 && _wektor_krawedzi[i].drugi->_numer==v1))
		{
			_wektor_krawedzi.erase(_wektor_krawedzi.begin()+i);
		}
	}
}

bool Graf::Czy_polaczone(int v1, int v2)
{
	if(_tab_sasiedztwa[v1][v2]==1)
		return true;
	else
		return false;
}

void Graf::Wypisz_macierz()
{
	cout << "   ";
	for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++) 
		cout << setw(3) << i;
	cout << endl << endl;
	for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++)
	{
		cout << setw(3) << i;
		for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++) 
			cout << setw(3) << (int) _tab_sasiedztwa[i][j];
		cout << endl;
	}
  cout << endl;
}

vector<int> Graf::Sasiedztwo(int v)
{
	int wielkosc=0;
	vector <int> pom;
		
	for(unsigned int i=0; i<_wektor_wierzcholkow.size(); i++)
		if(_tab_sasiedztwa[v][i]==1)
		{
			wielkosc++;
			pom.push_back(i);
		}	
	if(wielkosc==0)
	{
		cout<<"Wierzcholek numer "<<v<<" nie ma sasiadow."<<endl;
		pom[0]=-1;
		return pom;
	}
	else
	{
		return pom;
	}
}

bool Graf::Czy_istnieje(int v)
{
	if(_wektor_wierzcholkow[v]._czy_istnieje==true)
		return true;
	else 
		return false;
}

int Graf::Nastepny_DFS(int v)
{
	int i;
 
	for (i=_wektor_wierzcholkow.size()-1;i>=0;i--)
		if ((_tab_sasiedztwa[i][v]==1)&&(_wektor_wierzcholkow[i]._czy_odwiedzony==false))
		{
			_wektor_wierzcholkow[i]._czy_odwiedzony=true;
			return(i);
		}
	return(-1);
}

void Graf::DFS(int v, int szukany)
{
	int u;
	int nastepny;
	
	if(v==szukany)
	{
		//cout<<"DFS: Znaleziono! Element: "<<v<<endl;
		for(int i=0; i<(int)_wektor_wierzcholkow.size(); i++)
			_wektor_wierzcholkow[i]._czy_odwiedzony=false;
	}
	else
	{
	_wektor_wierzcholkow[v]._czy_odwiedzony=true;
	nastepny=Nastepny_DFS(v);
	while (nastepny!=-1)
	{
		_stos_DFS.push(nastepny);
		nastepny=Nastepny_DFS(v);
	}
	if (!_stos_DFS.empty())
	{
		u=_stos_DFS.top();
		_stos_DFS.pop();
		DFS(u, szukany);
	}
 }
}

void Graf::BFS(int poczatkowy, int szukany)
{
		_lista_BFS *q, *glowa, *ogon;
		
		q=new _lista_BFS;
		q->_nastepny=NULL;
		q->_dane=poczatkowy;
		glowa=ogon=q;
		_wektor_wierzcholkow[poczatkowy]._czy_odwiedzony=true;
		
		while(glowa)
		{
			if(glowa->_dane==szukany)
			{
				//cout<<"BFS: Znaleziono! Element: "<<glowa->_dane<<endl;
				for(int i=0; i<(int)_wektor_wierzcholkow.size(); i++)
					_wektor_wierzcholkow[i]._czy_odwiedzony=false;
				glowa=NULL;
			}
			else
			{
			poczatkowy=glowa->_dane;
			q=glowa;
			glowa=glowa->_nastepny;
			if(!glowa)
				ogon=NULL;
			delete q;
			
			for(int i=0; i<(int)_wektor_wierzcholkow.size(); i++)
			{
				if(_tab_sasiedztwa[poczatkowy][i]==1 && _wektor_wierzcholkow[i]._czy_odwiedzony==false)
				{	
					q=new _lista_BFS;
					q->_nastepny=NULL;
					q->_dane=i;
					if(!ogon)
						glowa=q;
					else
						ogon->_nastepny=q;
					ogon=q;
					_wektor_wierzcholkow[i]._czy_odwiedzony=true;
				}
			}
		}	
	}
}

bool Graf::A_star(int poczatkowy, int koncowy)
{
	vector<int> Lista_otwartych;
	vector<int> Lista_zamknietych;
	
	int koszt, najnizszy_koszt, obecny=0;
	
	Lista_otwartych.push_back(poczatkowy);
	
	
	_wektor_wierzcholkow[poczatkowy]._G=0;
	_wektor_wierzcholkow[poczatkowy]._H=Odleglosc(poczatkowy, koncowy);
	_wektor_wierzcholkow[poczatkowy]._F=_wektor_wierzcholkow[poczatkowy]._G + _wektor_wierzcholkow[poczatkowy]._H;
	najnizszy_koszt=_wektor_wierzcholkow[poczatkowy]._F;
	while(!Lista_otwartych.empty())
	{
		obecny=Lista_otwartych[0];
		najnizszy_koszt=_wektor_wierzcholkow[obecny]._F;
		for(unsigned int i=0; i<Lista_otwartych.size(); i++) //szukam elementu o najmniejszym _F
		{
			if(najnizszy_koszt>_wektor_wierzcholkow[Lista_otwartych[i]]._F)
			{	
				najnizszy_koszt=_wektor_wierzcholkow[Lista_otwartych[i]]._F;
				obecny=Lista_otwartych[i];
				
			}
		}
		if(obecny==koncowy) //jesli znaleziono to przerwij
		{
			//cout<<"Znaleziono wierzcholek: "<<obecny<<endl;
			//cout<<endl;
			Odtworz_sciezke(poczatkowy, koncowy);
			return true;
		}
		Lista_otwartych.erase(Lista_otwartych.begin());
		Lista_zamknietych.push_back(obecny);
		
		for(unsigned int i=0; i<Sasiedztwo(obecny).size(); i++) // dla kazdego z sasiadow
		{	
			int sasiad=Sasiedztwo(obecny)[i];
			
			_wektor_wierzcholkow[sasiad]._G=Znajdz_krawedz(obecny, sasiad).waga + _wektor_wierzcholkow[obecny]._G;
			
			if(Czy_na_liscie(Lista_zamknietych, sasiad)) //jesli jest na liscie zamknietych - przejdz do nastepnego
				continue;
				
			koszt=_wektor_wierzcholkow[obecny]._G + Znajdz_krawedz(obecny, sasiad).waga;// szacuj koszt
			
			if(!Czy_na_liscie(Lista_otwartych, sasiad) || koszt<_wektor_wierzcholkow[sasiad]._G)
			{
				_wektor_wierzcholkow[sasiad]._G=koszt;
				_wektor_wierzcholkow[sasiad]._H=Odleglosc(sasiad, koncowy);
				_wektor_wierzcholkow[sasiad]._F=_wektor_wierzcholkow[sasiad]._G + _wektor_wierzcholkow[sasiad]._H;
				_wektor_wierzcholkow[sasiad]._rodzic=&_wektor_wierzcholkow[obecny];

				if(!Czy_na_liscie(Lista_otwartych, sasiad))
				{
					Lista_otwartych.push_back(sasiad);
				}
			}	
		}
	}
	//cout<<"Nie znaleziono!"<<endl;
	return false;
}

void Graf::Odtworz_sciezke(int poczatkowy, int koncowy)
{
	_wierzcholek obecny=_wektor_wierzcholkow[koncowy];
	vector<int> wektor;
	
	wektor.push_back(obecny._numer);
	cout<<"Odtworzona sciezka: "<<endl;
	while(obecny._numer!=poczatkowy)
	{
		wektor.push_back(obecny._rodzic->_numer);
		obecny._rodzic=obecny._rodzic->_rodzic;
		obecny._numer=obecny._rodzic->_numer;
	}
	wektor.push_back(obecny._numer);
	for(int i=wektor.size()-1; i>=0; i--)
		cout<<wektor[i]<<" ";
	cout<<endl;
}
	
bool Graf::Czy_na_liscie(vector <int> lista, int element)
{
	if(!lista.empty())
		for(unsigned int i=0; i<lista.size(); i++)
			if(lista[i]==element)
				return true;
	return false;
}

Graf::_krawedz Graf::Znajdz_krawedz(int v1, int v2)
{
	for(unsigned int i=0; i<_wektor_krawedzi.size(); i++)
	{
		if((_wektor_krawedzi[i].pierwszy->_numer==v1 && _wektor_krawedzi[i].drugi->_numer==v2)
		||(_wektor_krawedzi[i].pierwszy->_numer==v2 && _wektor_krawedzi[i].drugi->_numer==v1))
		{
			return _wektor_krawedzi[i];
		}
	}
	return _wektor_krawedzi[1];
}

int Graf::Odleglosc(int v1, int v2)
{
	int x1=_wektor_wierzcholkow[v1]._wsp_x;
	int x2=_wektor_wierzcholkow[v2]._wsp_x;
	int y1=_wektor_wierzcholkow[v1]._wsp_y;
	int y2=_wektor_wierzcholkow[v2]._wsp_y;
	int x, y;
	
	x=x1-x2;
	y=y1-y2;
	
	return (sqrt((x*x) + (y*y)));
}
