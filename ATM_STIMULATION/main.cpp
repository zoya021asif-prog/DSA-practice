// Simple console ATM simulation in C++
// Compile: g++ -std=c++17 atm_simulation.cpp -o atm
// Run:     ./atm

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <limits>
#include <ctime>
#include <sstream>

using namespace std;

class Account {
private:
    string accountNo;
    string name;
    string pin;
    double balance;
    vector<string> transactions;

    static string timestamp() {
        time_t now = time(nullptr);
        char buf[32];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        return string(buf);
    }

    void log(const string& type, double amount) {
        ostringstream oss;
        oss << timestamp() << " | " << left << setw(9) << type << " | "
            << right << setw(10) << fixed << setprecision(2) << amount
            << " | Bal: " << balance;
        transactions.push_back(oss.str());
    }

public:
    Account() : balance(0.0) {}
    Account(string no, string n, string p, double bal)
        : accountNo(no), name(n), pin(p), balance(bal) {}

    const string& getName() const { return name; }
    double getBalance() const { return balance; }
    bool checkPin(const string& p) const { return p == pin; }

    bool deposit(double amount, string& msg) {
        if (amount <= 0) { msg = "Amount must be positive."; return false; }
        balance += amount;
        log("Deposit", amount);
        msg = "Deposit successful.";
        return true;
    }

    bool withdraw(double amount, string& msg) {
        if (amount <= 0) { msg = "Amount must be positive."; return false; }
        if (amount > balance) { msg = "Insufficient funds."; return false; }
        balance -= amount;
        log("Withdraw", amount);
        msg = "Please collect your cash.";
        return true;
    }

    bool changePin(const string& oldPin, const string& newPin, string& msg) {
        if (oldPin != pin) { msg = "Old PIN is incorrect."; return false; }
        if (newPin.size() != 4 ||
            newPin.find_first_not_of("0123456789") != string::npos) {
            msg = "New PIN must be exactly 4 digits.";
            return false;
        }
        pin = newPin;
        msg = "PIN changed successfully.";
        return true;
    }

    void miniStatement() const {
        if (transactions.empty()) {
            cout << "No transactions yet.\n";
            return;
        }
        cout << "\n--- Last 5 transactions ---\n";
        size_t start = transactions.size() > 5 ? transactions.size() - 5 : 0;
        for (size_t i = start; i < transactions.size(); ++i)
            cout << transactions[i] << "\n";
    }
};

class ATM {
private:
    map<string, Account> accounts;
    static const int MAX_ATTEMPTS = 3;

    static double readAmount(const string& prompt) {
        double value;
        cout << prompt;
        if (!(cin >> value)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid number.\n";
            return -1;
        }
        return value;
    }

    Account* login() {
        string accNo, pin;
        cout << "Enter account number: ";
        cin >> accNo;

        auto it = accounts.find(accNo);
        for (int attempt = 1; attempt <= MAX_ATTEMPTS; ++attempt) {
            cout << "Enter 4-digit PIN: ";
            cin >> pin;
            if (it != accounts.end() && it->second.checkPin(pin)) {
                cout << "\nWelcome, " << it->second.getName() << "!\n";
                return &it->second;
            }
            cout << "Invalid credentials. " << (MAX_ATTEMPTS - attempt)
                 << " attempt(s) left.\n";
        }
        cout << "Card blocked. Please contact your bank.\n";
        return nullptr;
    }

    void session(Account& acc) {
        int choice = 0;
        string msg;

        do {
            cout << "\n===== ATM MENU =====\n"
                 << "1. Check Balance\n"
                 << "2. Deposit\n"
                 << "3. Withdraw\n"
                 << "4. Mini Statement\n"
                 << "5. Change PIN\n"
                 << "6. Exit\n"
                 << "Select an option: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                choice = 0;
            }

            switch (choice) {
                case 1:
                    cout << fixed << setprecision(2)
                         << "Current balance: " << acc.getBalance() << "\n";
                    break;
                case 2: {
                    double amt = readAmount("Amount to deposit: ");
                    if (amt != -1) { acc.deposit(amt, msg); cout << msg << "\n"; }
                    break;
                }
                case 3: {
                    double amt = readAmount("Amount to withdraw: ");
                    if (amt != -1) { acc.withdraw(amt, msg); cout << msg << "\n"; }
                    break;
                }
                case 4:
                    acc.miniStatement();
                    break;
                case 5: {
                    string oldPin, newPin;
                    cout << "Current PIN: ";
                    cin >> oldPin;
                    cout << "New PIN: ";
                    cin >> newPin;
                    acc.changePin(oldPin, newPin, msg);
                    cout << msg << "\n";
                    break;
                }
                case 6:
                    cout << "Thank you for using our ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid option. Try again.\n";
            }
        } while (choice != 6);
    }

public:
    void addAccount(const string& no, const Account& acc) { accounts[no] = acc; }

    void run() {
        cout << "=== Welcome to the C++ ATM ===\n";
        Account* acc = login();
        if (acc) session(*acc);
    }
};

int main() {
    ATM atm;
    atm.addAccount("1001", Account("1001", "Alice", "1234", 5000));
    atm.addAccount("1002", Account("1002", "Bob", "4321", 2500));
    atm.run();
    return 0;
}