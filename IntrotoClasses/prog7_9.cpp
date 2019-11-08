// This program passes an object to a function. It passes it
// to one function by reference and to another by value.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryItem
{
  private:
	int partNum;         // Part number
	string description;  // Item description
	int onHand;          // Units on hand
	double price;        // Unit price

  public:

	/*storeInfo basically takes place of setters and constructor*/
	void storeInfo(int p, string d, int oH, double cost); // Prototype

  //getters
	int getPartNum();
	string getDescription();
	int getOnHand();
  double getPrice();

};

/*************************** Memember Functions *******************************/
int InventoryItem::getPartNum()
{
  return partNum;
}

string InventoryItem::getDescription()
{
  return description;
}

int InventoryItem::getOnHand()
{
  return onHand;
}

double InventoryItem::getPrice()
{
  return price;
}

// Implementation code for InventoryItem class function storeInfo
void InventoryItem::storeInfo(int p, string d, int oH, double cost)
{
  partNum = p;
	description = d;
	onHand = oH;
	price = cost;
}

/*************************** Client Function Prototypes ***********************/
// Function prototypes for client program
void storeValues(InventoryItem&);  // Receives an object by reference
void showValues (InventoryItem);   // Receives an object by value


/********************************* Main ***************************************/
int main()
{

  /*creating an instance of the InventoryItem class*/
	InventoryItem part;

	storeValues(part);
	showValues(part);
	return 0;
}

/*These functions are not part of the InventoryItem class *
 *they are considered client functions that use the InventoryItem class*/


/**********************************************************
 *                        storeValues                     *
 * This function stores user input data in the members of *
 * an InventoryItem object passed to it by reference.     *
 * ********************************************************/

 /*Why does this function require you to pass by reference*/
void storeValues(InventoryItem &item)
{
  // Local variables to hold user input
	int partNum;
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

	// Store the data in the InventoryItem object
	item.storeInfo(partNum, description, qty, price);
}

/********************************************************
 *                       showValues                     *
 * This function displays the member data stored in the *
 * InventoryItem object passed to it by value.          *
 ********************************************************/

 /*Why does this not need the be pass by reference*/
void showValues(InventoryItem item)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Part Number  : "  << item.getPartNum() << endl;
	cout << "Description  : "  << item.getDescription() << endl;
	cout << "Units On Hand: "  << item.getOnHand() << endl;
	cout << "Price        : $" << item.getPrice() << endl;
}
