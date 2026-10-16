#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int* createInArray(int N){
    int* inArr = new int [N];
        for(int i = 0; i < N; i++){
            inArr[i] = rand() % 10;
            cout << inArr[i] << " ";
        }
    return inArr;
}

int* getOddNumbersArray( int* inArr, int inArrSz, int& outArrSz){
    outArrSz = 0;
        for(int i = 0; i < inArrSz; i++){
            if (inArr[i] % 2 != 0){
                outArrSz++;
            }   
        }

    int M = outArrSz;
    int* outArr = new int [M];
    int j = 0;
        for(int i = 0; i < inArrSz; i++){
            if (inArr[i] % 2 != 0){
                outArr[j] = inArr[i];
                cout << outArr[j] << " ";
                j++;
            }
        }
    return outArr;
}

int main()
{
    srand(time(nullptr));

    cout << "Ведіть розмір масиву:" << " ";
    int N;
    cin >> N;

    cout << "Наш массив:" << " ";
    int* inArr = createInArray(N);
    int inArrSz = N;

    int outArrSz = 0;
    cout << "\nОбробленний масив:" << " ";

    int* outArr = getOddNumbersArray(inArr, inArrSz, outArrSz);
    cout << "\nКількість непарних чисел у масиві: " << outArrSz << endl;


    delete [] inArr;
    delete [] outArr;
    return 0;
}

