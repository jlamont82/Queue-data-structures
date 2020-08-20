#pragma once
#include <string>


using namespace std;


class Person
{
private:
    string name;
    string telNo;

public:
    Person(string _name, string _telNo) 
    {
        name = _name;
        telNo = _telNo;
    }

    
    Person(){}

    bool operator==(const Person& Person)
    {
        return ((this->name == Person.name) && (this->telNo == Person.telNo));
    }

    void printperson()
    {
        cout << " Customer name " << name << " Phone No " << telNo << endl;

    }
};