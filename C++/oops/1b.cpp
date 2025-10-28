#include<iostream> 
using namespace std; 
int main() { 
int Ctemp, Ftemp; 
cout<< "Enter temperature in celcius: "<<endl; 
cin >> Ctemp; 
Ftemp = (Ctemp * 9/5) + 32; 
cout<< "Temperature in fahrenheit is: " << Ftemp; 
}