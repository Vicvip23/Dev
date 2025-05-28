#include <cstdlib>
#include <cmath>
#include <cstdio>

#define PI 3.14

class Shape{

public:
    virtual double area(){
        return 0;
    };
};

class Solid{

public:
    virtual double volume(){
        return 0;
    };
};

class Square: public Shape{

private:
    int side;

public:
    Square(int a = 0){
        this->side = a;
    };

    void setSide(int input){
        this->side = input;
    };

    double area() override{
        return this->side * this->side;
    };
};

class Circle: public Shape{

private:
    int radius;

public:
    Circle(int r = 0){
        this->radius = r;
    };

    void setRadius(int input){
        this->radius = input;
    };

    double area() override{
        return pow(this->radius, PI);
    };
};

class Rectangle: public Shape{

private:
    int sideA;
    int sideB;

public:
    Rectangle(int a = 0, int b = 0){
        this->sideA = a;
        this->sideB = b;
    };

    void setSideA(int input){
        this->sideA = input;
    };

    void setSideB(int input){
        this->sideB = input;
    };

    double area() override{
        return this->sideA * this->sideB;
    };
};

class Cone: public Solid{

private:
    int baseRadius;
    int height;
    float baseArea;

public:
    Cone(int r = 0, int h = 0){
        this->baseRadius = r;
        this->height = h;
        this->baseArea = pow(this->baseRadius, 2) * PI;
    };

    double volume() override{
        return this->baseArea * this->height;
    };
};


int main(){

    Shape* shape;
    Square square = Square(4);
    Rectangle rectangle = Rectangle(4, 9);
    Circle circle = Circle(5);

    Solid* solid;
    Cone cone = Cone(12, 11);

    shape = &square;
    printf("%f\n", shape->area());
    shape = &rectangle;
    printf("%f\n", shape->area());
    shape = &circle;
    printf("%f\n\n", shape->area());

    solid = &cone;
    printf("%f\n", solid->volume());

    return 0;
}