//
// Created by rafab on 10/16/2018.
//

#include "term.h"

term::term(char v) {
    coeff = power = 0; // Initializes coeff and power to 0;
}

term::term(const fraction &c, const fraction &p, const char &v) {
    power = p;
    variable = v;
}