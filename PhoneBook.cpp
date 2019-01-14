#include <string>
#include <iostream>
#include "Phone.h"
#include "PhoneBook.h"
#include "Person.h"
using namespace std;
bool PhoneBook::iequals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}
PhoneBook::PhoneBook()
{
    head = NULL;
    numberOfPeople = 0;
}
PhoneBook::~PhoneBook()
{
    if(head == NULL)
        return;
    while(head->next != NULL)
    {
        removeFirstPerson();
    }
    delete head;
}
PhoneBook::PhoneBook( const PhoneBook& systemToCopy )
{
    numberOfPeople = systemToCopy.numberOfPeople;
    if(systemToCopy.head == NULL)
    {
        head = NULL;
    }
    else
    {
        head = new Node;
        Person tmp(systemToCopy.head->t);
        head->t = tmp;
        head->next = NULL;
        Node *cur1 = head, *cur2 = systemToCopy.head->next;
        while(cur2 != NULL)
        {
            Node * tmp = new Node;
            tmp->t = cur2->t;
            cur1->next = tmp;
            cur1 = cur1->next;
            cur2 = cur2->next;
            tmp = NULL;
        }
    }
}
void PhoneBook::operator=( const PhoneBook &right )
{
    Node *cur1 = head , *cur2 = right.head;

        if(head == NULL)
        {
            head = new Node;
            head->t = cur2->t;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        while(cur1 != NULL)
        {
            if(cur2 !=  NULL) {
                cur1->t = cur2->t;
                cur2 = cur2->next;
                if(cur2 == NULL)
                {
                    Node *tmp = cur1;
                    cur1 = cur1->next;
                    tmp->next = NULL;
                }
                else
                    cur1 = cur1->next;
            }
            else {
                Node *tmp = cur1;
                cur1 = cur1->next;
                tmp->next = NULL;
                delete tmp;
            }
        }
        while(cur2 != NULL)
        {
            Node *tmp = new Node;
            tmp->t = cur2->t;
            cur1->next = tmp;
            cur1 = cur1->next;
            cur2 = cur2->next;
            tmp = NULL;
        }
}
bool PhoneBook::addPerson( string name )
{
    if(head == NULL)
    {
        head = new Node;
        Person pr(name);
        head->t = pr;
        head->next = NULL;
        numberOfPeople++;
        return true;
    }
    Node *cur = head;
    while(cur != NULL)
    {
        if(iequals(cur->t.getName(), name))   //*****************************case
        {
            cout<<"Person already exist in the phonebook!"<<endl;
            return false;
        }
        cur = cur->next;
    }
    cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new Node;
    Person per(name);
    cur->next->t = per;
    cur->next->next = NULL;
    numberOfPeople++;
    return true;
}
bool PhoneBook::removePerson( string name )
{
    Node *cur = head, *ncur = head;
    if(iequals(head->t.getName(), name)) //*****************************case
    {
        head = head->next;
        cur->next = NULL;
        delete cur;
        numberOfPeople--;
        return true;
    }
    cur = head->next;
    while(cur != NULL)
    {
        if(iequals(cur->t.getName(), name))  //***************************case
        {
            ncur->next = cur->next;
            cur->next = NULL;
            delete cur;
            numberOfPeople--;
            return true;
        }
        cur = cur->next;
        ncur = ncur->next;
    }
    return false;
}
bool PhoneBook::addPhone( string personName, int areaCode, int number )
{
    Node *cur = head;
    while(cur != NULL)
    {
        if(iequals(cur->t.getName(), personName))
        {
            if(cur->t.addPhone(areaCode, number))
            {
                return true;
            }
            else{
                cout<<"The phone number already exists in the person's phone list!"<<endl;
                return false;
            }
        }
    }
    cout<<"The person does not exist in the phonebook!"<<endl;
    return false;
}
bool PhoneBook::removePhone( string personName, int areaCode, int number )
{
    Node *cur = head;
    while(cur != NULL)
    {
        if(iequals(cur->t.getName(), personName))
        {
            if(cur->t.removePhone(areaCode, number))
            {
                return true;
            }
            else{
                cout<<"The phone number does not exist in the person's phone list!"<<endl;
                return false;
            }
        }
    }
    cout<<"The person does not exist in the phonebook!"<<endl;
    return false;
}
void PhoneBook::displayPerson( string name )
{
    Node *cur = head;
    while(cur != NULL)
    {
        if(cur->t.getName() == name)
        {
            cout<<cur->t.getName()<<endl;
            cur->t.displayPhoneNumbers();
            return;
        }
    }
    cout<<"The person does not exist in the phonebook!"<<endl;
}
void PhoneBook::displayAreaCode( int areaCode )
{
    cout<<areaCode<<endl;
    if(head == NULL)
    {
        cout<<"--EMPTY--"<<endl;
        return;
    }
    Node *cur = head;
    bool flag = false;
    while(cur != NULL)
    {
        if(cur->t.displayAreaCode(areaCode))
        {
            flag = true;
        }
        cur = cur->next;
    }
    if(!flag)
        cout<<"--EMPTY--"<<endl;
}
void PhoneBook::displayPeople()
{
    if(head == NULL)
    {
        cout<<"--EMPTY--"<<endl;
    }
    else {
        Node *cur = head;
        while(cur != NULL)
        {
            cout<<"Person: "<<cur->t.getName()<<"number of phones "<<cur->t.getName()<<" is: "<<cur->t.getNumberOfPhoneNums()<<endl;
            cur = cur->next;
        }
    }
}
void PhoneBook::removeFirstPerson()
{
    if(head == NULL)
    {
        return;
    }
    else{
        Node *tmp = head;
        head = head->next;
        tmp->next = NULL;
        delete tmp;
    }
}
