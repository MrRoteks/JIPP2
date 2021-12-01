//
// Created by filip on 07.11.2021.
//

#include "Point.h"

Point::Point(double x, double y, string name) : name(name) {
    *this->x = x;
    *this->y = y;
}

Point::Point(string name) : name(name) {
    *x = *y = 0;
}

Point::Point(Point &point)
{
  name=point.name;

  x=new double;
  y=new double;

  *x=*point.x;
  *y=*point.y;
}

double Point::getX() {
    return *x;
}

void Point::setX(double x) {
    *this->x = x;
}

double Point::getY() {
    return *y;
}

void Point::setY(double y) {
    *this->y = y;
}

void Point::printData() const {
    cout << "Point " << name << " (x = " << *x << ", y = " << *y << ")\n";
}

void Point::setName(string name) {
    this->name = name;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y &&
           name == rhs.name;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}

const string &Point::getName() const {
    return name;

}
Point::~Point()
{
    cout<<"Usuwanie P(x,y)"<<endl;
    delete x;
    delete y;
}

Pojazd::Pojazd(string numerRejestracyjny, string nazwa, int iloscMiejsc, string pasarzer, string marka, string typ) {
    this->numerRejestracyjny=numerRejestracyjny;
    this->nazwa=nazwa;
    this->iloscMiejsc=iloscMiejsc;
    *this->pasarzer=pasarzer;
    this->marka=marka;
    this->typ=typ;
}

void Pojazd:: wyswietlPojazd()
{
    cout<<"Numer Rejestracyjny: "<<this->numerRejestracyjny<<"\nNazwa: "<<this->nazwa<<"\nIlosc miejsc: "<<this->iloscMiejsc<<"\nPasarzer: "<<this->pasarzer[0]<<this->pasarzer[1]<<this->pasarzer[2]<<this->pasarzer[3]<<this->pasarzer[4]<<"\nMarka: "<<this->marka<<"\nTyp: "<<this->typ<<endl;
}