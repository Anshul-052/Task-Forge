#include <iostream>

using namespace std;

class bankacc{
   private:
    string name;
    int accno;
    int bal; 
   
   public:

   void input();
   void deposit();
   void withdraw();
   void display();
};
void bankacc::input(){
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Account No: ";
    cin>>accno;
    cout<<"Enter Balance: ";
    cin>>bal;
}

void bankacc::deposit(){
    int mon;
    cout<<"Enter amount: ";
    cin>>mon;
    bal = bal + mon;
}

void bankacc::withdraw(){
    int nom;
    cout<<"Enter amount: ";
    cin>>nom;
    if(nom<=bal)
      bal = bal - nom;
    else
      cout<<"Insuffcient balance"<<endl;
}

void bankacc::display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Account No: "<<accno<<endl;
    cout<<"Balance: "<<bal<<endl;
}

int main(){
    bankacc p1;
    p1.input();

    int choice;
    do
    {
    cout<<"Options"<<endl;
    cout<<"1. Deposite"<<endl;
    cout<<"2. Withdraw"<<endl;
    cout<<"3. Display Details"<<endl;
    cout<<"4. Exit"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        p1.deposit();
        break;

    case 2:
        p1.withdraw();
        break;
    
    case 3:
        p1.display();
        break;

    case 4:
        cout<<"Exiting program..";
        break;
    default:
       cout<<"Invalid choice. Please try again";
        break;
    }
      } while (choice!=4);
}