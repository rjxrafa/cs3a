//
// Created by rafab on 10/9/2018.
//

#ifndef UNTITLED16_FRACTIONQUIZ_H
#define UNTITLED16_FRACTIONQUIZ_H

#include <iostream>
#include "fraction.h"
#include <string>

class fractionQuiz {

    public:
        fractionQuiz();
        ~fractionQuiz();
        // fractionQuiz(int numQ);

    private:
        unsigned int score = 0;
        fraction fraction1;
        fraction fraction2;
        fraction ans;
        char op;

        fraction randomFraction();
        char randomOperator();
        int playRound();
        fraction output(fraction x, fraction y, char op);

};


#endif //UNTITLED16_FRACTIONQUIZ_H
