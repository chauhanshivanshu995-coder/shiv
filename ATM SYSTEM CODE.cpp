#include <iostream>
#include <string>
using namespace std;

// Base class: Transaction
class Transaction {
protected:
    double amount;
public:
    Transaction(double amt) : amount(amt) {}
    virtual void execute() = 0; // Pure virtual function
    virtual ~Transaction() {}
};

// Account class
class Account {
private:
    string accountNumber;
    double balance;
public:
    Account(string accNo, double bal) : accountNumber(accNo), balance(bal) {}

    void credit(double amt) {
        balance += amt;
        cout << "Amount deposited successfully.\n";
    }

    void debit(double amt) {
        if (amt <= balance) {
            balance -= amt;
            cout << "Please collect your cash.\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    string getAccountNumber() const {
        return accountNumber;
    }
};

// Derived classes for specific transactions
class Withdrawal : public Transaction {
private:
    Account &account;
public:
    Withdrawal(Account &acc, double amt) : Transaction(amt), account(acc) {}
    void execute() override {
        cout << "\n--- Withdrawal Transaction ---\n";
        account.debit(amount);
    }
};

class Deposit : public Transaction {
private:
    Account &account;
public:
    Deposit(Account &acc, double amt) : Transaction(amt), account(acc) {}
    void execute() override {
        cout << "\n--- Deposit Transaction ---\n";
        account.credit(amount);
    }
};

class BalanceInquiry : public Transaction {
private:
    Account &account;
public:
    BalanceInquiry(Account &acc) : Transaction(0), account(acc) {}
    void execute() override {
        cout << "\n--- Balance Inquiry ---\n";
        cout << "Available Balance: " << account.getBalance() << endl;
    }
};

// ATM class
class ATM {
private:
    Account *account;
public:
    ATM(Account *acc) : account(acc) {}

    void showMenu() {
        int choice;
        double amt;
        while (true) {
            cout << "\n===== ATM MENU =====\n";
            cout << "1. Balance Inquiry\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Try again.\n";
                continue;
            }

            Transaction *t = NULL;

            switch (choice) {
                case 1:
                    t = new BalanceInquiry(*account);
                    break;
                case 2:
                    cout << "Enter amount to deposit: ";
                    cin >> amt;
                    t = new Deposit(*account, amt);
                    break;
                case 3:
                    cout << "Enter amount to withdraw: ";
                    cin >> amt;
                    t = new Withdrawal(*account, amt);
                    break;
                case 4:
                    cout << "Thank you for using our ATM!\n";
                    return;
                default:
                    cout << "Invalid choice.\n";
                    continue;
            }

            if (t != NULL) {
                t->execute();
                delete t;
            }
        }
    }
};

// Main Function
int main() {
    Account acc("AC12345", 5000.0);
    ATM atm(&acc);
    atm.showMenu();
    return 0;
}

