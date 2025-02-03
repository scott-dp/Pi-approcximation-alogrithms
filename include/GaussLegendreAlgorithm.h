//
// Created by scott on 03.02.2025.
//
#include "PiApproximationAlgorithm.h"

#ifndef PIAPPROXIMATION_GAUSSLEGENDREALGORITHM_H
#define PIAPPROXIMATION_GAUSSLEGENDREALGORITHM_H

class GaussLegendreAlgorithm: public PiApproximationAlgorithm {
public:
    explicit GaussLegendreAlgorithm(int amountOfBitsPrecision);
    void calculate(int numIterations);
    void squareRootApproximation(mpf_t &result, double initialGuess, int numIterations, mpf_t radicand);
};

#endif //PIAPPROXIMATION_GAUSSLEGENDREALGORITHM_H
