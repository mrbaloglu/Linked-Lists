#include <string>
#include <iostream>
#include "Phone.h"
#include "PhoneBook.h"
#include "Person.h"
int main()
{
    cout<<1<<endl;
    PhoneBook pb;
    cout<<2<<endl;
    Person ps1("emre");
    cout<<3<<endl;
    Person ps2("aa");
    cout<<4<<endl;
    ps1.addPhone(90,555);
    cout<<5<<endl;
    ps1.addPhone(90,555);
    ps1.addPhone(90,444);
    ps1.addPhone(90,333);
    ps2.addPhone(1,500);
    ps2.addPhone(1,100);
    ps2.addPhone(1,200);
    ps2.addPhone(1,300);
    ps2.addPhone(2,500);

    Person ps3(ps2);
    cout<<"display phone nums"<<endl;
    ps1.displayPhoneNumbers();
    cout<<"------------------"<<endl;
    ps2.displayPhoneNumbers();
    cout<<"------------------"<<endl;
    ps3.displayPhoneNumbers();
    cout<<6<<endl;
    cout<<"Display area code"<<endl;
    pb.displayAreaCode(90);
    pb.addPerson("emre");
    pb.addPhone("emre",90,555);
    pb.addPhone("emre",90,555);
    pb.addPhone("emre",90,444);
    cout<<7<<endl;
    pb.addPerson("aa");
    cout<<"Display people-----------------"<<endl;
    pb.displayPeople();
    pb.displayAreaCode(90);
    cout<<"---------------------------"<<endl;
    PhoneBook pb2 = pb;
    pb2.displayPeople();
    cout<<"**************"<<endl;
    pb2.displayAreaCode(90);

    return 0;
}
