#include <string>
#include <iostream>
using namespace std;

class PrzykladowaKlasa
{
public:
    double liczba;       //prawo dostępu: publiczne
    char tablica[20];    //prawo dostępu: publiczne
// + np. void funckja()
private:
    int abc;            //prawo dostępu: prytatne
    char znak;          //prawo dostępu: prytatne
    std::string napis;  //prawo dostępu: prytatne
};

class JakasKlasa
{
    int a;
    char b;
    std::string c;
public:
    JakasKlasa();
};

JakasKlasa::JakasKlasa()
//: a( 123 )
//     , b( 'x' )
//     , c( "napis" )
//tak mozna odrazu zadeklarowac wartosci zmiennych
// np. tez
//JakasKlasa::JakasKlasa( int fA )
//    : a( fA )
//{
//}
{
    cout << "Klasa utworzona, wartosci zmiennych: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
    a = 123;
    b = 'x';
    c = "napis";
    cout << "Wartosci zmiennych po zainicjowaniu w konstruktorze: " << endl;
    cout << "a = " << a << endl;
    cout << "b = '" << b << "'" << endl;
    cout << "c = \"" << c << "\"" << endl;
}

int main()
{
    PrzykladowaKlasa nazwaZmiennej;
    JakasKlasa tZmienna;

    return(0);
}