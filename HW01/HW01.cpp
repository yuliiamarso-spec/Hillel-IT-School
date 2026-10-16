#include <iostream>

using namespace std; 

int main()
{
    int num = 0;
    long long factorial = 1;

    cout << "Введіть число від 0 до 10: ";

	if(!(cin >> num))
	{
		cout << "Помилка вводу, це має бути ціле число від 0 до 10 " << endl;

		return 1;
	}

    else
	{ 
		if (num >= 0)
		{
       		if (num <= 10)
			{
				for (int i = 1; i <= num; i++)
				{
					factorial *= i;
				}
				cout << "Факторіал числа " << num << " дорівнює: "<<  factorial << endl;
			} 
			else
			{
				cout << "Ви ввели невірне число, це має бути ціле число не більше 10! " << endl;
			}
		}
		else
		{
			cout << "Ви ввели невірне число, це має бути ціле число не менше 0! " << endl;
		}	
	}

    return 0;
}