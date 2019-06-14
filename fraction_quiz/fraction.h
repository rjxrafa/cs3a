/**
 * This is an Fraction implementation using two separate integers to hold numerator and denominator values.
 * This class is mostly adapted from its lecture source, Paul J. Wilkinson.
 *
 * @author      Rafael Betita
 * @modified    2019-06-13
 */

#ifndef CS003A_FRACTION_H
#define CS003A_FRACTION_H

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <limits>

namespace cs3a {
class Fraction {
 public:

  Fraction();
  ~Fraction();
  Fraction(int numerator, int denominator = 1);
  Fraction(const Fraction &Fraction); // Fraction -> Fraction
  Fraction(const double &other);      // Double -> Fraction

  /** Assignment operators **/
  Fraction& operator=(const Fraction &Fraction);
  Fraction& operator+=(const Fraction &Fraction);
  Fraction& operator-=(const Fraction &Fraction);
  Fraction& operator*=(const Fraction &Fraction);
  Fraction& operator/=(const Fraction &Fraction);

  /** Accessors **/
  int GetNumerator() const {return numerator_;}     // accessor function for numerator
  int GetDenominator() const {return denominator_;} // accessor function for denominator
  void Display(std::ostream &out = std::cout);

  /** Modifiers **/
  void SetValues(int numerator, int denominator = 1); // mutator function
  void Reduce();
  void GetInput();

  friend
  std::ostream& operator<<(std::ostream& out, const Fraction &frac);

  friend
  std::istream& operator>>(std::istream& out, Fraction &frac);

  friend
  Fraction operator+(const Fraction &x,const Fraction &y);

  friend
  Fraction operator-(const Fraction &x,const Fraction &y);

  friend
  Fraction operator*(const Fraction &x,const Fraction &y);

  friend
  Fraction operator/(const Fraction &x,const Fraction &y);

  friend
  bool operator==(const Fraction &x,const Fraction &y);

  friend
  bool operator>=(const Fraction &x,const Fraction &y);

  friend
  bool operator<=(const Fraction &x,const Fraction &y);

  friend
  bool operator!=(const Fraction &x,const Fraction &y);

  friend
  bool operator<(const Fraction &x,const Fraction &y);

  friend
  bool operator>(const Fraction &x,const Fraction &y);

 private:
  int numerator_,
      denominator_;

  int GCD(int p, int q);

  bool IsRepeating(const std::string &fraction);
  int CreateDenominator(int digits, bool same);
};

} // end namespace cs3a


#endif // FRACTION_H
#endif //CS003A_FRACTION_H
