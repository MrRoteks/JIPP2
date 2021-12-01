#include <iostream>
#include <math.h>
using namespace std;

class Vector{
private:
    double x, y;

public:
    Vector() {};

    Vector(double x, double y) : x(x), y(y) {}

    double length() {
        return sqrt(x * x + y * y);
    }

    Vector operator+(const Vector &rhs) const {
        return {x + rhs.x, y + rhs.y};
    }

    Vector &operator+=(const Vector &rhs) {
        this->x = this->x + rhs.x;
        this->y = this->y + rhs.y;
        return *this;
    }

    friend void print(const Vector &v);


    Vector operator-(const Vector &rhs){
        return {x -rhs.x,y -rhs.y};
    }

    Vector operator*(const Vector &rhs)
    {
        return {x*rhs.x,y*rhs.y};
    }
    Vector operator*(const double rhs)
    {
        return {x*rhs,y*rhs};
    }
};
void print(const Vector &v){
    cout<<"("<<v.x<<","<<v.y<<")\n";
}

class Imaginary
{
private:
    double r,i;
public:
    Imaginary(){};
    Imaginary(double r, double i){};

    Imaginary operator+(const Imaginary &rhs)
    {
        return {r+rhs.r,i+rhs.i};
    }
    Imaginary &operator+=(const Imaginary &rhs) {
        this->r = this->r + rhs.r;
        this->i = this->i + rhs.i;
        return *this;
    }
    friend void print(const Imaginary &num);

};


void print(const Imaginary &num){
    cout<<"("<<num.r<<","<<num.i<<")\n";}

int main()
{
    Vector v1(2,1), v2(5,10);
    Vector v3 = v1 + v2;
    Vector v4,v5,v6;
    v3 = v1.operator+(v2);
    v4= v1-v2;
    v5=v1*v2;
    v6=v1*10;
    //v6=10*v2;  ///tu sproboj naprawic
    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
cout<<"--------------------------------------\n";
    Imaginary i1(2,3),i2(1,1),i3;

    i3= i1.operator+(i2);
    print(i3);
    return 0;
}