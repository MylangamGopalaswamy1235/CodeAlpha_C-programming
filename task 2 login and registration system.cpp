#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string> userDB;

void registerUser() {
    string username, password;
    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    if (userDB.find(username) != userDB.end()) {
        cout << "❌ Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    userDB[username] = password;
    cout << "✅ Registration successful!\n";
}

void loginUser() {
    string username, password;
    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (userDB.find(username) != userDB.end() && userDB[username] == password) {
        cout << "✅ Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "❌ Invalid username or password.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n📋 Menu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "👋 Goodbye!\n"; return 0;
            default: cout << "⚠ Invalid choice. Try again.\n";
        }
    }
}
