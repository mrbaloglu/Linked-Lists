#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

Person::Person( const string iname)
{
    name = iname;
    head = NULL;
    numberOfPhoneNums  = 0;
}
Person::~Person()
{
    if(head == NULL)
        return;
    while(head->next != NULL)
    {
        removeFirstPhoneNum();
    }
    delete head;
}
Person::Person( const Person& personToCopy )
{
    name = personToCopy.name;
    numberOfPhoneNums = personToCopy.numberOfPhoneNums;
    if(personToCopy.head == NULL)
    {
        head = NULL;
    }
    else{
        head = new PhoneNode;
        head->p = personToCopy.head->p;
        PhoneNode *cur1 = head, *cur2 = personToCopy.head->next;
        while(cur2 != NULL)
        {
            PhoneNode *tmp = new PhoneNode;
            tmp->p = cur2->p;
            cur1->next = tmp;
            cur1 = cur1->next;
            cur2 = cur2->next;
            tmp = NULL;
        }

    }
}
void Person::operator=( const Person &right )
{
    PhoneNode *cur1 = head , *cur2 = right.head;
    numberOfPhoneNums = right.numberOfPhoneNums;
    name = right.name;
    if(right.head == NULL)
    {
        //cout<<"personop2"<<endl;
        head = NULL;
        return;
    }
    else {
        if(head == NULL)
        {
            head = new PhoneNode;
            head->p = cur2->p;
            head->next = NULL;
            cur1 = head->next;
            cur2 = cur2->next;
        }
        while(cur1 != NULL)
        {
            if(cur2 !=  NULL) {
                cur1->p = cur2->p;
                cur2 = cur2->next;
                if(cur2 == NULL)
                {
                    PhoneNode *tmp = cur1;
                    cur1 = cur1->next;
                    tmp->next = NULL;
                }
                else
                    cur1 = cur1->next;
            }
            else {
                PhoneNode *tmp = cur1;
                cur1 = cur1->next;
                tmp->next = NULL;
                delete tmp;
            }
        }
        while(cur2 != NULL)
        {
            if(head->next == NULL)
                cur1 = head;
            PhoneNode *tmp = new PhoneNode;
            tmp->p = cur2->p;
            cur1->next = tmp;
            cur1 = cur1->next;
            cur1->next = NULL;
            cur2 = cur2->next;
            tmp = NULL;
        }
    }
}
string Person::getName()
{
    return name;
}
int Person::getNumberOfPhoneNums()
{
    return numberOfPhoneNums;
}
bool Person::addPhone( const int areaCode, const int number )
{
    if(head == NULL)
    {
        head = new PhoneNode;
        Phone ph(areaCode, number);
        head->p = ph;
        head->next = NULL;
        numberOfPhoneNums++;
        return true;
    }
    PhoneNode *cur = head;
    while(cur != NULL)
    {
        if(cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
        {
            return false;
        }
        cur = cur->next;
    }
    cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new PhoneNode;
    Phone ph(areaCode, number);
    cur->next->p = ph;
    cur->next->next = NULL;
    numberOfPhoneNums++;
    return true;
}
bool Person::removePhone( const int areaCode, const int number )
{
    PhoneNode *cur = head, *ncur = head;
    if(head->p.getAreaCode() == areaCode && head->p.getNumber() == number)
    {
        head = head->next;
        cur->next = NULL;
        delete cur;
        numberOfPhoneNums--;
        return true;
    }
    cur = head->next;
    while(cur != NULL)
    {
        if(cur->p.getAreaCode() == areaCode && cur->p.getNumber() == number)
        {
            ncur->next = cur->next;
            cur->next = NULL;
            delete cur;
            numberOfPhoneNums--;
            return true;
        }
        cur = cur->next;
        ncur = ncur->next;
    }
    return false;
}
void Person::displayPhoneNumbers()
{
    if(head == NULL)
    {
        cout<<"--EMPTY--"<<endl;
        return;
    }
    else {
        PhoneNode *cur = head;
        while(cur != NULL)
        {
            cout<<"Phone Number: "<<cur->p.getAreaCode()<<" "<<cur->p.getNumber()<<endl;
            cur = cur->next;
        }
    }
}
void Person::removeFirstPhoneNum()
{
    if(head == NULL)
        return;
    else {
        PhoneNode* tmp = head;
        head = head->next;
        tmp->next = NULL;
        delete tmp;
        numberOfPhoneNums--;
        tmp = NULL;
    }
}
bool Person::displayAreaCode(int area_Code)
{
    PhoneNode *cur = head;
    bool flag = false;
    int cnt = 0;
    while(cur != NULL)
    {

        if(cur->p.getAreaCode() == area_Code)
        {
            cnt++;
            if(cnt == 1)
                cout<<name<<endl;
            cout<<"Phone Number: "<<cur->p.getAreaCode()<<" "<<cur->p.getNumber()<<endl;
            flag = true;
        }
        cur = cur->next;
    }
    return flag;
}
