/**
 * This program is a Fraction quiz designed to test the Fraction implementation.
  */

#ifndef CS003A_FRACTIONQUIZ_H
#define CS003A_FRACTIONQUIZ_H

#include <iostream>
#include "fraction.h"

namespace cs3a {
class FractionQuiz {
 public:
  FractionQuiz();
  ~FractionQuiz();

 private:
  unsigned int score_ = 0;
  Fraction fraction1_;
  Fraction fraction2_;
  Fraction answer_;
  char operator_;

  Fraction RandomFraction();
  char RandomOperator();
  int PlayRound();
  Fraction Output(const Fraction &x, const Fraction &y, char operation);

};
}


#endif //CS003A_FRACTIONQUIZ_H
