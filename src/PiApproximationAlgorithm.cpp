//
// Created by scott on 29.01.2025.
//
#include <gmp.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "../include/PiApproximationAlgorithm.h"

using namespace std;

PiApproximationAlgorithm::PiApproximationAlgorithm(int amountOfBitsPrecision) {
    if (amountOfBitsPrecision < 1) {
        throw invalid_argument("amount of bit precision cant be 0 or less");
    }
    mpf_set_default_prec(amountOfBitsPrecision); //Set precision to given amount of bits
    mpf_init(piApproximated);
    readPiFromFile();
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
    char *str = mpf_get_str(nullptr, &exponent, 10, 0,
                            piApproximated); //Get the digits of pi as a string to compare to the correct pi string

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

void PiApproximationAlgorithm::readPiFromFile() {
    ifstream file("C:\\Users\\scott\\Documents\\annet\\Pi-approcximation-alogrithms\\resources\\digitsOfPi.txt");

    if (!file) {
        cout<<"error"<<endl;
        //throw std::ios_base::failure("Error opening file");
    }

    string line;
    while (getline(file, line)) {  // Read file line by line
        piCorrect = line;
    }

    file.close();  // Close the file
}
