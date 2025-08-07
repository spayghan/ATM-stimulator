#include <iostream>
#include <string>
using namespace std;

// Account class
class Account {
private:
    int accountNumber;
    string accountHolderName;
    int pin;
    double balance;

public:
    Account(int accNum, string name, int accPin, double bal) {
        accountNumber = accNum;
        accountHolderName = name;
        pin = accPin;
        balance = bal;
    }

    bool verifyPin(int enteredPin) {
        return pin == enteredPin;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

// ATM class
class ATM {
private:
    Account *account;

public:
    ATM(Account *acc) {
        account = acc;
    }

    void showMenu() {
        int choice;
        do {
            cout << "\nWelcome, " << account->getAccountHolderName() << "!" << endl;
            cout << "===== ATM Menu =====" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit" << endl;
            cout << "3. Withdraw" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Current Balance: " << account->getBalance() << endl;
                    break;
                case 2: {
                    double depositAmount;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmount;
                    account->deposit(depositAmount);
                    break;
                }
                case 3: {
                    double withdrawAmount;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmount;
                    account->withdraw(withdrawAmount);
                    break;
                }
                case 4:
                    cout << "Thank you for using the ATM!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again!" << endl;
            }
        } while (choice != 4);
    }
};

// Main function
int main() {
    int enteredPin;
    Account userAccount(123456, "Shashvat Payghan", 4321, 10000.0); 

    cout << "===== Welcome to the ATM Simulator =====" << endl;
    cout << "Enter PIN: ";
    cin >> enteredPin;

    if (userAccount.verifyPin(enteredPin)) {
        ATM atm(&userAccount);
        atm.showMenu();
    } else {
        cout << "Incorrect PIN. Access Denied." << endl;
    }

    return 0;
}

