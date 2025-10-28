#include <iostream>
using namespace std;

class Student {
int id;
static int count;
public:
void setId(int i) {
id = i;
count++;
}
void show() {
cout << "ID: " << id << endl;
}
static void showCount() {
cout << "Total Students: " << count << endl;
}
};

int Student::count = 0;

int main() {
Student s1, s2, s3;
s1.setId(101);
s2.setId(102);
s3.setId(103);
s1.show();
s2.show();
s3.show();
Student::showCount();
return 0;
}
