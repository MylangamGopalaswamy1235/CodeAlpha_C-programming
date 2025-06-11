#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string timeStr;

    Transaction(string t, double amt) {
        type = t;
        amount = amt;

        // Safe method for getting formatted time in C++
        time_t now = time(0);
        char* dt = ctime(&now);
        if (dt) {
            timeStr = string(dt);
            if (!timeStr.empty() && timeStr.back() == '\n') {
                timeStr.pop_back(); // remove newline
            }
        } else {
            timeStr = "Time error";
        }
    }

    void display() const {
        cout << type << " of $" << fixed << setprecision(2) << amount << " at " << timeStr << endl;
    }
};

class Account {
public:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

    Account(string accNo) {
        accountNumber = accNo;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposited $" << amount << " to Account " << accountNumber << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance in Account " << accountNumber << endl;
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Withdrew $" << amount << " from Account " << accountNumber << endl;
        return true;
    }

    void transfer(Account& to, double amount) {
        if (withdraw(amount)) {
            to.deposit(amount);
            transactions.push_back(Transaction("Transfer to " + to.accountNumber, amount));
            to.transactions.push_back(Transaction("Transfer from " + accountNumber, amount));
        }
    }

    void showBalance() const {
        cout << "Balance for Account " << accountNumber << ": ₹" << fixed << setprecision(2) << balance << endl;
    }

    void showTransactions() const {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        for (const auto& t : transactions) {
            t.display();
        }
    }
};

class Customer {
public:
    string name;
    Account account;

    Customer(string n, string accNo) : name(n), account(accNo) {}

    void showInfo() const {
        cout << "Customer: " << name << ", Account No: " << account.accountNumber << endl;
    }
};

int main() {
    Customer c1("Alice", "A101");
    Customer c2("Bob", "B202");

    c1.account.deposit(1000);
    c1.account.withdraw(300);
    c1.account.transfer(c2.account, 200);

    cout << "\n--- Account Summary ---\n";
    c1.account.showBalance();
    c2.account.showBalance();

    cout << "\n--- Transactions ---\n";
    c1.account.showTransactions();
    cout << "\n";
    c2.account.showTransactions();

    return 0;
}