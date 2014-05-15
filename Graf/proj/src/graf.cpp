#include "graf.hh"

 /*!
 * \file
 * \brief Definicje metod klasy Graf.
 */

void Graf::Dodaj_wierzcholek(int v)
{	
	//_liczba_wierzcholkow=v+1;  
	_wierzcholek wierzcholek;

	_wektor_wierzcholkow.push_back(wierzcholek);
	_wektor_wierzcholkow[v]._czy_istnieje=true;
	_wektor_wierzcholkow[v]._numer=v;
	
	if(v==0)
	{
		_tab_sasiedztwa = new char * [_wektor_wierzcholkow.size()];    // Tworzymy tablicę wskaźników
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++)
			_tab_sasiedztwa[i] = new char [_wektor_wierzcholkow.size()]; // Tworzymy wiersze

		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++) // Macierz wypełniamy zerami
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++)
				_tab_sasiedztwa[i][j] = 0;
	/*
		_tab_wierzcholkow = new int [_liczba_wierzcholkow]; //tworzymy tablice wierzcholkow
		_tab_wierzcholkow[v]=1; //element istnieje*/
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
		
		/*cout << "   ";
	for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++) 
		cout << setw(3) << i;
	cout << endl << endl;
	for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++)
	{
		cout << setw(3) << i;
		for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++) 
			cout << setw(3) << (int) B[i][j];
		cout << endl;
	}
  cout << endl;*/
		
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size()-1; i++)
		{
		//	B[i] = _tab_sasiedztwa[i]; //przepisuje stara tablice do pomocniczej
			
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size()-1; j++)
				B[i][j]=_tab_sasiedztwa[i][j];
		}
		
			
			
		/*
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size()-1; i++) //usuwam tablice
			delete [] _tab_sasiedztwa[i];
		delete [] _tab_sasiedztwa;
		*/
		_tab_sasiedztwa = new char * [_wektor_wierzcholkow.size()]; //tworze nowa tablice
		
		for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++)
		{
			_tab_sasiedztwa[i] = new char [_wektor_wierzcholkow.size()]; //tworze wiersze
			
			//for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++)
				//_tab_sasiedztwa[i][j] = 0;
			
			for(unsigned int j = 0; j < _wektor_wierzcholkow.size(); j++) //przepisuje dane
				_tab_sasiedztwa[i][j]=B[i][j];
		}

	//	for(unsigned int i = 0; i < _wektor_wierzcholkow.size(); i++) //usuwam pomocnicza tablice
		//	delete [] B[i];
		//delete [] B;	
	
	/*	tab_pom=new int[_wektor_wierzcholkow.size()];
		
		for(int i=0; i<_wektor_wierzcholkow.size()-1; i++)
			tab_pom[i]=_tab_wierzcholkow[i];
		_tab_wierzcholkow=new int [_wektor_wierzcholkow.size()];
		
		for(int i=0; i<_wektor_wierzcholkow.size(); i++)
			_tab_wierzcholkow[i]=tab_pom[i];
		_tab_wierzcholkow[v]=1;
		
		delete [] tab_pom;*/
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
	
	for(int i=0; i<_wektor_krawedzi.size(); i++)
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
	// Wypisujemy zawartość macierzy sąsiedztwa

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

void Graf::Sasiedztwo(int v)
{
	int jest=0;
	
	for(unsigned int i=0; i<_wektor_wierzcholkow.size(); i++)
	{
		if(_tab_sasiedztwa[v][i]==1)
		{
			cout<<"Wierzcholek numer "<<v<<" sasiaduje z wierzcholkiem numer "<<i<<endl;
			jest=1;
		}
	}
	if(jest!=1)
		cout<<"Wierzcholek numer "<<v<<" nie ma sasiadow."<<endl;
}

bool Graf::Czy_istnieje(int v)
{
	if(_wektor_wierzcholkow[v]._czy_istnieje==true)
		return true;
	else 
		return false;
}
/*
void Graf::DFS(int poczatkowy, int szukany)
{
	_wektor_wierzcholkow[poczatkowy]._czy_odwiedzony=true;
	
	if(poczatkowy==szukany)
	{
		cout<<"DFS: Znaleziono!"<<endl;
		for(int i=0; i<(int)_wektor_wierzcholkow.size(); i++)
			_wektor_wierzcholkow[i]._czy_odwiedzony=false;
	}
	else
	{
		for(int i=0; i<(int)_wektor_wierzcholkow.size(); i++)
			if(_tab_sasiedztwa[poczatkowy][i]==1 && _wektor_wierzcholkow[i]._czy_odwiedzony==false)
				DFS(i, szukany);
	}		
}*/

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
		cout<<"DFS: Znaleziono! Element: "<<v<<endl;
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
				cout<<"BFS: Znaleziono! Element: "<<glowa->_dane<<endl;
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
