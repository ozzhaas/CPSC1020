#include "ThisExample.h"
#include <iostream>
using namespace std;

//***************************************
//constructor                           *
//***************************************

Example::Example(int x)
{
    this->x = x;
}

//*****************************************
//set value of object.                    *
//*****************************************
void Example::setValue(int a)
{
  x = a;
}

//*****************************************
// Print address and value.               *
//*****************************************
void Example::printAddressAndValue()
{
 cout << "The object at address " << this << " has "
      << "value " << x << endl;
    //I could have used the pointer here
    // (*this).x or this->x but I don't really
    //need to here because I have access to x
}
