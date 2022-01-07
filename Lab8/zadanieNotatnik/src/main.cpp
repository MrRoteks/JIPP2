//
// Created by filip on 07.11.2021.
//
//getline(cin,linia)
#include <iostream>
#include <string>
#include "notatnik.cpp"

using namespace std;


int main()
{
    string tytul;
    cout<<"----------NOTATNIK-----------"<<endl;
    cout<<"Podaj tytuł notatnika: ";
    cin>>tytul;
    Note n1;
    n1.setTitle(tytul);
    cout<<"Tytuł notatnika = "<<n1.getTitle();

    return 0;
}
