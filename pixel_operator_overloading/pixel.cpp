#include "Pixel.h"


uint8_t& Pixel::getR () {
    return this->R;
}

uint8_t& Pixel::getG () {
    return this->G;
}

uint8_t& Pixel::getB () {
    return this->B;
}


// Output
ostream& operator<< (ostream& out, const Pixel& p) {
    return out << (uint&)p.R << (uint&)p.G << (uint&)p.B;
}

// Input
istream& operator >> (istream& in, Pixel& p) {
  return in >> (uint&)p.R >> (uint&)p.G >> (uint&)p.B;
}

// Assignment
Pixel& Pixel::operator= (const Pixel& rhs) {
    this->R = rhs.R;
    this->G = rhs.G;
    this->B = rhs.B;

    return *this;
}

//Add two pixels//
Pixel Pixel::operator + (const Pixel& rhs) {
    int hi = 255;
    int lo = 0;

    Pixel retPix(Pixel::clamp(lo, hi, (int)this->R + (int)rhs.R),
                 Pixel::clamp(lo, hi, (int)this->G + (int)rhs.G),
                 Pixel::clamp(lo, hi, (int)this->B + (int)rhs.B));


    return retPix;
}

//Add a pixel and an integer//
Pixel operator + (const Pixel& lhs, const int rhs) {
    int hi = 255;
    int lo = 0;

    Pixel retPix(Pixel::clamp(lo, hi, (int)lhs.R + rhs),
                 Pixel::clamp(lo, hi, (int)lhs.G + rhs),
                 Pixel::clamp(lo, hi, (int)lhs.B + rhs));

    return retPix;
}

//Subtracting two pixels//
Pixel Pixel::operator - (const Pixel& rhs) {
    int hi = 255;
    int lo = 0;

    Pixel retPix(Pixel::clamp(lo, hi, (int)this->R - (int)rhs.R),
                 Pixel::clamp(lo, hi, (int)this->G - (int)rhs.G),
                 Pixel::clamp(lo, hi, (int)this->B - (int)rhs.B));

    return retPix;
}

//Subtract a pixel from an integer//
Pixel operator - (const Pixel& lhs, const int rhs) {
    int hi = 255;
    int lo = 0;

    Pixel retPix(Pixel::clamp(lo, hi, (int)lhs.R - rhs),
                 Pixel::clamp(lo, hi, (int)lhs.G - rhs),
                 Pixel::clamp(lo, hi, (int)lhs.B - rhs));

    return retPix;
}

Pixel operator * (const Pixel& lhs, const uint rhs) {
    int hi = 255;
    int lo = 0;

    Pixel retPix(Pixel::clamp(lo, hi, (int)lhs.R * (int)rhs),
                 Pixel::clamp(lo, hi, (int)lhs.G * (int)rhs),
                 Pixel::clamp(lo, hi, (int)lhs.B * (int)rhs));


    return retPix;
}

Pixel operator / (const Pixel& lhs, const uint rhs) {
    int hi = 255;
    int lo = 0;

    Pixel retPix(Pixel::clamp(lo, hi, (int)lhs.R / (int)rhs),
                 Pixel::clamp(lo, hi, (int)lhs.G / (int)rhs),
                 Pixel::clamp(lo, hi, (int)lhs.B / (int)rhs));

    return retPix;
}

bool operator <  (const Pixel& lhs, const Pixel& rhs) {

    if(((int)lhs.R < (int)rhs.R) ||
      ((int)lhs.G < (int)rhs.G) ||
      ((int)lhs.B < (int)rhs.B))  {
        return true;
    }
    else {
        return false;
    }
}

bool operator == (const Pixel& lhs, const Pixel& rhs) {
    if(((int)lhs.R == (int)rhs.R) ||
      ((int)lhs.G == (int)rhs.G) ||
      ((int)lhs.B == (int)rhs.B))  {
        return true;
    }
    else {
        return false;
    }
}

bool operator >  (const Pixel& lhs, const Pixel& rhs) {
    return rhs < lhs;
}
bool operator <= (const Pixel& lhs, const Pixel& rhs) {
    return rhs > lhs || rhs == lhs;
}
bool operator >= (const Pixel& lhs, const Pixel& rhs) {
    return rhs < lhs || rhs == lhs;
}
bool operator != (const Pixel& lhs, const Pixel& rhs) {
    return !(rhs == lhs);
}
