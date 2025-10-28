#include <iostream>
using namespace std;

int main() {
int a, b;
cout << "Enter two numbers: ";
cin >> a >> b;
try {
if (cin.fail())
throw "Invalid input";
if (b == 0)
throw 0;
cout << "Result: " << a / b << endl;
}
catch (const char* msg) {
cout << msg << endl;
}
catch (int x) {
cout << "Cannot divide by zero" << endl;
}
return 0;
}
