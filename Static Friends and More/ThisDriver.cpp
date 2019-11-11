#include "ThisExample.h"
#include <iostream>

int main()
{
    Example ex(55);
    ex.printAddressAndValue();

    ex.setValue(155);
    ex.printAddressAndValue();

    return 0;
}
