#include "fraction_quiz.h"

namespace cs3a {
FractionQuiz::FractionQuiz() {
  srand(time(nullptr));
  std::string name;
  std::cout << "What is your name?";
  getline(std::cin, name);
  fflush(stdin);
  std::cout << "How many times do you want to play?";

  int numQ = 0; // number of questions
  while (!(std::cin >> numQ) && numQ < 1)
    std::cout << "Enter a valid number: ";

  for (unsigned int i = 0; i < numQ; ++i)
    score_ += PlayRound();

  std::cout << "\nYour score: " << score_ << '\n';

}

FractionQuiz::~FractionQuiz() = default;


Fraction FractionQuiz::RandomFraction() {
  int numerator   = rand()%24+1,
      denominator = rand()%24+2;

  return Fraction(numerator,denominator);
}

char FractionQuiz::RandomOperator() {
  char arr[4] = {'+','-','/','*'};
  return (*(arr+rand()%4));
}

int FractionQuiz::PlayRound() {

  operator_ = RandomOperator();
  fraction1_ = RandomFraction();
  fraction2_ = RandomFraction();

  std::cout << fraction1_ << " " << operator_ << " " << fraction2_ << " =\n";
  std::cin >> answer_;

  if (answer_ == Output(fraction1_, fraction2_, operator_)) {
    if (answer_.GetNumerator() == Output(fraction1_, fraction2_, operator_).GetNumerator()) {
      std:: cout << "Right on! The answer was exactly " << Output(fraction1_, fraction2_,operator_) << '\n';
      return 2;
    }
    std:: cout << "Good job! The reduced answer is: " << Output(fraction1_, fraction2_,operator_) << '\n';
    return 1;
  } else {
    std::cout << "Sorry, the answer was: " << Output(fraction1_, fraction2_,operator_) << '\n';
    return 0;
  }
}


Fraction FractionQuiz::Output(const Fraction &x, const Fraction &y, char operation) {
  Fraction z;
  switch(operation)
  {
    case '+' : z = x + y;
      break;
    case '-' : z = x - y;
      break;
    case '*' : z = x * y;
      break;
    case '/' : z = x / y;
      break;
    default:
      return z = 0;
  }
  return z;
}
} // end namespace cs3a


/*
What is your name?
rafa
How many times do you want to play?
3
5/24 / 1 =
10/24
Sorry, the answer was: 5/24
2 * 1/6 =
4/12
Good job! The reduced answer is: 1/3
23/24 * 1/3 =
23/72
Right on! The answer was exactly 23/72

Your score: 3
*/