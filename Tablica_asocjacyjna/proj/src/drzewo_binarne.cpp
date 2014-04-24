#include "drzewo_binarne.hh"

 /*!
 * \file
 * \brief Definicje metod klasy Drzewo_binarne.
 */

bool Drzewo_binarne::Czy_puste() const 
{ 
	return korzen==NULL;
}

void Drzewo_binarne::dodaj(string adres, string d)
{
    galaz* t = new galaz;
    galaz* rodzic;
    t->adres=adres;
    t->dane = d;
    t->lewa = NULL;
    t->prawa = NULL;
    rodzic = NULL;
    
    if(Czy_puste())
		korzen = t;
    else
    {
        galaz* curr;
        curr = korzen;
        while(curr)
        {
           rodzic = curr;
           if(curr->adres==adres)
           {
				curr->dane=d;
				return;
		   }
           else if(t->adres > curr->adres) 
				curr = curr->prawa;
           else 
				curr = curr->lewa;
        }
        if(t->adres < rodzic->adres)
           rodzic->lewa = t;
        else
           rodzic->prawa = t;
    }
    rozmiar++;
}

void Drzewo_binarne::usun(string adres)
{
    bool znaleziono = false;
    if(Czy_puste())
    {
        cout<<" Drzewo jest puste! "<<endl;
        return;
    }
    
    galaz* curr;
    galaz* rodzic;
    curr = korzen;
    
    while(curr != NULL)
    {
         if(curr->adres == adres)
         {
            znaleziono = true;
            break;
         }
         else
         {
             rodzic = curr;
             if(adres>curr->adres) curr = curr->prawa;
             else curr = curr->lewa;
         }
    }
    if(!znaleziono)
    {
        cout<<" nie znaleziono danej! "<<endl;
        return;
    }

    if((curr->lewa == NULL && curr->prawa != NULL)|| (curr->lewa != NULL && curr->prawa == NULL))
    {
       if(curr->lewa == NULL && curr->prawa != NULL)
       {
           if(rodzic->lewa == curr)
           {
             rodzic->lewa = curr->prawa;
             delete curr;
           }
           else
           {
             rodzic->prawa = curr->prawa;
             delete curr;
           }
       }
       else
       {
          if(rodzic->lewa == curr)
           {
             rodzic->lewa = curr->lewa;
             delete curr;
           }
           else
           {
             rodzic->prawa = curr->lewa;
             delete curr;
           }
       }
     rozmiar--;
     return;
    }

		 if( curr->lewa == NULL && curr->prawa == NULL)
    {
        if(rodzic->lewa == curr) rodzic->lewa = NULL;
        else rodzic->prawa = NULL;
		 		 delete curr;
		 		 rozmiar--;
		 		 return;
    }

    if (curr->lewa != NULL && curr->prawa != NULL)
    {
        galaz* chkr;
        chkr = curr->prawa;
        if((chkr->lewa == NULL) && (chkr->prawa == NULL))
        {
            curr = chkr;
            delete chkr;
            rozmiar--;
            curr->prawa = NULL;
        }
        else
        {

            if((curr->prawa)->lewa != NULL)
            {
                galaz* lcurr;
                galaz* lcurrp;
                lcurrp = curr->prawa;
                lcurr = (curr->prawa)->lewa;
                while(lcurr->lewa != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->lewa;
                }
				curr->adres = lcurr->adres;
                delete lcurr;
                rozmiar--;
                lcurrp->lewa = NULL;
           }
           else
           {
               galaz* tmp;
               tmp = curr->prawa;
               curr->dane = tmp->dane;
			   curr->prawa = tmp->prawa;
               delete tmp;
           }

        }
		 rozmiar--;
		 return;
    }

}

void Drzewo_binarne::wyswietl_kolejno()
{
  kolejno(korzen);
}

void Drzewo_binarne::kolejno(galaz* p)
{
    if(p != NULL)
    {
        if(p->lewa) 
			kolejno(p->lewa);
        cout<<" "<<p->dane<<endl;
        if(p->prawa) 
			kolejno(p->prawa);
    }
    else return;
}

bool Drzewo_binarne::czy_jest(string adres)
{
	galaz* curr;
    curr = korzen;
	
	bool znaleziono = false;
    if(Czy_puste())
        return false;
        
    while(curr != NULL)
    {
         if(curr->adres == adres)
         {
            znaleziono = true;
            break;
         }
         else
         {
             if(adres>curr->adres) curr = curr->prawa;
             else curr = curr->lewa;
         }
    }
    if(!znaleziono)
    {
        return false;
    }
    return true;
}
