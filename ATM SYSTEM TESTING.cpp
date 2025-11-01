#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// ===== ATM SYSTEM CORE CLASS =====
class ATM {
private:
    string userPIN;
    double balance;

public:
    ATM(string pin, double initialBalance) {
        userPIN = pin;
        balance = initialBalance;
    }

    bool login(string enteredPIN) {
        return enteredPIN == userPIN;
    }

    double checkBalance() {
        return balance;
    }

    bool deposit(double amount) {
        if (amount <= 0) return false;
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) return false;
        balance -= amount;
        return true;
    }
};

// ===== TESTING FUNCTIONS =====

// Unit Tests
void testLogin() {
    ATM atm("1234", 5000);
    assert(atm.login("1234") == true);
    assert(atm.login("9999") == false);
    cout << "[Unit Test] Login Test Passed ?\n";
}

void testDeposit() {
    ATM atm("1234", 5000);
    assert(atm.deposit(1000) == true);
    assert(atm.checkBalance() == 6000);
    assert(atm.deposit(-500) == false);
    cout << "[Unit Test] Deposit Test Passed ?\n";
}

void testWithdraw() {
    ATM atm("1234", 5000);
    assert(atm.withdraw(2000) == true);
    assert(atm.checkBalance() == 3000);
    assert(atm.withdraw(10000) == false);
    assert(atm.withdraw(-200) == false);
    cout << "[Unit Test] Withdraw Test Passed ?\n";
}

// Integration Test (Deposit + Withdraw)
void testIntegration() {
    ATM atm("1234", 10000);
    atm.deposit(5000);
    atm.withdraw(3000);
    assert(atm.checkBalance() == 12000);
    cout << "[Integration Test] Deposit + Withdraw Passed ?\n";
}

// System Test (End-to-End Scenario)
void testSystem() {
    ATM atm("9999", 8000);
    cout << "\n=== SYSTEM TEST: ATM Scenario ===\n";
    cout << "User tries login with wrong PIN: " << (atm.login("1234") ? "Passed ?" : "Failed ?") << endl;
    cout << "User tries login with correct PIN: " << (atm.login("9999") ? "Passed ?" : "Failed ?") << endl;

    if (atm.login("9999")) {
        cout << "Initial Balance: " << atm.checkBalance() << endl;
        atm.deposit(2000);
        cout << "After Deposit: " << atm.checkBalance() << endl;
        atm.withdraw(3000);
        cout << "After Withdraw: " << atm.checkBalance() << endl;
    }
    cout << "[System Test] Complete ?\n";
}

int main() {
    cout << "===== ATM SYSTEM TESTING MODULE =====\n";

    // Run Unit Tests
    testLogin();
    testDeposit();
    testWithdraw();

    // Run Integration Test
    testIntegration();

    // Run System Test
    testSystem();

    cout << "\nAll Tests Executed Successfully ?\n";
    return 0;
}

