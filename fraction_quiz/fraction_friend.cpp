#include "Fraction.h"

namespace cs3a {

std::ostream& operator<<(std::ostream& out, const Fraction &frac) {
  out << frac.numerator_;
  if(frac.denominator_ != 1)
    out<<"/"<<frac.denominator_;
  return out;
}

std::istream& operator>>(std::istream& in, Fraction &frac) {
  char junk;
  std::stringstream ss;
  std::string possibleFraction;
  if(&in == &std::cin) { // This means that the program is reading from the console
    if(in>>possibleFraction) {
      ss<<possibleFraction;
      ss>>frac;
    }
  } else {
    if(in>>frac.numerator_) {
      if(in.peek() == '/')
        in>>junk>>frac.denominator_;
    }
  }
  return in;
}

Fraction operator+(const Fraction &x,const Fraction &y) {
  Fraction result;
  int numerator_ = x.numerator_ * y.denominator_ + y.numerator_  * x.denominator_,
      denominator_ = x.denominator_ * y.denominator_;
  result.SetValues(numerator_, denominator_);
  return result;
}

Fraction operator-(const Fraction &x,const Fraction &y) {
  Fraction result;
  int numerator_ = x.numerator_ * y.denominator_ - y.numerator_  * x.denominator_,
      denominator_ = x.denominator_ * y.denominator_;
  result.SetValues(numerator_, denominator_);
  return result;
}

Fraction operator*(const Fraction &x,const Fraction &y) {
  Fraction result;
  int numerator_ = x.numerator_ * y.numerator_,
      denominator_ = x.denominator_ * y.denominator_;
  result.SetValues(numerator_, denominator_);
  return result;
}

Fraction operator/(const Fraction &x,const Fraction &y) {
  Fraction result;
  int numerator_ = x.numerator_ * y.denominator_,
      denominator_ = x.denominator_ * y.numerator_;
  result.SetValues(numerator_, denominator_);
  return result;
}


bool operator==(const Fraction &x,const Fraction &y) {
  return x.numerator_ * y.denominator_ == y.numerator_ * x.denominator_;
}

bool operator>=(const Fraction &x,const Fraction &y) {
  return x.numerator_ * y.denominator_ >= y.numerator_ * x.denominator_;
}

bool operator<=(const Fraction &x,const Fraction &y) {
  return x.numerator_ * y.denominator_ <= y.numerator_ * x.denominator_;
}

bool operator!=(const Fraction &x,const Fraction &y) {
  return x.numerator_ * y.denominator_ != y.numerator_ * x.denominator_;
}

bool operator<(const Fraction &x,const Fraction &y) {
  return x.numerator_ * y.denominator_ < y.numerator_ * x.denominator_;
}

bool operator>(const Fraction &x,const Fraction &y) {
  return x.numerator_ * y.denominator_ > y.numerator_ * x.denominator_;
}


} // end namespace cs3a
