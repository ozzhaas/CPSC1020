/*Overriding example*/
#include <iostream>
#include <string>
using namespace std;

class Base
{
  private:
    string name;
  public:
    Base() :name("noName"){cout << "Base default Constructor\n"; }

    Base(string n) : name(n){cout << "Base regular Constructor\n"; }

    void setName(string name)
    {
      this->name = name;
    }
    string getName()
    {
      return name;
    }

    void printInfo()
    {
      cout << name << endl;
    }

};

class Derived : public Base
{
  private:
     string title;
     string address;
     string city;
     string state;
     int zip;

  public:
    void printName()
    {
      cout << title << " " << getName() << endl;
      cout << address << endl << city << "," << zip << endl;
    }

    Derived(): Base("Frankenstein"), title("Dr."), address("123 Main St."), city("Clemson"),
               state("SC"), zip(29634) {cout << "Derived default Constructor\n"; }

    Derived(string title, string name, string address, string city,
      string state, int zip):
      title(title), Base(name),  address(address), city(city),
      state(state), zip(zip){cout << "Derived Regular Constructor\n"; }


    void setAddress(string address)
    {
      this->address = address;
    }
    void setTitle(string title)
    {
      this->title = title;
    }
    void setCity(string city)
    {
      this->city = city;
    }
    void setState(string state)
    {
      this->state = state;
    }
    void setZip(int zip)
    {
      this->zip = zip;
    }
    void printInfo()
    {
      //cout << title << " " << name << endl;
      cout << title << " " << getName() << endl;
      cout << address << endl;
      cout << city << ", " << state << " " << zip << endl;
      cout << endl;
    }
};


int main()
{
    Base base;
    base.printInfo();
    base.setName("Yvon Feaster");
    base.printInfo();
    cout << "after base:\n\n";

    //Default constructor is called
    Derived derived;
    derived.printInfo();
    derived.setName("Yvon H. Feaster");
    derived.printInfo();
    cout << "after derived:\n\n";
    Derived derived2("Dr.", "Yvon", "301 McAdams Hall", "Clemson", "SC", 29634);
    derived2.printInfo();

    return 0;
}
