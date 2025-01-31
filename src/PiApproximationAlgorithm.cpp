//
// Created by scott on 29.01.2025.
//
#include <gmp.h>
#include <cstdlib>
#include <iostream>
#include "../include/PiApproximationAlgorithm.h"

using namespace std;

PiApproximationAlgorithm::PiApproximationAlgorithm(int amountOfBitsPrecision) {
    if (amountOfBitsPrecision < 1) {
        throw invalid_argument("amount of bit precision cant be 0 or less");
    }
    mpf_set_default_prec(amountOfBitsPrecision); //Set precision to given amount of bits
    mpf_init(piApproximated);
    piCorrect = "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436";
}

PiApproximationAlgorithm::~PiApproximationAlgorithm() {
    mpf_clear(piApproximated);
}

void PiApproximationAlgorithm::setPiApproximated(__mpf_struct *pi) {
    mpf_set(piApproximated, pi);
}

int PiApproximationAlgorithm::findAmountCorrectDigitsOfPi() {
    mp_exp_t exponent;
    //Get the approximated pi as string
    char* str = mpf_get_str(nullptr, &exponent, 10, 0, piApproximated); //Get the digits of pi as a string to compare to the correct pi string

    //Find position where approximated and correct pi differ and return
    for (int i = 0; i < piCorrect.length(); i++) {
        if (str[i] != piCorrect[i]) {
            free(str);
            return i;
        }
    }
    free(str);
    //More or equal amount correct digits than the solution contains
    return piCorrect.length();
}
