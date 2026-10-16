#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

const string filePath = "D:/Study/projects/Hillel/Lesson20/test_file.txt";

int main()
{
    ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;   
    }
    cout << "Файл відкрито успішно!" << endl;

    map<char, int> counts;
    char ch;
    while (inputFile.get(ch))
    {
        if (ch != '\n' && ch != '\r' && ch != '\t')
            {
                counts[ch]++;
            }
    }

    cout << "Частота символів (відсортовано за алфавітом):\n";
    for (map<char, int>::const_iterator it = counts.begin(); it != counts.end(); ++it) 
    {
        cout << left << "char: " << it->first << " amount: " << it->second << '\n';
    }

    inputFile.close();

    return 0;
}
