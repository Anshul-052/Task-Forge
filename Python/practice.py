class bank:
    
    def __init__(self, balance, accno):
        self.balance = balance
        self.accno= accno
    
    def details(self):
        self.accno = input("Enter accno: ")
        self.balance = int(input("Enter balance: "))
        
    def dprint(self):
        print(self.accno)
        print(self.balance)

    def debit(self):
        mon=int(input("Enter money to withdraw: "))
        if self.balance > mon:
            self.balance = self.balance - mon
        else:
            print("Insufficicent balance")
            
    def credit(self):
        nom=int(input("Enter amount to deposite: "))
        self.balance = self.balance + nom

acc1 = bank(0,0)


while True:
    print("\n--- Bank Menu ---")
    print("1. Set Account Details")
    print("2. Display Account Details")
    print("3. Withdraw Money (Debit)")
    print("4. Deposit Money (Credit)")
    print("5. Exit")
    print("-----------------")
    try:
        choice = int(input("Enter choice: "))
    except ValueError:
        print("Invalid input. Please enter a number between 1 and 5.")
        continue 
    
    match choice:
        case 1:
            acc1.details()
        case 2:
            acc1.dprint() 
        case 3:
            acc1.debit()
        case 4:
            acc1.credit()
        case 5:
            print("Thank you for banking with us! Exiting program.")
            break 
        case _: 
            print("Invalid choice. Please select a valid option (1-5).")
