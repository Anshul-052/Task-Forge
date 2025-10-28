#include<iostream>
using namespace std;

class mobile{
    public:
    string brand = "Samsung galaxy ";
    string series = "S";
    int ver = 24;
    string scrtyp = "Oled";
    int cammp = 100;
    void print();
};

class soft: public mobile{
   public:
   int andver=15 ;
   string os = "galaxy";
   void display();
};

void mobile:: print(){
   cout<<"Hardware detail"<<endl;
   cout<<brand <<series <<ver<<endl;
   cout<<"Screentype: "<<scrtyp<<endl;
   cout<<"Camera megapixel: "<<cammp<<endl;
   cout<<endl;
}

void soft::display(){
    cout<<"Software details"<<endl;
    cout<<"Android version: "<<andver<<endl;
    cout<<"Operated system: "<<os<<endl;
}

int main(){
    soft p1;
    p1.print();
    p1.display();

    return 0;
}