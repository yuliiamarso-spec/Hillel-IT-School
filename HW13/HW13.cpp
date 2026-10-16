#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string baseFolder = "D:/Study/projects/Hillel/Lesson21/";

struct Book 
{
	int  id;
	char title[50];
	char author[40];
	int year;
};

Book getBook(fstream& f, int idx)
{
    Book readBook;
    f.seekg(idx * sizeof(Book), ios::beg);
    f.read(reinterpret_cast<char*>(&readBook), sizeof(Book));

    return readBook;
}

void printHeader()
{
    cout << left << setw(3)  << "ID" << "|  " << setw(25) << "Назва" << "|  " << setw(25) << "Автор" << "|  " << setw(8)  << "Рік" << endl;
    cout << "---------------------------------------------------------------" << endl;  
}

void printBook(Book book)
{
    cout << left << setw(3)  << book.id << "|  " << setw(20) << book.title << "|  " << setw(20) << book.author << "|  " << setw(8)  << book.year << endl;
}

int main()
{    
    Book books[] = {
	{ 1, "1984", "George Orwell", 1949 },
	{ 2, "Animal Farm", "George Orwell", 1945 },
	{ 3, "We", "Yevgeny Zamyatin", 1924 },
	{ 4, "The City of the Sun", "Tommaso Campanella", 1602 },
	};

    string bookFile = baseFolder + "library.bin";

    ofstream bookBinFile(bookFile, ios::out | ios::binary | ios::trunc);
	bookBinFile.write(reinterpret_cast<char*>(books), sizeof(books) / sizeof(books[0]) * sizeof(Book));
	bookBinFile.close();

    Book readBook;
    ifstream bookBinFileIn(bookFile, ios::in | ios::binary);
    printHeader();
	while (bookBinFileIn.read(reinterpret_cast<char*>(&readBook), sizeof(Book)))
	{
        printBook(readBook);
	}
    cout << "---------------------------------------------------------------" << endl; 
    cout << endl;
    bookBinFileIn.close();

    fstream bookBinFileInOut(bookFile, ios::in | ios::out | ios::binary);
    readBook = getBook(bookBinFileInOut, 0);

    printHeader();
    printBook(readBook);
    cout << "---------------------------------------------------------------" << endl;  
    cout << endl;

    readBook.year = 2026;
    bookBinFileInOut.seekp(0 * sizeof(Book), ios::beg);
	bookBinFileInOut.write(reinterpret_cast<const char*>(&readBook), sizeof(Book));

    bookBinFileInOut.clear();

    bookBinFileInOut.seekg(sizeof(Book) * 0, ios::beg);

    printHeader();
	while (bookBinFileInOut.read(reinterpret_cast<char*>(&readBook), sizeof(Book)))
	{
        printBook(readBook);
	}
    cout << "---------------------------------------------------------------" << endl;    
    cout << endl;
    bookBinFileInOut.close();

    return 0;
}