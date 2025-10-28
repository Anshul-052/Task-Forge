#include <iostream>
#include <string>
using namespace std;

#define SIZE 5
int ticket_number = 1;  

string names[SIZE];
int tickets[SIZE];
int front = -1, rear = -1;

void enqueue(string name) {
    if (rear == SIZE - 1) {
        cout << "Queue is full! Cannot issue more tickets.\n";
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    rear++;
    names[rear] = name;
    tickets[rear] = ticket_number;
    cout << name << ", your ticket number is: " << ticket_number << endl;
    ticket_number++;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "No customers in queue.\n";
        return;
    }
    cout << "Now serving " << names[front] << " with ticket number: " << tickets[front] << endl;
    front++;

    
    if (front > rear) {
        front = rear = -1;
    }
}

int main() {
    int choice;
    string cname;

    while (true) {
        cout << "\n1. Get Ticket\n2. Serve Customer\n3. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter your name: ";
            cin >> cname;  
            enqueue(cname);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
