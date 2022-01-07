#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/statisticMathChekerLib.h"

using namespace std;

int main() {
    int dzialanie;
    cout<<"---------Kalkulator: Statystyka-----------\n";
   cout<<"Podaj dzialanie do wykonania (wpisz \"-1\", aby uzyskac liste dostepnych dzialan)"<<endl;
   cin>>dzialanie;


while(dzialanie!=0) {
    switch (dzialanie) {
        case -1:
            help();
            break;
        case 1:
            wariancja();
            break;
        default:
            cout << "Nieznane dzialanie.\n";
            break;
    }
    cout<<"Podaj dzialanie do wykonania (wpisz \"-1\", aby uzyskac liste dostepnych dzialan)"<<endl;
    cin>>dzialanie;
}


    return 0;
}

