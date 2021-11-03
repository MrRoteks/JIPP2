#include<iostream>
using namespace std;


//struktura globalna widoczna w każdym zakątku
struct samochod{
    string marka;
    string model;
    string kolor;
    int rokProdukcji;
    bool uszkodzony;
};//tu mozna odrazu zdefiniowac zmienne typu "czlowiek"
//np.: }kasia/osoba1;
//lub tez: }osoba1={"kasia","nowak",...}
string porownanieMarek(samochod pojazd[],int liczba_pojazdow);
int zliczMarki(samochod pojazd[],int liczba_pojazdow);
int rokProdukcjiMin(samochod pojazd[],int liczba_pojazdow);

int main()
{
    int liczba_pojazdow = 4;

    samochod pojazdy[] = {
            {"Subaru","XV","Granatowy",2020,false},
            {"Toyota","Yaris","Szary",2001,true},
            {"Fiat","Tipo","Niebieski",2021,true},
            {"Fiat","126","Czerwony",1976,false}
    };


    cout << "Marka\tModel \tKolor \tRok produkcji\tUszkodzenia" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < liczba_pojazdow; i++)
    {
        cout << pojazdy[i].marka << "\t" << pojazdy[i].model << "\t" << pojazdy[i].kolor << "\t" << pojazdy[i].rokProdukcji <<"\t"<<pojazdy[i].uszkodzony<< endl;
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout<<"Powtarzajaca sie marka: "<<porownanieMarek(pojazdy,liczba_pojazdow)<<"\tIlosc powtorzen: "<<zliczMarki(pojazdy,liczba_pojazdow)<< endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Najmnizszy rok produkcji: " <<rokProdukcjiMin(pojazdy,liczba_pojazdow)<< endl;


    return 0;

}


string porownanieMarek(samochod pojazd[],int liczba_pojazdow)
{
    int x=-1;
    for (int i = 0; i < liczba_pojazdow-1; i++)
    {
       if(pojazd[i].marka==pojazd[i+1].marka) {
            x=i;
        }
    }
    if(x==-1)
        return "Brak";
    return pojazd[x].marka;
}

int zliczMarki(samochod pojazd[],int liczba_pojazdow)
{
    int x=0;
    for (int i = 0; i < liczba_pojazdow-1; i++)
    {
        if(pojazd[i].marka==pojazd[i+1].marka) {
            x++;
        }
    }
    return x;
}

int rokProdukcjiMin(samochod pojazd[],int liczba_pojazdow)
{
    int x=pojazd[0].rokProdukcji;
    for (int i = 0; i < liczba_pojazdow; i++)
    {
        if(pojazd[i].rokProdukcji<x) {
            x=pojazd[i].rokProdukcji;
        }
    }

    return x;
}
