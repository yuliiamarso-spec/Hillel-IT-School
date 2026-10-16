#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

    srand(time(NULL));
    
    const int num = 50;
    int numArr[num];
  
    cout << "Наш массив: " << " ";
    for(int i = 0; i < num; i++)
    {
        numArr [i] = rand() % 100;
        cout << numArr[i] << " ";
    }

    cout << "\nНаші парні числа: " << " ";
    for(int i = 0; i < num; i++)
    {
        if (numArr[i] % 2 == 0)
        {
            cout << numArr[i] << " ";
        }
    }
    
    return 0;
}
