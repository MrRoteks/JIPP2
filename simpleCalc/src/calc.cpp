#include "../include/calc.h"
#include <iostream>

using namespace std;

void helpMsg()
{
    cout<<"Simple calculator\n---------HELP--------\n";
    cout<<"Uruchomienie kalkulatora z terminalu: \n./simpleCalc [nazwa dzialania] [liczba1] [liczba2]\n\n";
    cout<<"Dzialania:\n";
    cout<<"add [liczba1] [liczba2]\n\tDodawanie dwoch liczb ([a] i [b]) calkowitych.\nsubstract [liczba1] [liczba2]\n\tOdejmowanie dwoch liczb ([a] i [b]) calkowitych.\nvolume [liczba1] [liczba2]\n\tObliczanie objetosci graniastoslupa o podstawie trapezu \n\t([a] - pole podstawy i [b] - wysokosc, [a][b] - liczby calkowite);";
    cout<<"\nhelp\n\twyswietlenie pomocnych informacji";
    exit(2);
}
void errMsg()
{
    cout<<"!!!ERROR: bledne dane!!!\n";
    helpMsg();
}

void add(int l1, int l2)
{
    cout<<"Wynik dodawania liczb "<<l1<<" i "<<l2<<" = "<<l1+l2;
}
void substract(int l1, int l2)
{
    cout<<"Wynik odejmowania liczb "<<l1<<" i "<<l2<<" = "<<l1-l2;
}
void volume(int l1, int l2)
{
    cout<<"Objetosc graniastoslupa o podstawie trapezu, ktorego pole podstawy to "<<l1<<" i wysokosci graniastoslupa "<<l2<<" = "<<l1*l2;
}