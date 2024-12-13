#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Account Class
class Account {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    Account(string accNum, string owner, double initialBalance)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {}

    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("입금 금액은 0보다 커야 합니다.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw runtime_error("잔액이 부족합니다.");
        }
        balance -= amount;
    }

    void display() const {
        cout << "계좌번호: " << accountNumber
             << ", 소유자: " << ownerName
             << ", 잔액: " << fixed << setprecision(2) << balance << endl;
    }

    string toCSV() const {
        return accountNumber + "," + ownerName + "," + to_string(balance);
    }

    static Account fromCSV(const string& csvLine) {
        size_t pos1 = csvLine.find(',');
        size_t pos2 = csvLine.find(',', pos1 + 1);

        string accNum = csvLine.substr(0, pos1);
        string owner = csvLine.substr(pos1 + 1, pos2 - pos1 - 1);
        double bal = stod(csvLine.substr(pos2 + 1));

        return Account(accNum, owner, bal);
    }
};

// Bank Class
class Bank {
private:
    vector<Account> accounts;
    string dataFile = "accounts.txt";

public:
    void createAccount() {
        string accNum, owner;
        double initialBalance;
        cout << "계좌번호: ";
        cin >> accNum;
        cout << "소유자 이름: ";
        cin >> owner;
        cout << "초기 잔액: ";
        cin >> initialBalance;

        accounts.push_back(Account(accNum, owner, initialBalance));
        cout << "계좌가 생성되었습니다.\n";
    }

    Account* findAccount(const string& accNum) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    void displayAccounts() {
        for (const auto& account : accounts) {
            account.display();
        }
    }

    void saveToFile() {
        ofstream file(dataFile);
        for (const auto& account : accounts) {
            file << account.toCSV() << endl;
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file(dataFile);
        string line;
        while (getline(file, line)) {
            accounts.push_back(Account::fromCSV(line));
        }
        file.close();
    }
};

// Main Function
int main() {
    Bank bank;
    bank.loadFromFile();

    int choice;
    while (true) {
        cout << "\n1. 계좌 생성\n"
             << "2. 잔액 확인\n"
             << "3. 입금\n"
             << "4. 출금\n"
             << "5. 모든 계좌 보기\n"
             << "6. 종료\n"
             << "선택: ";
        cin >> choice;

        try {
            if (choice == 1) {
                bank.createAccount();
            } else if (choice == 2) {
                string accNum;
                cout << "계좌번호: ";
                cin >> accNum;
                Account* account = bank.findAccount(accNum);
                if (account) {
                    cout << "잔액: " << account->getBalance() << endl;
                } else {
                    cout << "계좌를 찾을 수 없습니다.\n";
                }
            } else if (choice == 3) {
                string accNum;
                double amount;
                cout << "계좌번호: ";
                cin >> accNum;
                cout << "입금 금액: ";
                cin >> amount;
                Account* account = bank.findAccount(accNum);
                if (account) {
                    account->deposit(amount);
                    cout << "입금 완료.\n";
                } else {
                    cout << "계좌를 찾을 수 없습니다.\n";
                }
            } else if (choice == 4) {
                string accNum;
                double amount;
                cout << "계좌번호: ";
                cin >> accNum;
                cout << "출금 금액: ";
                cin >> amount;
                Account* account = bank.findAccount(accNum);
                if (account) {
                    account->withdraw(amount);
                    cout << "출금 완료.\n";
                } else {
                    cout << "계좌를 찾을 수 없습니다.\n";
                }
            } else if (choice == 5) {
                bank.displayAccounts();
            } else if (choice == 6) {
                bank.saveToFile();
                break;
            } else {
                cout << "잘못된 선택입니다.\n";
            }
        } catch (const exception& e) {
            cout << "오류: " << e.what() << endl;
        }
    }

    return 0;
}
