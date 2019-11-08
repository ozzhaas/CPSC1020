// This program uses a constant reference parameter.
// It also shows how to return an object from a function.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryItem
{
  private:
	int partNum;              // Part number
	string description;       // Item description
	int onHand;               // Units on hand
	double price;             // Unit price

  public:

	void storeInfo(int p, string d, int oH, double cost); // Prototype

	int getPartNum() const;    // The get functions have all been made
	                          // const functions. This ensures they
                            // cannot alter any class member data.
	string getDescription() const;
	int getOnHand() const;
	double getPrice() const;

};

// Implementation code for InventoryItem class function storeInfo
void InventoryItem::storeInfo(int p, string d, int oH, double cost)
{
  partNum = p;
	description = d;
	onHand = oH;
	price = cost;
}

//getters
int InventoryItem::getPartNum() const
{
  return partNum;
}

string InventoryItem::getDescription() const
{
  return description;
}

int InventoryItem::getOnHand() const
{
  return onHand;
}

double InventoryItem::getPrice() const
{
  return price;
}
/******************************************************************************/
/*NOTICE the InventoryItem class declaration appears before the prototype
 *for the storeValues and showValues functions. This is important.  Both
 *functions have an InventoryItem object as a parameter, the compiler must
 *know what an InventoryItem is before it encounters anything that refers to
 *it.*/
 /*****************************************************************************/
// Function prototypes for client program
InventoryItem createItem();              // Returns an InventoryItem object
void showValues (const InventoryItem);  // Receives a reference to an
                                         // InventoryItem object

//*************** main *****************
int main()
{
	InventoryItem part = createItem();
	showValues(part);
	return 0;
}

/************************************************************
 *                          createItem                      *
 * This function stores user input data in the members of a *
 * locally defined InventoryItem object, then returns it.   *
 ************************************************************/
InventoryItem createItem()
{
	InventoryItem tempItem;    // Local InventoryItem object
	int partNum;               // Local variables to hold user input
	string description;
	int qty;
	double price;

	// Get the data from the user
	cout << "Enter data for the new part number \n";
	cout << "Part number: ";
	cin  >> partNum;
	cout << "Description: ";
	cin.ignore();
	getline(cin, description);
	cout << "Quantity on hand: ";
	cin  >> qty;
	cout << "Unit price: ";
	cin  >> price;

	// Store the data in the InventoryItem object and return it
	tempItem.storeInfo(partNum, description, qty, price);
	return tempItem;
}

/***************************************************************
 *                         showValues                          *
 * This function displays the member data in the InventoryItem *
 * object passed to it. Because it was passed as a constant    *
 * reference, showValues accesess the original object, not a   *
 * copy, but it CAN ONLY CALL MEMBER FUNCTION DECLARED TO BE   *
 * CONST. This prevents it from calling any mutator functions. *
 ***************************************************************/
void showValues(const InventoryItem item)
{
	cout << fixed << showpoint << setprecision(2) << endl;;
	cout << "Part Number  : "  << item.getPartNum() << endl;
	cout << "Description  : "  << item.getDescription() << endl;
	cout << "Units On Hand: "  << item.getOnHand() << endl;
	cout << "Price        : $" << item.getPrice() << endl;

  /*These lines of code are to demonstrate that the function
   *can not change  the item because it is const.  Remember this
   *function is print the values of item not change it.*/
	//item.storeInfo(999, "hammer", 19, 19.99);
	//cout << "part num again" << item.getPartNum() << endl;
}
