#include <iostream>
using namespace std;

class device
{
public:
    string devtype = "Handset";
    string scrtype = "Touchscreen";
    string ram = "12GB";
    string storage = "256GB";
    int sp = 50000;
};

class mobile : public device
{
public:
    string brand = "Samsung galaxy ";
    string series = "S";
    int ver = 24;
    string display = "Oled";
    int cammp = 100;
    int hcost = 15000;
};

class mobile2 : public device
{
public:
    string brand2 = "Apple Iphone";
    string series2 = "16 Pro Max";
    string display2 = "Oled";
    int mp = 12;
    int dcost = 12000;
    
};

class soft : public mobile
{
public:
    int andver = 15;
    string os = "galaxyos";
    int scost = 15000;
    void print();
};

class soft2 : public mobile2
{
    string chip = "A18";
    string os2 = "galaxyos";
    int tcost = 15000;
    void print2();
};

void soft::print()
{
    cout << "Hardware detail" << endl;
    cout << devtype << " " << scrtype << endl;
    cout << brand << series << ver << endl;
    cout << "Screentype: " << display << endl;
    cout << "Camera megapixel: " << cammp << endl;
    cout << endl;
    cout << "Software details" << endl;
    cout << "Android version: " << andver << endl;
    cout << "Operated system: " << os << endl;
    cout << "Ram: " << ram << endl;
    cout << "Storage: " << storage << endl;
    cout << endl;
    cout << "Profit" << endl;
    int prof = sp - (hcost + scost);
    cout << "Making cost: " << hcost + scost << endl;
    cout << "Selling price: " << sp << endl;
    cout << "Total Profit: " << prof << endl;
}

void soft2::print2()
{
    cout << "Hardware detail" << endl;
    cout << devtype << " " << scrtype << endl;
    cout << brand2 << series2 <<endl;
    cout << "Screentype: " << display2 << endl;
    cout << "Camera megapixel: " << mp << endl;
    cout << endl;
    cout << "Software details" << endl;
    cout << "Chip version: " << chip<< endl;
    cout << "Operated system: " << os2 << endl;
    cout << "Ram: " << ram << endl;
    cout << "Storage: " << storage << endl;
    cout << endl;
    cout << "Profit" << endl;
    int prof = sp - (dcost + tcost);
    cout << "Making cost: " << dcost + tcost << endl;
    cout << "Selling price: " << sp << endl;
    cout << "Total Profit: " << prof << endl;
}
int main()
{
    soft p1;
    soft2 p2;

    cout<<"Enter which device: "<<endl;
    cout<<"1.Samsung Galaxy"<<endl;
    cout<<"2.Iphone"<<endl;

    p1.print();
    p2.print2();
    return 0;
}