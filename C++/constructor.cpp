#include <iostream>
using namespace std;

class device {
public:
    string devtype;
    string scrtype;
    string ram;
    string storage;
};

class mobile : public device {
public:
    string brand;
    string series;
    int ver;
    string display;
    int cammp;
    mobile(string a, string b, string c, string d, string f, string g, int h, string i, int j);
    void showDetails();
};

mobile::mobile(string a, string b, string c, string d, string f, string g, int h, string i, int j) 
    {
        devtype = a;
        scrtype = b;
        ram = c;
        storage = d;
        brand = f;
        series = g;
        ver = h;
        display = i;
        cammp = j;
    }
void mobile::showDetails() {
        cout << "Device Type: " << devtype << endl;
        cout << "Screen Type: " << scrtype << endl;
        cout << "RAM: " << ram << endl;
        cout << "Storage: " << storage << endl;
        cout << "Brand: " << brand << endl;
        cout << "Series: " << series << endl;
        cout << "Version: " << ver << endl;
        cout << "Display: " << display << endl;
        cout << "Camera MP: " << cammp << endl;
    }

int main() {
    mobile phone("Electronics", "Touchscreen", "8GB", "128GB",
                 "Samsung", "Galaxy", 2024, "AMOLED", 108);

    mobile phone2("Electronics", "Touchscreen", "12GB", "512GB",
                  "Apple", "iPhone", 16, "Super Retina XDR", 48);

    phone.showDetails();
    cout<<"vs"<<endl;
    phone2.showDetails();
    return 0;
}
