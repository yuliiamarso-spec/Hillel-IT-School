#include <iostream>

using namespace std;

int string_Length(const char* myStr){
    int len = 0;
    while( *myStr != '\0'){
        len ++;
        myStr++;
    }
    return len;
}

char* allocateString(int len){
    char* myStr = new char [len + 1];

    return myStr;
}

void copyString(char* myStr, const char* buffer){
    while (*buffer !='\0'){
        *myStr = *buffer;
        myStr++;
        buffer++;
    }
    *myStr = '\0';
}

int Length(char* myStr, int len){
    int curr_len = 1;
    int max_len = 1;  

    for (int i = 0; i < len - 1; i++){
        if (myStr[i] == myStr[i + 1]){
            curr_len++;
        }else {
            if (curr_len > max_len) {
                max_len = curr_len;
            }
            curr_len = 1;
        }
    }

    if (curr_len > max_len){
        max_len = curr_len;
    }

    return max_len;
}

int longestSequence_idx(char* myStr, int len, int max_len){
    int curr_len = 1;
    int curr_idx = 0;
    int max_idx = 0;

    for (int i = 0; i < len - 1; i++){
        if (myStr[i] == myStr[i + 1]){
            curr_len++;
        }else {
            if (curr_len == max_len){
                return curr_idx;
            }
            curr_len = 1;
            curr_idx = i + 1;
        }
    }

    if (curr_len == max_len){
        max_idx = curr_idx;
    }

    return max_idx;
}

void printLongest(char* myStr, int max_idx, int max_len){
    for(int i = 0; i < max_len; i++){
            cout << myStr[max_idx];
        }
}

void freeArray(char* myStr){

    delete [] myStr;
}

int main(){

    char buffer [256];
    cout << "Введіть рядок: ";
    cin.getline(buffer, 256, '\n');

    int len = string_Length(buffer);

    if(len == 0){

        cout << "Найдовша послідовність: " ;
        cout << "\nДовжина: 0";

        return 0;
    }

    char* myStr = allocateString(len);

    copyString(myStr, buffer);

    int max_len = Length(myStr, len);

    int max_idx = longestSequence_idx( myStr, len, max_len);

    cout << "Найдовша послідовність: " ;
    printLongest( myStr, max_idx, max_len);

    cout << "\nДовжина: " << max_len << endl;

    freeArray(myStr);

    return 0;
}