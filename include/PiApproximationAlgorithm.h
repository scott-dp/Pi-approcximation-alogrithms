//
// Created by scott on 29.01.2025.
//
#include <gmp.h>

#ifndef PIAPPROXIMATION_PIAPPROXIMATIONALGORITHM_H
#define PIAPPROXIMATION_PIAPPROXIMATIONALGORITHM_H


class PiApproximationAlgorithm {
public:
    explicit PiApproximationAlgorithm(int amountOfBitsPrecision);
    ~PiApproximationAlgorithm();
private:
    mpf_t piCorrect{};
    mpf_t piApproximated{};
};


#endif //PIAPPROXIMATION_PIAPPROXIMATIONALGORITHM_H
