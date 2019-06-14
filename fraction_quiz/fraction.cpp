#include "fraction.h"

namespace cs3a {

Fraction::Fraction() : numerator_(0),
                       denominator_(1) {}

Fraction::Fraction(int numerator, int denominator) {
  SetValues(numerator, denominator);
}

Fraction::~Fraction() {
  numerator_ = denominator_ = 0;
}

Fraction::Fraction(const Fraction &frac) {
  numerator_   = frac.numerator_;
  denominator_ = frac.denominator_;
}

Fraction::Fraction(const double &other) {
  std::string whole, fraction;
  std::stringstream ss;
  ss << other;
  getline(ss,whole,'.');
  getline(ss,fraction);
  int num_digits = fraction.size();
  denominator_ = CreateDenominator(num_digits, IsRepeating(fraction));
  numerator_ = denominator_ * std::stoi(whole) + std::stoi(fraction) - (int) IsRepeating(fraction);
  Reduce();
}

/**
 * This function checks for repeating decimals from a given fraction.
 * @param fraction
 * @return
 */
bool Fraction::IsRepeating(const std::string &fraction) {
  bool yes = true;
  for(int i = 1; yes && i < fraction.size()-1; ++i)
    yes = (fraction[0] == fraction[i]);
  return yes;
}

/**
 * Creates a denominator given an integer representing number of places. Subtracts one to represent
 * a repeating fractional part.
 * @param digits
 * @param same
 * @return
 */
int Fraction::CreateDenominator(int digits, bool same){
  std::string result("1");
  for(int i = 0; i < digits; ++i)
    result += "0";
  return std::stoi(result) - (int)same;
}

Fraction& Fraction::operator=(const Fraction &frac) {
  if(this != &frac) {
    numerator_ = frac.numerator_;
    denominator_ = frac.denominator_;
  }
  return *this;
}

Fraction& Fraction::operator+=(const Fraction &other) {
  *this = *this + other;
  return *this;
}

Fraction& Fraction::operator-=(const Fraction &other) {
  *this = *this - other;
  return *this;
}

Fraction& Fraction::operator*=(const Fraction &other) {
  *this = *this * other;
  return *this;
}

Fraction& Fraction::operator/=(const Fraction &other) {
  *this = *this / other;
  return *this;
}

void Fraction::SetValues(int numerator, int denominator) {
  numerator_ = numerator;
  denominator_ = denominator;
  Reduce();
}

void Fraction::Display(std::ostream &out) {
  out <<" "<<numerator_;
  if(denominator_ != 1)
    out <<"/"<<denominator_<<" ";
}

void Fraction::GetInput() {
  char junk;
  std::cin>>numerator_>>junk>>denominator_;
  Reduce();
}

void Fraction::Reduce() {
  bool neg = numerator_ < 0 || denominator_ < 0,
       both = numerator_ < 0 && denominator_ < 0;
  int divisor = GCD(abs(numerator_), abs(denominator_));

  numerator_ = abs(numerator_) / divisor;
  denominator_ = abs(denominator_) / divisor;

  if(!both && neg) //Asking is both == false
    numerator_ *= -1;
}


int Fraction::GCD(int p, int q) {
/*
 *  Remainder Theorem
 *
 *  P = nQ + R;
 *
 * 36 = (1)(24) + 12  Question, is 12 == 0?
 * 24 = (2)(12) + 0   If no, move Q into P, and R into Q and continue
 *                    until R == 0;
 * If R == 0, that means Q is the GCD of the original numbers provided
 *
 */
  return !q ? p : GCD(q, p % q);  //!q is the same as asking q == 0;
}

}
