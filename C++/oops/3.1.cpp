#include <iostream>
using namespace std;

class Rectangle {
int length;
int width;
public:
void setData(int l, int w) {
length = l;
width = w;
}
int area() {
return length * width;
}
int perimeter() {
return 2 * (length + width);
}
};

int main() {
Rectangle r;
r.setData(5, 3);
cout << "Area: " << r.area() << endl;
cout << "Perimeter: " << r.perimeter() << endl;
return 0;
}
