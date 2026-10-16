#include <iostream>

using namespace std;

enum class Category
{
    food,
    clothing,
    household
};

struct Items {
    char Name[50];
    int Price;
    Category category;
};

void SalesReport(int quantity, const Items& i)
{
    cout << "Name: " << "[" << i.Name << "]" << " Price: " << "[" << i.Price << "]"  << " Category: " << "[";
    
    switch (i.category)
    {
    case Category::food:
        cout << "Food";
        break;
    case Category::clothing:
        cout << "Clothing";
        break;
    case Category::household:
        cout << "Household";
        break;
    };

    cout << "]" << " Cost: " << "[" << quantity * i.Price << "]" << endl;

}

int main(){

    int quantity = 3;

    Items VC{"Vacuum Cleaner", 300, Category::household};

    SalesReport(quantity, VC);

    return 0;
}