#include <string>
#include <iostream>
#include <math.h>
using namespace std;

//zadanie1
class Prostopadloscian
{
public:
    double Pole1;
    double Pole2;
    double Pole3;

    double obliczPolePowierzchni(double pole1,double pole2,double pole3)
    {
        double wynik=0;
        wynik = 2*pole1+2*pole2+2*pole3;
        return wynik;
    }
private:

};


//zadanie2
class Kula
{
public:
    double r;

    double obliczObjetosc(double r)
    {
        double V;
        V=(4/3.)*M_PI*pow(r,3);
        return V;
    }

};

//zadanie3
class FunkcjaKwadratowa
{
public:
    double a,b,c;

    void wyswietlFunkcje(double a,double b, double c)
    {
        cout<<"\nF(x)= "<<a<<"x^2 + "<<b<<"x + "<<c;
    }
};

//zadanie4
class Student
{
public:
    string imie;
    string nazwisko;
    int nrAlbumu;
    int liczbaPytan;
    int poprawneOdp;
    void wyswietlDane()
    {

        cout<<"Dane studenta: \nImie: "<<this->imie<<"\nNazwisko: "<<this->nazwisko<<"\nNumer albumu: "<<this->nrAlbumu<<"\nLiczba pytan: "<<this->liczbaPytan<<"\nPoprawne odpowiedzi: "<<this->poprawneOdp<<endl;
        cout<<"Wynik procentowo: "<<this->poprawneOdp/(double)this->liczbaPytan*100<<"%";
    }
};

class przykladGetISet
{
private:
    int wartoscInt;
    string slowo;

public:
    int getWartosc()
    {
        return this->wartoscInt;
    }
    string getSlowo()
    {
        return this->slowo;
    }
    void setWartosc(int nowyInt) {
        this->wartoscInt = nowyInt;
    }
    void setSlowo(string noweSlowo) {
        this->slowo = noweSlowo;
    }
};

class Punkt
{
public:
    int wspolrzedna1,wspolrzedna2;

    void obliczDystans(Punkt k1, Punkt k2)
    {
        double dystans;
        dystans= sqrt( (k2.wspolrzedna1-k1.wspolrzedna1)*(k2.wspolrzedna1-k1.wspolrzedna1)  + (k2.wspolrzedna2-k1.wspolrzedna2)* (k2.wspolrzedna2-k1.wspolrzedna2) );
        cout<<"Dystans miedzy kropkami = "<<dystans<<endl;
    }

    Punkt(int ws1,int ws2);
    ~Punkt();
};
Punkt::Punkt(int ws1,int ws2)
:wspolrzedna1(ws1),wspolrzedna2(ws2)
{
    cout<<"zapisano wspolrzedne: ("<<wspolrzedna1<<", "<<wspolrzedna2<<")"<<endl;

}
Punkt::~Punkt()
{
    cout<<"Zniszczono punkt"<<endl;
}
int main()
{
    /*
     //zadanie 1
     Prostopadloscian kostka;
     cout<<"Podaj 3 pola prostopadloscianu: ";
     cin>>kostka.Pole1>>kostka.Pole2>>kostka.Pole3;
     cout<<"Pole kostki:"<<kostka.obliczPolePowierzchni(kostka.Pole1,kostka.Pole2,kostka.Pole3)<<endl;


    //zadanie2

     Kula kulka;
     cout<<"Podaj promien kuli: "<<endl;
     cin>>kulka.r;
     cout<<"Pole kulki:"<<kulka.obliczObjetosc(kulka.r)<<endl;

    //zadanie3
    FunkcjaKwadratowa wzor;
    cout<<"Podaj wspolczynniki funkcji kwadratowej [a,b,c]: "<<endl;
    cin>>wzor.a>>wzor.b>>wzor.c;
    wzor.wyswietlFunkcje(wzor.a,wzor.b,wzor.c);

//zadanie4
    Student student1;
    cout<<"Podaj dane studenta 1 [imie][nazwisko][nrAlbumu][liczbaPytan][liczbaPoprawnychOdpowiedzi]: ";
    cin>>student1.imie>>student1.nazwisko>>student1.nrAlbumu>>student1.liczbaPytan>>student1.poprawneOdp;
    student1.wyswietlDane();

//zadanie getter i setter
    przykladGetISet wez;
    wez.setWartosc(2);
    wez.setSlowo("abc");
    cout<<"int: "<<wez.getWartosc()<<endl;
    cout<<"string: "<<wez.getSlowo()<<endl;
  */
//zadanie Konstruktor

    int ws1=1,ws2=1;
    Punkt kropka1(ws1,ws2);
    ws1=2; ws2=2;
    Punkt kropka2(ws1,ws2);
    kropka1.obliczDystans(kropka1,kropka2);


    // zadanie destruktor
    Punkt *kropka3;
    kropka3=new Punkt(9,9);
    delete kropka3;

    return(0);
}

