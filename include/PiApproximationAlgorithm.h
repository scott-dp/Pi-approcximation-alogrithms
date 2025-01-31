//
// Created by scott on 29.01.2025.
//
#include <gmp.h>
#include <string>

#ifndef PIAPPROXIMATION_PIAPPROXIMATIONALGORITHM_H
#define PIAPPROXIMATION_PIAPPROXIMATIONALGORITHM_H

using namespace std;

class PiApproximationAlgorithm {
public:
    explicit PiApproximationAlgorithm(int amountOfBitsPrecision);
    ~PiApproximationAlgorithm();
    void setPiApproximated(mpf_t pi);
    int findAmountCorrectDigitsOfPi();
private:
    string piCorrect;
    mpf_t piApproximated{};
};


#endif //PIAPPROXIMATION_PIAPPROXIMATIONALGORITHM_H
