#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <sstream>
#include <assert.h>
#include <cstdint>
using namespace std;

class Pixel {
  private:
    uint8_t R, G, B;

  public:
    /*For each of the constructors you should use the Initialization List
     *to set the values*/
    Pixel (): R(0), G(0), B(0){};
    /*Although, C++ will provide a copy constructor for us that will do
     *a member-wise copy, for practice, you are still required to implement
     *this constructor.*/
    Pixel (const Pixel& p): R(p.R), G(p.G), B(p.B) {};
    Pixel (uint8_t red, uint8_t green, uint8_t blue): R(red), G(green), B(blue) {};
    ~Pixel (){};

    /*These are getters.  Do not change the signature of these functions.*/
    uint8_t& getR ();
    uint8_t& getG ();
    uint8_t& getB ();

    /*Clamp function - this function is used to make sure a pixels values
     *are not less than 0 and not greater than 255.*/
    static inline int clamp(int lo, int hi, int x) {
      return std::max(lo, min(x, hi));
    }

    // Assignment operator
    /*While c++ will provide you with an assignment operator that will do
     *a member wise copy.  For practice you are required to implement this
     *function.*/
    Pixel& operator = (const Pixel&);

    /*FYI:  make sure the math operator does not allow the pixel values to
     *be less than 0 or greater than 255*/
    // Math operators
    Pixel operator + (const Pixel& rhs);
    friend Pixel operator + (const Pixel& lhs, const int rhs);
    Pixel operator - (const Pixel& rhs);
    friend Pixel operator - (const Pixel& lhs, const int rhs);
    friend Pixel operator * (const Pixel& lhs, const uint rhs);
    friend Pixel operator / (const Pixel& lhs, uint rhs);

    // Relational operators
    friend bool operator <  (const Pixel& lhs, const Pixel& rhs);
    friend bool operator <= (const Pixel& lhs, const Pixel& rhs);
    friend bool operator >  (const Pixel& lhs, const Pixel& rhs);
    friend bool operator >= (const Pixel& lhs, const Pixel& rhs);
    friend bool operator == (const Pixel& lhs, const Pixel& rhs);
    friend bool operator != (const Pixel& lhs, const Pixel& rhs);

    /*The output operator should output the pixel values in the following format
     *(redvalue greenvalue bluevalue)*/
    // Output operator
    friend ostream& operator << (ostream&, const Pixel&);

    /*I will provide the implementation for this function. */
    // Input operator
    friend istream& operator >> (istream&, Pixel& p);
};


#endif
