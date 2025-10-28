#include<iostream> 
using namespace std;     
 
int prime(int n){ 
        if( n % 2 ==0) 
            cout<<"Prime number"; 
        else  
            cout << "Not a prime number"; 
    } 
 
    int main(){ 
        int num; 
        cout << "Enter a number to check : "<<endl; 
        cin >> num; 
        prime(num); 
         
        return 0; 
    }