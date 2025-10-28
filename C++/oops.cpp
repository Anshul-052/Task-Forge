#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    int age;

public:
    void setAge(int newAge) {
        if (newAge <= 0) {
            throw 0; 
        }
        age = newAge;
    }

    int getAge() const {
        return age;
    }
};

int main() {
    Person person;
    int userAge;

    cout << "Enter your age: ";
    cin >> userAge;

    try {
        person.setAge(userAge);
        cout << "You entered a valid age: " << person.getAge() << endl;
    } 
    catch (int e) {
        cout << "Error age cannot be a negative or zero number." << endl;
    }

    return 0;
}
