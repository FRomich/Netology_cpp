#include <iostream>
#include <string>

struct Account
{
    int number;
    std::string name;
    double balance;
};

static void changeBalance(Account* account, double balance)
{
    account->balance = balance;
}

static void printAccount(const Account* account)
{
    std::cout << "Ваш счёт: " << account->name << ", " << account->number <<  ", " << account->balance << "\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    Account account;
    double newBalance;

    std::cout << "Введите номер счёта:";
    std::cin >> account.number;
    std::cout << "Введите имя владельца:";
    std::cin >> account.name;
    std::cout << "Введите баланс:";
    std::cin >> account.balance;
    printAccount(&account);

    std::cout << "Введите новый баланс:";
    std::cin >> newBalance;

    changeBalance(&account, newBalance);

    printAccount(&account);

}
