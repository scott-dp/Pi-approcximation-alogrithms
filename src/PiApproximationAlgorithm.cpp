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
    mpf_set_str(piCorrect, "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436", 10); // Base 10 string representation
}

PiApproximationAlgorithm::~PiApproximationAlgorithm() {
    mpf_clear(piApproximated);
    mpf_clear(piCorrect);
}
