#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class BankAccount
{
private:
    char *accountHolder;
    char *accountNumber;
    double balance;

public:
    BankAccount()
    {
        accountHolder = nullptr;
        accountNumber = nullptr;
        balance = 0;
    }
    BankAccount(const char *accountHolder, const char *accountNumber, double balance = 0)
    {
        this->accountHolder = (char *)malloc(strlen(accountHolder) + 1);
        if (this->accountHolder != nullptr)
        {
            strcpy(this->accountHolder, accountHolder);
        }
        this->accountNumber = (char *)malloc(strlen(accountNumber) + 1);
        if (this->accountNumber != nullptr)
        {
            strcpy(this->accountNumber, accountNumber);
        }
        this->balance = balance;
    }
    ~BankAccount()
    {
        if(accountHolder != nullptr)
            free(accountHolder);
        if(accountNumber != nullptr)
            free(accountNumber);
    }
    void setAccountHolder(const char *accountHolder)
    {
        if (this->accountHolder != nullptr)
        {
            free(this->accountHolder);
        }
        this->accountHolder = (char *)malloc(strlen(accountHolder) + 1);
        if (this->accountHolder != nullptr)
        {
            strcpy(this->accountHolder, accountHolder);
        }
    }
    void setAccountNumber(const char *accountNumber)
    {
        if (this->accountNumber != nullptr)
        {
            free(this->accountNumber);
        }
        this->accountNumber = (char *)malloc(strlen(accountNumber) + 1);
        if (this->accountNumber != nullptr)
        {
            strcpy(this->accountNumber, accountNumber);
        }
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    const char *getAccountHolder()
    {
        return accountHolder ? accountHolder : "";
    }
    const char *getAccountNumber()
    {
        return accountNumber ? accountNumber : "";
    }
    double getBalance()
    {
        return balance;
    }
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        balance -= amount;
    }
};

class Bank
{
private:
    int holder_count;
    BankAccount allAccounts[100];

public:
    Bank()
    {
        holder_count = 0;
    }
    ~Bank()
    {
    }
    void addAccount(const char *accountNumber, const char *accountHolder)
    {
        if (holder_count < 100)
        {
            allAccounts[holder_count].setAccountNumber(accountNumber);
            allAccounts[holder_count].setAccountHolder(accountHolder);
            holder_count += 1;
        }
    }
    void displayAllAccounts()
    {
        cout << "Registered Accounts: " << endl;
        for (int i = 0; i < holder_count; i++)
        {
            allAccounts[i].display();
            cout << endl;
        }
        cout << endl;
    }
    void deposit(const char *accountNumber, double amount)
    {
        for (int i = 0; i < holder_count; i++)
        {
            if (strcmp(allAccounts[i].getAccountNumber(), accountNumber) == 0)
            {
                allAccounts[i].deposit(amount);
                return;
            }
        }
    }
    void withdraw(const char *accountNumber, double amount)
    {
        for (int i = 0; i < holder_count; i++)
        {
            if (strcmp(allAccounts[i].getAccountNumber(), accountNumber) == 0)
            {
                allAccounts[i].withdraw(amount);
                return;
            }
        }
    }
    void removeAccount(const char *accountNumber)
    {
        for (int i = 0; i < holder_count; i++)
        {
            if (strcmp(allAccounts[i].getAccountNumber(), accountNumber) == 0)
            {
                cout << "Account '" << allAccounts[i].getAccountHolder() << " ("
                     << accountNumber << ")' removed successfully.\n" << endl;
                for (int j = i; j < (holder_count - 1); j++)
                {
                    allAccounts[j].setAccountHolder(allAccounts[j + 1].getAccountHolder());
                    allAccounts[j].setAccountNumber(allAccounts[j + 1].getAccountNumber());
                    allAccounts[j].setBalance(allAccounts[j + 1].getBalance());
                }
                allAccounts[holder_count - 1] = BankAccount();
                holder_count -= 1;
                return;
            }
        }
    }
};

int main()
{
    Bank bank;
    // Add new bank accounts
    bank.addAccount("12345", "John Doe");
    bank.addAccount("67890", "Jane Smith");
    // Perform transactions
    bank.deposit("12345", 1000.0);
    bank.deposit("67890", 500.0);
    // Display account details
    bank.displayAllAccounts();
    // Perform transactions
    bank.withdraw("12345", 200.0);
    bank.withdraw("67890", 500.0);
    // Display account details after transaction
    bank.displayAllAccounts();
    // Remove an account
    bank.removeAccount("67890");
    // Display account details after removal
    bank.displayAllAccounts();
    // Add more accounts
    bank.addAccount("24680", "Sarah Adams");
    bank.addAccount("13579", "Michael Lee");
    // Perform transactions on the newly added accounts
    bank.deposit("24680", 1500.0);
    bank.deposit("13579", 200.0);
    bank.withdraw("13579", 100.0);
    bank.withdraw("24680", 300.0);
    // Display all accounts
    bank.displayAllAccounts();
    return 0;
}
