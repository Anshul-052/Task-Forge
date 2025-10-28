#include <iostream>

using namespace std;

class student {
    private:
      string name;
      int roll;
      int marks;

    public:
    void acceptdetails(){
      cout<<"Enter name: ";
      cin>>name;
      cout<<"Enter Roll No.: ";
      cin>>roll;
      cout<<"Enter Marks: ";
      cin>>marks;
    }

    void pastedetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<roll<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
};

int main(){
    student stu1;
    stu1.acceptdetails();
    cout<<endl;
    stu1.pastedetails();

    return 0;
}


