//
// Created by scott on 30.01.2025.
//
#include <thread>
#include <vector>
#include <iostream>
#include "../include/MachinsFormulaPiApproximation.h"

using namespace std;

MachinsFormulaPiApproximation::MachinsFormulaPiApproximation(int amountOfBitsPrecision) : PiApproximationAlgorithm(
        amountOfBitsPrecision) {
}

void MachinsFormulaPiApproximation::calculate(int numIterations) {
    mpf_set_default_prec(500);
    vector<thread> workers;
    mpf_t result, number1, number5, number239, number4, firstFraction, secondFraction, firstArctanApproximation, secondArctanApproximation;
    mpf_init(result);
    mpf_init(number1);
    mpf_init(number5);
    mpf_init(number239);
    mpf_init(number4);
    mpf_init(firstFraction);
    mpf_init(secondFraction);
    mpf_init(firstArctanApproximation);
    mpf_init(secondArctanApproximation);
    //set the numbers
    mpf_set_si(number4, 4);
    mpf_set_si(number1, 1);
    mpf_set_si(number5, 5);
    mpf_set_si(number239, 239);
    //Set the fractions
    mpf_div(firstFraction, number1, number5);
    mpf_div(secondFraction, number1, number239);

    //Work for first thread
    workers.emplace_back([this, &firstArctanApproximation, &firstFraction, &numIterations] {
        eulersArctanApproximation(firstFraction, numIterations, firstArctanApproximation);
    });

    //Work for second thread
    workers.emplace_back([this, &secondArctanApproximation, &secondFraction, &numIterations] {
        eulersArctanApproximation(secondFraction, numIterations, secondArctanApproximation);
    });

    for(auto &t : workers) t.join(); //Make sure all threads finish before continuing execution

    mpf_mul(result, number4, firstArctanApproximation);
    mpf_sub(result, result, secondArctanApproximation);
    //Final calc
    mpf_mul(result, number4, result);
    setPiApproximated(result);
}

void MachinsFormulaPiApproximation::eulersArctanApproximation(mpf_t &x, int numIterations, mpf_t &result) {
    mpf_set_default_prec(500);
    mpf_t estimate, temp, xSquared;
    mpf_init(estimate);
    mpf_init(temp);
    mpf_init(xSquared);
    mpf_set_si(estimate, numIterations*2 + 1);
    mpf_mul(xSquared, x, x);//Square x


    for (int i = numIterations; i > 0; i--) {
        int oddNumber = 2*i - 1;
        int iSquared = (i*i); //To multiply with x^2/estimate

        mpf_div(temp, xSquared, estimate);//set temp to x^2/estimate
        // multiply by i^2
        mpf_set_si(estimate, iSquared);
        mpf_mul(estimate, estimate, temp);//estimate = i^2*(x^2/estimate)
        // add odd number
        mpf_set_si(temp, oddNumber);
        mpf_add(estimate, estimate, temp); //estimate = oddNumber + i^2*(x^2/estimate)

    }
    mpf_div(estimate, x, estimate); //Estimate = x/estimate
    mpf_set(result, estimate); //set the result to the calculated arctan value
}