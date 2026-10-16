#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string accNum;
    static int OpenAccCounter;
    static int AccCounter;
    bool isOpen;

public:
    BankAccount()
    {
        isOpen = false;
        AccCounter++;
        accNum = "acc#" + to_string(AccCounter);
    }

    void OpenAccount()
    {
        if(isOpen)
        {
            cout << "Аккаунт вже існує" << endl;
            return;
        }
        OpenAccCounter++;
        isOpen = true;
    }

    string GetAccountNumber()
    {
        return accNum;
    }

    static int GetOpenAccountNumber()
    {
        return OpenAccCounter;
    }

    static int GetAccountCounter()
    {
        return AccCounter;
    }

    void CloseAccount()
    {
        if(!isOpen)
        {
            cout << "Аккаунт вже закритий" << endl;
            return;
        }
        OpenAccCounter--;
        isOpen = false;
    }

    bool IsOpen()
    {
        return isOpen;
    }
};

int BankAccount::OpenAccCounter = 0;
int BankAccount::AccCounter = 0;

int main()
{
    BankAccount Acc1;
    BankAccount Acc2;
    BankAccount Acc3;

    Acc1.OpenAccount();
    Acc2.OpenAccount();
    Acc3.OpenAccount();

    cout << "Acc1 - " << Acc1.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc1.IsOpen() << endl;
    cout << "Acc2 - " << Acc2.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc2.IsOpen() << endl;
    cout << "Acc3 - " << Acc3.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc3.IsOpen() << endl;

    cout << endl;

    Acc1.CloseAccount();
    Acc3.CloseAccount();

    cout << "Acc1 - " << Acc1.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc1.IsOpen() << endl;
    cout << "Acc2 - " << Acc2.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc2.IsOpen() << endl;
    cout << "Acc3 - " << Acc3.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc3.IsOpen() << endl;

    cout << endl;

    Acc2.OpenAccount();

    cout << "Acc2 - " << Acc2.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc2.IsOpen() << endl;

    cout << endl;
    Acc3.CloseAccount();
    cout << "Acc3 - " << Acc3.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc3.IsOpen() << endl;
    cout << endl;

    BankAccount Acc4;
    Acc4.OpenAccount();
    cout << "Acc4 - " << Acc4.GetAccountNumber() << " " << "Статус: " << boolalpha << Acc4.IsOpen() << endl;
    cout << endl;

    cout << "Відкриті аккаунти: " << BankAccount::GetOpenAccountNumber() << endl;
    cout << "Загальна кількість аккаунтів: " << BankAccount::GetAccountCounter() << endl;

    cout << endl;


    return 0;
}