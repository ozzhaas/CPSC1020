#include <iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;
public:
  NumberArray(int size, double value);
 ~NumberArray()
 { cout << "Destructor\n";
   if (arraySize > 0) delete [ ] aPtr;
 }
  // Commented out to avoid problems with the
  // default copy constructor
  void print() const;
  void setValue(double value);
};
