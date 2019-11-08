#include <iostream>
#include <cmath>

using namespace std;

/*This program demonstrates a simple class
 *Circle class declaration*/

 class Circle
 {
 	private:
 		double radius;
 	public:
 		void setRadius(double r)
 		{
			/* do not need to use the . notation radius is a
 			 * member variable of the class -- this is a mutator,
 			 * a.k.a setter function*/
 			radius = r; 
 		}
		 /*only uses does not modify radius This is called an
 		  *accessor a.k.a. getter function */
 		double getArea() 
 		{
 			return 3.14 * pow(radius, 2);
 		}
 };

 int main()
 {
 	/*Define 2 circle objects*/
 	Circle circle1, circle2;
  
 	/*Call the setRadius function for each circle.  Passes in the radius to the
 	 *setRadius function.  The data member for radius is then set to equal
 	 *to the value passed in to the function setRadius*/
 	circle1.setRadius(1);
 	circle2.setRadius(2.5);
  	
 	/*Call the getArea function for each instance of circle.
 	 *the result is then printed.*/
 	cout << "The area of circle1 is " << circle1.getArea() << endl;
 	cout << "The area of circle2 is " << circle2.getArea() << endl;

	circle1.setRadius(10);
	
 	cout << "The area of circle1 is " << circle1.getArea() << endl;
 	cout << "The area of circle2 is " << circle2.getArea() << endl;

 	return 0;

 }
