#include <iostream>
using namespace std;

class Number {
int value;
public:
Number(int v = 0) {
value = v;
}
friend Number operator+(Number a, Number b);
friend Number operator-(Number a, Number b);
void show() {
cout << value << endl;
}
};

Number operator+(Number a, Number b) {
return Number(a.value + b.value);
}

Number operator-(Number a, Number b) {
return Number(a.value - b.value);
}

int main() {
Number n1(10), n2(5);
Number n3 = n1 + n2;
Number n4 = n1 - n2;
n3.show();
n4.show();
return 0;
}
