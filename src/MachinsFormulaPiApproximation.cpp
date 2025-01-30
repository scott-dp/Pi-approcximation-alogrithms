//
// Created by scott on 30.01.2025.
//
#include <thread>
#include <vector>
#include "../include/MachinsFormulaPiApproximation.h"

using namespace std;

MachinsFormulaPiApproximation::MachinsFormulaPiApproximation(int amountOfBitsPrecision) : PiApproximationAlgorithm(
        amountOfBitsPrecision) {
}

void MachinsFormulaPiApproximation::calculate(int numIterations) {
    vector<thread> workers;
    mpf_t result, *temp, number1, number5, number239, number4, firstFraction, secondFraction;
    mpf_init(result);
    mpf_init(number1);
    mpf_init(number5);
    mpf_init(number239);
    mpf_init(number4);
    mpf_init(firstFraction);
    mpf_init(secondFraction);

    //set the numbers
    mpf_set_si(number4, 4);
    mpf_set_si(number1, 1);
    mpf_set_si(number5, 5);
    mpf_set_si(number239, 239);
    //Set the fractions
    mpf_div(firstFraction, number1, number5);
    mpf_div(secondFraction, number1, number239);

    //Work for first thread
    workers.emplace_back([this, &result, &number4, &firstFraction] {
        mpf_mul(result, number4, *arctanApproximation(firstFraction));
    });

    //Work for second thread
    workers.emplace_back([this, &temp, &secondFraction] {
        temp = arctanApproximation(secondFraction);
    });

    for(auto &t : workers) t.join(); //Make sure all threads finish before continuing execution

    mpf_sub(result, result, *temp);

    //Final calc
    mpf_mul(result, number4, result);

    mpf_clear(*temp); //Deallocate heap allocated memory
}

mpf_t* MachinsFormulaPiApproximation::arctanApproximation(mpf_t theta, int numIterations) {
    return nullptr;
}
