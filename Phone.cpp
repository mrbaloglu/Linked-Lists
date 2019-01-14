#include <string>
#include <iostream>
#include "Phone.h"
using namespace std;

Phone::Phone()
{
    areaCode = 0;
    number = 0;
}
Phone::Phone( const int area_Code, const int i_number )
{
    areaCode = area_Code;
    number = i_number;
}
int Phone::getAreaCode()
{
    return areaCode;
}
int Phone::getNumber()
{
    return number;
}
