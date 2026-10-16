#include <iostream>

using namespace std;

int main()
{
    const int ROW = 3;
    const int COL = 3;
    int myArr[ROW][COL] = {0};
    int (*ptr)[COL] = myArr;

    cout << "Масив:" << "\n";
    for(int i = 0; i < ROW; i++)
    {      
        for(int j = 0; j < COL; j++)
        {
            myArr[i][j] = (i + 1) * (j + 1); 
            cout << *(*(ptr + i) + j) << "\t"; //ptr[i][j] <=> *(ptr[i] + j) <=> *(*(ptr + i) + j) 
        } 
        cout << endl;
    }
 
    cout << "\nАдреса кожного елемену масиву: " << endl;
    for(int i = 0; i < ROW; i++)
    {  
        for(int j = 0; j < COL; j++)            
        {
            cout << *(ptr + i) + j << "\t"; //&(ptr[i][j]) <=> ptr[i] + j <=> *(ptr + i) + j
        }
        cout << endl;
    }

    cout << "\nАдреса кожного підмасиву: " << endl;
    for(int i = 0; i < ROW; i++)
    {  
        cout << ptr + i << "\n"; //Адреса підмасива ptr + i <=> &ptr[i]  - тип int (*ptr)[COL]
                                // ptr[i] <=> *(ptr + i) - i-та строка, тип int[COL]
                               //Адреса першого елемента &ptr[i][0] <=> ptr[i] (у виразі) - тип int*
    }

    cout << "\nСума елементів кожного рядка: " << endl;
    for(int i = 0; i < ROW; i++)
    {  
        int sumRow = 0;
            for(int j = 0; j < COL; j++)            
            {
                sumRow += *(*(ptr + i) + j); 
            }
        cout << sumRow << endl;    
    }

    cout << "\nСума елементів кожної колонки: " << endl;
    for(int j = 0; j < COL; j++)
    {  
        int sumCol = 0;
            for(int i = 0; i < ROW; i++)            
            {
                sumCol += *(*(ptr + i) + j); 
            }
        cout << sumCol << endl;    
    }

    cout << "\nСума діагональних елементів головної діагоналі: " << endl;
    int sumDiag1 = 0;
        for(int i = 0; i < ROW; i++)
        {
            for(int j = 0; j < COL; j++)
            {
                if(i == j)
                {  
                sumDiag1 += *(*(ptr + i) + j); 
                }
            }
        }
    cout << sumDiag1 << endl;

    cout << "\nСума діагональних елементів побічної діагоналі: " << endl;
    int sumDiag2 = 0;
    for(int i = 0; i < ROW; i++)
    {  
       for(int j = 0; j < COL; j++)
            {
                if(i + j == COL - 1)
                {  
                sumDiag2 += *(*(ptr + i) + j); 
                }
            } 
    }
    cout << sumDiag2 << endl;  

    return 0;
}