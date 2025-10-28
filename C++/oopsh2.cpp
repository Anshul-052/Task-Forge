#include <iostream>
using namespace std;

class device{
    public:
    string devtype ="Handset";
    string scrtype = "Touchscreen";
    string ram = "8GB";
    string storage = "128gb";
    int sp = 50000;
};

class mobile: public device{
    public:
    string brand = "Samsung galaxy ";
    string series = "S";
    int ver = 24;
    string display = "Oled";
    int cammp = 100;
    int hcost = 15000;
    void print();
};

class soft: public mobile{
   public:
   int andver=15 ;
   string os = "galaxyos";
   int scost = 15000;
   void display();
   void profit();
};

void mobile:: print(){
   cout<<"Hardware detail"<<endl;
   cout<<devtype<<" "<<scrtype<<endl;
   cout<<brand <<series <<ver<<endl;
   cout<<"Screentype: "<<display<<endl;
   cout<<"Camera megapixel: "<<cammp<<endl;
   cout<<endl;
}

void soft::display(){
    cout<<"Software details"<<endl;
    cout<<"Android version: "<<andver<<endl;
    cout<<"Operated system: "<<os<<endl;
    cout<<"Ram: "<<ram<<endl;
    cout<<"Storage: "<<storage<<endl;
    cout<<endl;
}

void soft::profit(){
    cout<<"Profit"<<endl;
    int prof = sp - (hcost + scost);
    cout<<"Making cost: "<<hcost+scost<<endl;
    cout<<"Selling price: "<<sp<<endl;
    cout<<"Total Profit: "<<prof<<endl;
}
int main(){
    soft p1;
    p1.print();
    p1.display();
    p1.profit();
    return 0;
}