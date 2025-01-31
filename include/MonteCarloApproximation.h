//
// Created by scott on 29.01.2025.
//
#include "PiApproximationAlgorithm.h"
#include <random>

#ifndef PIAPPROXIMATION_MONTECARLOAPPROXIMATION_H
#define PIAPPROXIMATION_MONTECARLOAPPROXIMATION_H


class MonteCarloApproximation: public PiApproximationAlgorithm {
public:
    explicit MonteCarloApproximation(int amountOfBitsPrecision);
    void calculate(int numIterations, int numThreads);
private:
    int numIterations;
    int numThreads;
};


#endif //PIAPPROXIMATION_MONTECARLOAPPROXIMATION_H
