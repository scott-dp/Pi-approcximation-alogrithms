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
    mpf_init(piCorrect);
    mpf_set_str(piCorrect, "3.141592653589793238462643383279502884197169399375105820974944", 10); // Base 10 string representation
}

PiApproximationAlgorithm::~PiApproximationAlgorithm() {
    mpf_clear(piApproximated);
    mpf_clear(piCorrect);
}
