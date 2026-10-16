#include <iostream>
#include <cstring>

using namespace std;

class BankAccount
{
    private:
        char accountNum[11];
        char* ownerName;
        unsigned int balance;

    public:
        BankAccount(const char* p_accountNum, const char* p_ownerName, unsigned int p_balance);
        ~BankAccount();  

        void withdrow(unsigned amount);
        unsigned getBalance();
        void print();

        BankAccount() = delete;                       
        BankAccount(const BankAccount&) = delete; 
        BankAccount& operator = (const BankAccount&) = delete;
};

BankAccount::BankAccount(const char* p_accountNum, const char* p_ownerName, unsigned int p_balance)
{
    if (strlen(p_accountNum) != 10) {
    cout << "Номер рахунку повинен бути 10 символів\n";
    accountNum[0] = '\0';
    } 
    else 
    {
    strcpy(accountNum, p_accountNum);
    }

    size_t length = strlen(p_ownerName);
    ownerName = new char[length + 1];
    strcpy(ownerName, p_ownerName);

    balance = p_balance;
}

BankAccount::~BankAccount()
{
    delete[] ownerName;
}

void BankAccount::withdrow(unsigned amount)
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        cout << "Недостатньо коштів" << endl;
    }
}

unsigned BankAccount::getBalance()
{
    return balance;
}

void BankAccount::print()
{
    cout << "Ассоunt Num: [" << accountNum << "], Owner [" << ownerName << "], balance [" << balance << "]" << endl;
}

int main()
{
    BankAccount MyAcc("CW23883965", "John Smith", 1000);
    MyAcc.print();

    MyAcc.withdrow(100);
    MyAcc.print();

    //BankAccount MyAcc2 = MyAcc;
    
    BankAccount MyAcc2("AA11111111", "Yuliia Marso", 5000);
    MyAcc2.withdrow(200);
    MyAcc2.print();

    //MyAcc = MyAcc2;

    //BankAccount MyAcc3;

    return 0;
}