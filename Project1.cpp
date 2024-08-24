#include <iostream>
#include <iomanip>

using namespace std;

class ATM {
private:
    double balance;

public:
    ATM(double initial_balance) : balance(initial_balance) {}

    void checkBalance() {
        cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "You have successfully deposited $" << fixed << setprecision(2) << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "You have successfully withdrawn $" << fixed << setprecision(2) << amount << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }
};

int main() {
    double initial_balance;
    cout << "Enter your initial balance: $";
    cin >> initial_balance;

    ATM myATM(initial_balance);
    int choice;
    double amount;

    do {
        cout << "\nATM Menu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myATM.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myATM.deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
