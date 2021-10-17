#include <iostream>
#include <string>
#include "../include/calc.h"

using namespace std;

int main (int argc, char *argv[])  {
    string polecenie=argv[1];
    if(polecenie=="help") {
    helpMsg();
    }
    if(polecenie!="add" && polecenie!="substract" && polecenie!="volume")
    {
        errMsg();
    }
    int l1 = stoi(argv[2]);
    int l2 = stoi(argv[3]);

    if(polecenie=="add")
        add(l1,l2);
    if(polecenie=="substract")
        substract(l1,l2);
    if(polecenie=="volume")
        cout<<"Objetosc graniastoslupa o podstawie trapezu, ktorego pole podstawy to "<<l1<<" i wysokosci graniastoslupa "<<l2<<" = "<<l1*l2;

    return 0;
}
