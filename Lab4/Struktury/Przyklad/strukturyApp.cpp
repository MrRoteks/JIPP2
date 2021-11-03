#include<iostream>
using namespace std;
//struktura globalna widoczna w każdym zakątku
struct czlowiek{
    char imie[20];
    char nazwisko[20];
    int wiek;
    double wzrost;
};//tu mozna odrazu zdefiniowac zmienne typu "czlowiek"
        //np.: }kasia/osoba1;
        //lub tez: }osoba1={"kasia","nowak",...}

int main()
{
    int liczba_osob = 3;

    czlowiek osoba[] = {{"Kasia","Nowak",22,1.65},
                        {"Anna","Kowalska",24,1.67},
                        {}};

    cout<<"Podaj imie, nazwisko, wiek oraz wzrost trzeciej osoby: ";
    cin>>osoba[2].imie>>osoba[2].nazwisko>>osoba[2].wiek>>osoba[2].wzrost;

    cout << "Imie\tNazwisko \tWiek \tWzrost" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < liczba_osob; i++)
    {
        cout << osoba[i].imie << "\t" << osoba[i].nazwisko << "\t" << osoba[i].wiek <<    	  "\t" << osoba[i].wzrost << endl;
    }

    return 0;
}