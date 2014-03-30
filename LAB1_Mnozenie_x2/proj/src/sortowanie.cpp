#include "sortowanie.hh"

/*!
 * \file
 * \brief Zawiera definicje funkcji uzytych w algorytmach sortujacych.
 */

//void sort_quicksort(Dane &wekt, int poczatek, int koniec )
void sort_quicksort(Dane &wekt, int left, int right)
{
    int l=left;
    int r=right-1;
    int size=right-left;

    if (size > 1)
    {
        //int pivot = wekt.Wektor[rand() % size + l];
		int pivot=wekt.Wektor[(left+right)/2];
        while (l<r)
        {
            while (wekt.Wektor[r]>pivot && r>l)
                r--;
            while (wekt.Wektor[l] < pivot && l<=r)
                l++;
            if (l<r) 
            {
                wekt.Zamien_elementy(wekt, l, r);
                l++;
            }
        }

        sort_quicksort(wekt, left, l);
        sort_quicksort(wekt, r, right);
    }
    //cout<<wekt<<endl;
}
 
void sort_heapsort(Dane &wekt, int rozmiar)
{
	int z;
	
	z=1;
	for (int i=rozmiar/2;i>0;i--)
		sort_kopiec(wekt,rozmiar, i);
	for (int i=rozmiar;i>z;i--)
	{
		wekt.Zamien_elementy(wekt, i, z);
		rozmiar--;
		sort_kopiec(wekt,rozmiar,z);
	}
}

void sort_kopiec(Dane &wekt, int rozmiar, int i)
{
	int szczyt;
	int temp;
	int x=2*i;
	int y=(2*i)+1;

	if (x<=rozmiar && wekt.Wektor[x]>wekt.Wektor[i])
		szczyt=x;
	else 
		szczyt=i;
	if (y<=rozmiar && wekt.Wektor[y]>wekt.Wektor[szczyt])
		szczyt=y;
	if (szczyt!=i)
	{
		temp=wekt.Wektor[szczyt];
		wekt.Wektor[szczyt]=wekt.Wektor[i];
		wekt.Wektor[i]=temp;
		sort_kopiec(wekt,rozmiar,szczyt);
	}
}

void sort_mergesort(Dane &wekt, Dane wekt_p, int poczatek, int koniec)
{
    int pivot;
    
    if(poczatek<koniec)
    {
        pivot=(poczatek+koniec)/2;
        sort_mergesort(wekt,wekt_p,pivot+1,koniec);
        sort_mergesort(wekt,wekt_p,poczatek,pivot);
        sort_scal(wekt,wekt_p,poczatek,pivot,koniec);
    }
}

void sort_scal(Dane &wekt, Dane wekt_p, int poczatek, int pivot, int koniec)
{
    int k;
    int p;
    int j;
    int i;
 
	p=poczatek;
	i=p;
	j=pivot+1;
    while((p<=pivot)&&(j<=koniec))
    {
        if(wekt.Wektor[p]<=wekt.Wektor[j])
        {
            wekt_p.Wektor[i]=wekt.Wektor[p];
            p++;
        }
        else
        {
            wekt_p.Wektor[i]=wekt.Wektor[j];
            j++;
        }
        i++;
    }
    if(p>pivot)
    {
        for(k=j; k<=koniec; k++)
        {
            wekt_p.Wektor[i]=wekt.Wektor[k];
            i++;
        }
    }
    else
    {
        for(k=p; k<=pivot; k++)
        {
            wekt_p.Wektor[i]=wekt.Wektor[k];
            i++;
        }
    }
    for(k=poczatek; k<=koniec; k++)
		wekt.Wektor[k]=wekt_p.Wektor[k];
}
