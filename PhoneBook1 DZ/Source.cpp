#include <iostream>
#include <fstream>
using namespace std;
struct Contact
{
    char name[40];
    char phoneNumber[20];
    char homeNumber[15];
};

class PhoneBook
{
private:
    int size;
    Contact* book;
public:
    // ctor x2
    PhoneBook()
    {   
        size = 0;
        book = nullptr;
    }
    PhoneBook(Contact cont)
    {
        size = 1;
        book = new Contact[size];
        book[0] = cont;
    }
    // dtor
    ~PhoneBook()
    {
        delete[] book;
    }
    //##############################################
    void Print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Contact #" << i + 1 << endl;
            cout << "Name: " << book[i].name << endl;
            cout << "Phone Number: " << book[i].phoneNumber << endl;
            cout << "Home Number: " << book[i].homeNumber << endl<<endl;
        }
        cout << endl;
    }
    //##############################################
    void AddContacts(Contact cont)
    {
        Contact* temp = new Contact[size + 1];

        for (int i = 0; i < size; i++)
        {   temp[i] = book[i];   }
        temp[size] = cont;
        size = size + 1;
        delete[] book;
        book = temp;
    }
    //##############################################
    void Delete(int number)
    {
        Contact* temp = new Contact[size - 1];
        int a = 0;
        for (int i = 0; i < size; i++)
        {
            if (i != number -1)
            {
                temp[a] = book[i];
                a++;
            }
        }
        size = size - 1;
        delete[] book;
        book = temp;
    }
    inline void PrintForSearch(int size,int d)
    {
        cout << "Name: " << book[d].name << endl;
        cout << "Phone Number: " << book[d].phoneNumber << endl;
        cout << "Home Number: " << book[d].homeNumber << endl;
    }
    void SearchByName(const char* _name)
    {
        int d = 0;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(book[i].name, _name)==0)
            {
                d = i;
                PrintForSearch(size, d);
            }
        }
    }

    void SearchByMobilePhone(const char* _Mphone)
    {
        int d = 0;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(book[i].phoneNumber, _Mphone) == 0)
            {
                d = i;
                PrintForSearch(size, d);
            }
        }
    }
    
    void SearchByHomePhone(const char* _Hphone)
    {
        int d = 0;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(book[i].homeNumber, _Hphone) == 0)
            {
                d = i;
                PrintForSearch(size, d);
            }
        }
    }
    void Save() const
    {
        ofstream fout;
        fout.open("Saves.txt", ios_base::app);
        bool isOpen = fout.is_open();
        if (isOpen == true)
        {
            ofstream rewrite("Saves.txt");
            rewrite.write("", 0);
            rewrite.close();
            for (int i = 0; i < size; i++)
            {
                fout << "Name: " << book[i].name << endl;
                fout << "Phone Number: " << book[i].phoneNumber << endl;
                fout << "Home Number: " << book[i].homeNumber << endl;
            }
        }
        else
        {   cout << "Error404" << endl;   }
    }

    void Load()
    {
        ifstream fin;
        fin.open("Saves.txt");
        bool isOpen = fin.is_open();
        if (isOpen == true)
        {
            int currentS = 0;
            Contact contactFile;
            while (!fin.eof())
            {
                currentS++;
                if (currentS == 1)
                {
                    fin >> contactFile.name;
                }
                else if (currentS == 2)
                {
                    fin >> contactFile.phoneNumber;
                }
                else if (currentS == 3)
                {
                    fin >> contactFile.homeNumber;
                    currentS = 0;
                    AddContacts(contactFile);
                }
            }
        }
        else
        {   cout << "Error404" << endl;   }
    }
};

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