#include <iostream>
using namespace std;

class Student {
public:
    int age;
    void setAge(int age) {
        this->age = age;
    }
    void showAge() {
        cout << "Age: " << age << endl;
    }
};

int main() {
    Student s;
    int age = 20;
    s.setAge(age);
    s.showAge();
    return 0;
}
