//
// Created by Roteks on 22.11.2021.
//

#include <iostream>

using namespace std;

class Figura{
protected:
    string nazwa;
    string kolor;

public:
    Figura();
    Figura(string nazwa,string kolor){
        this->nazwa=nazwa;
        this->kolor=kolor;
    }

    void printNazwa()
    {
        cout<<"Figura: "<<nazwa<<endl;
    }
    virtual double getArea() = 0;
};

class Kwadrat:public Figura{
protected:
    int bok;

public:
    Kwadrat(string nazwa,string kolor, int bok):Figura(nazwa,kolor)
    {
        this->nazwa=nazwa;
        this->kolor=kolor;
        this->bok=bok;
    }
    Kwadrat();

    void printPole()
    {
        cout<<"Pole kwadratu= "<<bok*bok<<endl;
    }
    void printObwod()
    {
        cout<<"Obwod kwadratu= "<<bok*4<<endl;
    }

};

class Circle:public figura{
protected:
    int r;
public:
    Circle(int r):figura(nazwa,kolor){
        this->nazwa=nazwa;
        this->kolor=kolor;
        this->r=r;
    }
    int getArea()
    {
        return r;
    }

};

class Rectangle:Figura{
protected:
    int a,b;
public:
    Rectangle(int a,int b):figura(nazwa,kolor)
    {
        this->a=a;
        this->b=b;
        this->nazwa=nazwa;
        this->kolor=kolor;
    }

};
int main(){

    Figura f1("wielokat","bialy");
    Kwadrat k1("Kwadrat","kolorowy",5);
    f1.printNazwa();
    k1.printNazwa();
    k1.printPole();
    k1.printObwod();

    Figure *circle = new Circle(5);
    Figure *rectangle = new Rectangle(5, 18);

    cout << "Circle area: " << circle->getArea() << endl;
    cout << "Rectangle area: " << rectangle->getArea() << endl;

  return 0;
}