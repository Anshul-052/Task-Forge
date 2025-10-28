#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
virtual float area() {
return 0;
}
};

class Circle : public Shape {
float radius;
public:
Circle(float r) {
radius = r;
}
float area() {
return 3.14 * radius * radius;
}
};

class Rectangle : public Shape {
float length, width;
public:
Rectangle(float l, float w) {
length = l;
width = w;
}
float area() {
return length * width;
}
};

class Triangle : public Shape {
float base, height;
public:
Triangle(float b, float h) {
base = b;
height = h;
}
float area() {
return 0.5 * base * height;
}
};

int main() {
Shape* s;
Circle c(5);
Rectangle r(4, 6);
Triangle t(3, 8);
s = &c;
cout << "Circle Area: " << s->area() << endl;
s = &r;
cout << "Rectangle Area: " << s->area() << endl;
s = &t;
cout << "Triangle Area: " << s->area() << endl;
return 0;
}
