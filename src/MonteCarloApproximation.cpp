//
// Created by scott on 29.01.2025.
//
#include <cmath>
#include "../include/MonteCarloApproximation.h"
using namespace std;

MonteCarloApproximation::MonteCarloApproximation(int amountOfBitsPrecision, int numIterations, int numThreads) :
        PiApproximationAlgorithm(amountOfBitsPrecision) {
    //Set numThreads to the amount of available cores on computer, for instance I have 4
    this->numThreads = numThreads;
    this->numIterations = numIterations;
}

void MonteCarloApproximation::calculate() {
    //The simple but slow monte carlo approach
    random_device rd;
    mt19937 gen(rd());  // Random number engine
    uniform_real_distribution<> distrib(-1.0, 1.0);

    int numPointsInsideCircle = 0;
    double x, y;
    for(int i = 0; i < numIterations; ++i) {
        x = distrib(gen);
        y = distrib(gen);
        if ((pow(x, 2) + pow(y, 2)) <= 1) {
            numPointsInsideCircle++;
        }
    }

    mpf_t fraction, iterationsMpf, numPointsInsideCircleMpf, number4, result;
    mpf_init(fraction);
    mpf_init(iterationsMpf);
    mpf_init(numPointsInsideCircleMpf);
    mpf_init(result);
    mpf_init(number4);

    //Make a mpf type of the needed variables to do calculations with them
    mpf_set_si(iterationsMpf, numIterations);
    mpf_set_si(numPointsInsideCircleMpf, numPointsInsideCircle);
    mpf_set_si(number4, 4);
    mpf_div(fraction, numPointsInsideCircleMpf, iterationsMpf); //Calculate the fraction
    mpf_mul(result, number4, fraction); //Calculate the final result
    mpf_out_str(stdout, 10, 0, result);
}
