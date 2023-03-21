//POP 2021-01-19 projekt 2 Podlinska Magdalena EIT 3 184441 Code::Blocks 20.03
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


//Funkcja sprawdzajaca czy dany znajomy znajomego nie powtorzyl sie w pliku
bool czy_powtarza(string my, string znajomy_znajomego)
{
    string osoba1;
    string osoba2;

    fstream pomoc1;

    pomoc1.open("probny1.txt",ios::in);

    while(pomoc1>>osoba1>>osoba2)
    {
        if(osoba1==my and osoba2==znajomy_znajomego) //Jezeli znajomy znajomego powtorzyl sie w liscie znajomych znajomych
        {
            return true;
        }
    }
    pomoc1.close();
    return false;
}

//Funkcja sprawdzajaca czy znajomy znajomego nie jest tez naszym znajomym
bool czy_nasz_znajomy(string my, string osoba, string nazwa)
{
    fstream plik;

    string osoba1;
    string osoba2;

    plik.open(nazwa,ios::in);

    while(plik>>osoba1>>osoba2)
    {
        if(my==osoba1 and osoba==osoba2) //Jezeli znajomy znajomego jest jednoczesnie naszym znajomym
        {
            return true;
        }
        if(osoba==osoba1 and my==osoba2) //Jezeli znajomy znajomego jest jednoczesnie naszym znajomym
        {
            return true;
        }
    }

    plik.close();

    return false;
}

//Przypisywanie znajomych znajomych do danej osoby
void znajomi(string my, string znajomy, string nazwa)
{
    fstream plik;
    fstream pomoc1;

    string osoba1;
    string osoba2;

    plik.open(nazwa,ios::in);

    while(plik>>osoba1>>osoba2)
    {
        //Je¿eli osoba1 jest znajomym osoby dla ktorej tworzymy liste i osoba2 nie jest osoba dla ktorej tworzymy liste i ta para osob nie
        //powtarza sie w pliku pomocniczym nr 1 i znajomy znajomego nie jest jednoczesnie naszym znajomym
        if(osoba1==znajomy and osoba2!=my and czy_powtarza(my,osoba2)==false and czy_nasz_znajomy(my,osoba2,nazwa)==false)
        {
            pomoc1.open("probny1.txt",ios::out | ios::app);
            pomoc1<<my<<" "<<osoba2<<endl;
            pomoc1.close();
        }
        //Je¿eli osoba2 jest znajomym osoby dla ktorej tworzymy liste i osoba1 nie jest osoba dla ktorej tworzymy liste i ta para osob nie
        //powtarza sie w pliku pomocniczym nr 1 i znajomy znajomego nie jest jednoczesnie naszym znajomym
        if(osoba1!=my and osoba2==znajomy and czy_powtarza(my,osoba1)==false and czy_nasz_znajomy(my,osoba1,nazwa)==false)
        {
            pomoc1.open("probny1.txt",ios::out | ios::app);
            pomoc1<<my<<" "<<osoba1<<endl;
            pomoc1.close();
        }
    }
    plik.close();
}

//Wyodrebnienie znajomego osoby dla ktorej tworzymy liste znajomych znajomych, od ktorego bedziemy brali znajomych znajomych
void relacja(string my, string nazwa)
{
    string osoba1;
    string osoba2;

    fstream plik;

    plik.open(nazwa,ios::in);

    while(plik>>osoba1>>osoba2)
    {
        if(osoba1==my) //Je¿eli osoba1 jest osoba dla ktorej tworzymy liste znajomych znajomych
        {
            znajomi(my,osoba2,nazwa);
        }
        if(osoba2==my)  //Je¿eli osoba1 jest osoba dla ktorej tworzymy liste znajomych znajomych
        {
            znajomi(my,osoba1,nazwa);
        }
    }
    plik.close();
}

//Funkcja wpisujaca dla danej osoby znajomych znajomych w jednej linii
void uzupelnienie(string my)
{
    fstream zz;
    fstream wynik;

    string osoba1;
    string osoba2;

    zz.open("probny1.txt",ios::in);

    while(zz>>osoba1>>osoba2)
    {
        if(osoba1==my) //Jezeli osoba jest osoba dla ktorej tworzymy liste znajomych znajomych
        {
            wynik.open("znajomi_znajomych.txt",ios::out | ios::app); //Zapisanie znajomego znajomego do listy
            wynik<<" "<<osoba2;
            wynik.close();
        }
    }

    zz.close();

    wynik.open("znajomi_znajomych.txt",ios::out | ios::app);
    wynik<<endl;
    wynik.close();

}

//Funkcja sprawdzajaca czy osoba dla ktorej jest robiona lista znajomych znajomych nie powtorzyla sie w pliku wynikowym
bool czy_masz_liste(string my)
{
    fstream pomoc2;

    string osoba;

    pomoc2.open("probny2.txt",ios::in);

    while(pomoc2>>osoba)
    {
        if(osoba==my) //Czy osoba dla ktorej jest robiona lista znajomych znajomych jest w pliku
        {
            return true;
        }
    }

    return false;
}

int main()
{
    fstream plik;
    fstream pomoc1;
    fstream pomoc2;
    fstream wynik;

    string my;

    int i=1;

    string nazwa;
    cout<<"Podaj nazwe pliku z ralacjami: "; cin>> nazwa;

    plik.open(nazwa,ios::in);

    if(plik.good()==false)
    {
        cout<<"Plik nie istnieje! Sprawdz pisownie i sproboj jeszcze raz!";
        exit(0);
    }

    plik.close();

    plik.open(nazwa,ios::in);

    while(plik>>my)     //przetwarzanie danych relacja po relacji
    {
        relacja(my,nazwa);
    }

    plik.close();

    plik.open(nazwa,ios::in);

    while(plik>>my)
    {
        if(i==1)//Czy plik wynikowy zostanie otworzony po raz pierwszy
        {
            pomoc2.open("probny2.txt",ios::out | ios::app); //Zaznaczenie uzycia osoby w pliku pomocniczym nr 2
            pomoc2<<my<<endl;
            pomoc2.close();
            wynik.open("znajomi_znajomych.txt",ios::out | ios::app);    //Wpisanie osoby do pliku wynikowego
            wynik<<my;
            wynik.close();
            uzupelnienie(my);
            i++;
        }
        //Czy plik wynikowy zostanie otworzony po raz ktorys i czy osoba dla ktorej tworzona jest lista nie potworzyla sie w pliku wynikowym
        if(i!=1 and czy_masz_liste(my)==false)
        {
            pomoc2.open("probny2.txt",ios::out | ios::app);    //Zaznaczenie uzycia osoby w pliku pomocniczym nr 2
            pomoc2<<my<<endl;
            pomoc2.close();
            wynik.open("znajomi_znajomych.txt",ios::out | ios::app); //Wpisanie osoby do pliku wynikowego
            wynik<<my;
            wynik.close();
            uzupelnienie(my);
        }
    }

    plik.close();

    pomoc1.open("probny1.txt",ios::out | ios::trunc); //Usuwa dane z pliku pomocniczego nr 1
    pomoc1.close();

    pomoc2.open("probny2.txt",ios::out | ios::trunc);  //Usuwa dane z pliku pomocniczego nr 2
    pomoc2.close();

  return 0;
}
