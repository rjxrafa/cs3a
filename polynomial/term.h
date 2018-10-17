//
// Created by rafab on 10/16/2018.
//

#ifndef UNTITLED17_TERM_H
#define UNTITLED17_TERM_H


#include "fraction.h"

class term {
    public:
        term(char v = 'X');
        term(const fraction &c, const fraction &p = 0, const char &v = ' ');
        ~term();
        term(const term& other);
        term& operator=(const term& other);
        term& operator*=(const term& other);
        term& operator/=(const term& other);
        term& operator+=(const term& other);
        term& operator-=(const term& other);

        friend
        term operator+(const term &x, const term &y);

        friend
        term operator-(const term &x, const term &y);

        friend
        term operator*(const term &x, const term &y);

        friend
        term operator/(const term &x, const term &y);

        friend
        bool operator==(const term &x, const term &y);

        friend
        bool operator!=(const term &x, const term &y);

        friend
        bool operator>=(const term &x, const term &y);

        friend
        bool operator<=(const term &x, const term &y);

        friend
        bool operator>(const term &x, const term &y);

        friend
        bool operator<(const term &x, const term &y);

        friend
        bool operator%=(const term &x, const term &y);

        friend
        std::ostream& operator<<(std::ostream& out, const term& t);

        friend
        std::istream& operator>>(std::istream& out, const term& t);

    private:
        fraction coeff, power;
        char variable;
        void copy(const term &other);
};


#endif //UNTITLED17_TERM_H
