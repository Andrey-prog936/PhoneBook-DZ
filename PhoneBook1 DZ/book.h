#pragma once
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
    PhoneBook();
    PhoneBook(Contact cont);
    // dtor
    ~PhoneBook();
    void Print() const;
    void AddContacts(Contact cont);
    void Delete(int number);
    inline void PrintForSearch(int size, int d);
    void SearchByName(const char* _name);
    void SearchByMobilePhone(const char* _Mphone);
    void SearchByHomePhone(const char* _Hphone);
    void Save() const;
    void Load();
};