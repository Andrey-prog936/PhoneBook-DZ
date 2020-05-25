#include <iostream>
#include "book.h"
using namespace std;

int main()
{
    PhoneBook PB1;
    PB1.AddContacts({ "Andrey","38067894****","88009003535" });
    PB1.AddContacts({  "Sasha","38066511****","88004008383" });
    cout << "### - - -Saving- - - ###" << endl;
    PB1.Save();
    PB1.Print();
    cout << "\n### - - -Searching by name- - - ###" << endl;
    PB1.SearchByName("Andrey");
    cout << "\n### - - -Searching by mobile phone- - - ###" << endl;
    PB1.SearchByMobilePhone("38067894****");
    cout << "\n### - - -Deleting- - - ###" << endl;
    PB1.Delete(2);
    PB1.Print();

    system("pause");
    return 0;
}