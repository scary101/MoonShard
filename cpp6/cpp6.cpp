#include <iostream>
#include <string>

using namespace std;

int chekInputInt() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail()) {
            cout << "Некоректный ввод! Попробуйте снова" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return num;
            break;
        }
    }
}

double chekInputDouble() {
    double num;
    while (true) {
        cin >> num;

        if (cin.fail()) {
            cout << "Некоректный ввод! Попробуйте снова" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return num;
            break;
        }
    }
}

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNumber, double balance, double interestRate) {

        this->accountNumber = accountNumber;
        this->balance = balance;
        this->interestRate = interestRate;
    }

    BankAccount(int accountNumber, double balance) : interestRate(0) {

        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        else {
            cout << "На балансе нет денег" << endl;
            return false;
        }
    }

    double getBalance() {
        return balance;
    }

    double getInterest() {
        return balance * (interestRate / 100) * (1.0 / 12);
    }

    void setInterestRate(double newInterestRate) {
        interestRate = newInterestRate;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

bool transfer(BankAccount& from, BankAccount& to, double amount) {
    if (from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        return true;
    }
    else {
        cout << "Недостаточно средст на счете" << endl;
        return false;
    }
}

int main() {

    setlocale(LC_ALL, "RUS");

    BankAccount bankacc1(12345, 777.50, 5.2);
    BankAccount bankacc2(54321, 0);
    bool isRun = true;
    int action, accUser, accNum, stavka;
    double sum;

    while (isRun) {
        cout << "Введите  номер своего счета: ";
        bool runIs = true;
        accNum = chekInputInt();

        if (accNum == bankacc1.getAccountNumber()) { accUser = 1;}
        else if (accNum == bankacc2.getAccountNumber()) { accUser = 2;}
        else { cout << "Счет не найден!" << endl; continue; }

        while (runIs) {
            cout << "Выберите действие: \n1. Положить деньги на счет \n2. Снять деньги со счета \n3. Посмотреть баланс счета \n4. Доход по процентам \n5. Новая процентная ствака \n6. Узнать номер бакнковского счета \n7. Перевести на другой счет \n8. Выйти " << endl;
            cin >> action;
            if (accUser == 1) {
                switch (action)
                {
                case 1:
                    cout << "Введите сумму депозита: ";
                    sum = chekInputDouble();
                    bankacc1.deposit(sum);
                    break;
                case 2:
                    cout << "Введите сумму, которую хотите снять: ";
                    sum = chekInputDouble();
                    bankacc1.withdraw(sum);
                    break;
                case 3:
                    cout << "Ваш текущий баланс состовляет: " << bankacc1.getBalance() << endl;
                    break;
                case 4:
                    cout << "Ваш доход по процентам в месяц состовляет: " << bankacc1.getInterest() << endl;
                    break;
                case 5:
                    cout << "Введите новую процетную ставку";
                    stavka = chekInputDouble();
                    bankacc1.setInterestRate(stavka);
                    break;
                case 6:
                    cout << "Номер вашего банковского счета: " << bankacc1.getAccountNumber() << endl;
                    break;
                case 7: {
                    cout << "Введите сумму перевода" << endl;
                    sum = chekInputDouble();
                    if (transfer(bankacc1, bankacc2, sum)) {
                        cout << "Перевод успешно выполнен" << endl;
                    }
                    else {
                        cout << "Ошибка при выполнении перевода" << endl;
                    }
                }
                    break;
                case 8:
                    runIs = false;
                    break;
                default:
                    cout << "Действие не найдено!";
                    break;
                }
            }
            else if (accUser == 2) {
                switch (action)
                {
                case 1:
                    cout << "Введите сумму депозита: ";
                    sum = chekInputDouble();
                    bankacc2.deposit(sum);
                    break;
                case 2:
                    cout << "Введите сумму, которую хотите снять: ";
                    sum = chekInputDouble();
                    bankacc2.withdraw(sum);
                    break;
                case 3:
                    cout << "Ваш текущий баланс состовляет: " << bankacc2.getBalance() << endl;
                    break;
                case 4:
                    cout << "Ваш доход по процентам в месяц состовляет:  " << bankacc2.getInterest() << endl;
                    break;
                case 5:
                    cout << "Введите новую процетную ставку";
                    stavka = chekInputDouble();
                    bankacc2.setInterestRate(stavka);
                    break;
                case 6:
                    cout << "Номер вашего банковского счета: " << bankacc2.getAccountNumber() << endl;
                    break;
                case 7: {
                    cout << "Введите сумму перевода" << endl;
                    sum = chekInputDouble();
                    if (transfer(bankacc2, bankacc1, sum)) {
                        cout << "Перевод успешно выполнен" << endl;
                    }
                    else {
                        cout << "Ошибка при выполнении перевода" << endl;
                    }
                }
                    break;
                case 8:
                    runIs = false;
                    break;
                default:
                    cout << "Действие не найдено!";
                    break;
                }
            }
        }
    }

}




