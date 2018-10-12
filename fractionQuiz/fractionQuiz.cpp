//
// Created by rafab on 10/9/2018.
//

#include "fractionQuiz.h"

fractionQuiz::fractionQuiz() {

    srand(time(0));
    std::string name;
    std::cout << "What is your name?";
    getline(std::cin, name);
    std::cout << "How many times do you want to play?";

    int numQ = 0; // number of questions
    while (!(std::cin >> numQ) && numQ < 1)
        std::cout << "Enter a valid number: ";

    for (unsigned int i = 0; i < numQ; ++i)
    {
        score += playRound();
    }

    std::cout << "\nYour score: " << score;

}

fractionQuiz::~fractionQuiz() {

}

fractionQuiz::fractionQuiz(int numQ) {

}

fraction fractionQuiz::randomFraction() {

    int n = rand()%24+1;
    int d = rand()%24+2;

    return fraction(n,d);
}

char fractionQuiz::randomOperator() {
    char arr[4] = {'+','-','/','*'};

    return (*(arr+rand()%4));
}

int fractionQuiz::playRound() {

    op = randomOperator();
    fraction1 = randomFraction();
    fraction2 = randomFraction();

    std::cout << fraction1 << " " << op << " " << fraction2 << " =\n";
    std::cin >> ans;

    if (ans == output(fraction1,fraction2,op)) {
        if (ans.getNum() == output(fraction1,fraction2,op).getNum())
        {
            std:: cout << "Right on! The answer was exactly " << output(fraction1,fraction2,op) << std::endl;
            return 2;
        }
        std:: cout << "Good job! The reduced answer is: " << output(fraction1,fraction2,op) << std::endl;
        return 1;
    } else {
        std::cout << "Sorry, the answer was: " << output(fraction1,fraction2,op) << std::endl;
        return 0;
    }
}


fraction fractionQuiz::output(fraction x, fraction y, char op)
{
    fraction z;
    switch(op)
    {
        case '+' : z = x + y;
            break;
        case '-' : z = x - y;
            break;
        case '*' : z = x * y;
            break;
        case '/' : z = x / y;
    }
    return z;
}

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
Process finished with exit code 0
*/