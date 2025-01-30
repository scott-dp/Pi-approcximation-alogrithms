//
// Created by scott on 29.01.2025.
//
#include <atomic>
#include <thread>
#include <iostream>
#include "../include/MonteCarloApproximation.h"

using namespace std;

MonteCarloApproximation::MonteCarloApproximation(int amountOfBitsPrecision, int numIterations, int numThreads) :
        PiApproximationAlgorithm(amountOfBitsPrecision) {
    //Set numThreads to the amount of available cores on computer, for instance I have 4
    if (numThreads < 1 || numIterations < 1) {
        throw invalid_argument("number of threads and iterations cant be less than 1");
    }
    this->numThreads = numThreads;
    this->numIterations = numIterations;
}

void MonteCarloApproximation::calculate() {
    //The simple but slow monte carlo approach, I try to increase speed by using threads
    vector<thread> workers;
    int numIterationsPerThread = numIterations / numThreads;
    atomic<int> numPointsInsideCircle = 0;

    // Random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distrib(-1.0, 1.0); //generates uniformly between -1 and 1, including the edges

    for (int i = 0; i < numThreads; ++i) {
        //let 4 threads divide the work between themselves, is faster than 1 thread
        workers.emplace_back([&gen, &distrib, numIterationsPerThread, &numPointsInsideCircle] {
            double x, y;
            int localNumPointsInCircle = 0;
            //step 1 and 2 of algorithm
            for(int i = 0; i < numIterationsPerThread; ++i) {
                x = distrib(gen);
                y = distrib(gen);
                if ((x*x + y*y) <= 1) {
                    localNumPointsInCircle++;
                }
            }
            numPointsInsideCircle += localNumPointsInCircle;
        });
    }

    for (auto &t : workers) t.join();

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
    mpf_out_str(stdout, 10, 0, result); //print result in base10
}
