//
// Created by scott on 30.01.2025.
//
#include "PiApproximationAlgorithm.h"

#ifndef PIAPPROXIMATION_MACHINSFORMULAPIAPPROXIMATION_H
#define PIAPPROXIMATION_MACHINSFORMULAPIAPPROXIMATION_H


class MachinsFormulaPiApproximation: public PiApproximationAlgorithm {
public:
    explicit MachinsFormulaPiApproximation(int amountOfBitsPrecision);
    void calculate(int numIterations);
    mpf_t* arctanApproximation(mpf_t theta, int numIterations);
};


#endif //PIAPPROXIMATION_MACHINSFORMULAPIAPPROXIMATION_H
