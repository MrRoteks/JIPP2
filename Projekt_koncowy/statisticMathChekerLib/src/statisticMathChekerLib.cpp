#include <iostream>
#include "../include/statisticMathChekerLib.h"
#include <iomanip>
#include <math.h>
using namespace std;

/**
 * help - wyswietla pomocnicze informacje dotyczace programu
 */
void help()
{
    cout<<"------------------------statCalc - HELP:------------------------"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"Dostepne dzialania: "<<endl;
    cout<<"0. - wyjscie z programu."<<endl;
    cout<<"1. - wariancja."<<endl;
    cout<<"--------------------------KONIEC--------------------------------------"<<endl;

}


void wariancja()
{
    int n=0;
    double wynik=0,wynik2=0,srednia=0,szereg=0;

    cout<<"---Wybrano dzialanie: [Wariancja]---"<<endl;
    cout<<"Podaj ilosc cyfr: ";
    cin>>n;
    cout<<"Podaj cyfry (odziel spacja): ";
    double x[n];
    for (int i=0; i<n;i++)
        cin>>x[i];

    cout<<"Podano "<<n<<" cyfr: "<<endl;
    for (int i=0; i<n;i++) {
        cout << x[i] << ", ";
        srednia+=x[i];
    }
    srednia=srednia/n;
    cout<<"srednia = "<<srednia<<endl;
    for (int i=0; i<n;i++)
    {
        szereg+=(x[i]-srednia)*(x[i]-srednia);
    }

    wynik=szereg/(n-1);
    wynik2=sqrt(wynik);
    cout<<"\nWariancja = "<<wynik<<endl;
    cout<<"Odchylenie standardowe = "<<wynik2<<endl;
}