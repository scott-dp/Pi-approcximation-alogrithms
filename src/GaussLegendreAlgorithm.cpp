//
// Created by scott on 03.02.2025.
//
#include <thread>
#include "../include/GaussLegendreAlgorithm.h"

using namespace std;

GaussLegendreAlgorithm::GaussLegendreAlgorithm(int amountOfBitsPrecision) : PiApproximationAlgorithm(
        amountOfBitsPrecision) {
}

void GaussLegendreAlgorithm::calculate(int numIterations) {
    mpf_t a, b, p, t, aCopy, temp;
    mpf_init(aCopy);
    mpf_init(temp);
    mpf_init(a);
    mpf_init(b);
    mpf_init(p);
    mpf_init(t);
    //Set values
    mpf_set_si(a, 2);//Set 'a' to 2 to be used ad param for sqrt(2) approximation
    squareRootApproximation(b, 1.5, numIterations*2, a); //set b to sqrt(2)
    mpf_set_si(a, 1);//Set 'a' to its correct value
    mpf_set_si(p, 1);
    mpf_set_d(t, 0.25); //Set t to 1/4
    mpf_div(b, a, b); //Set b to 1/sqrt(2)

    for (int i = 0; i < numIterations; ++i) {
        mpf_set(aCopy, a);
        mpf_add(temp, aCopy, b);
        mpf_div_ui(a, temp, 2); // a n+1 = (a_n + b_n)/2
        mpf_mul(temp, aCopy, b); //temp = a*b, radicand for square root calculation
        squareRootApproximation(b, 1, numIterations*2, temp); //b = sqrt(a*b)
        mpf_sub(temp, aCopy, a); //temp = a_n - a_n+1
        mpf_mul(temp, temp, temp); //temp = temp*temp
        mpf_mul(temp, p, temp);
        mpf_sub(t, t, temp);
        mpf_mul_ui(p, p, 2); // p = p*2
    }
    mpf_add(temp, a, b);
    mpf_mul(temp, temp, temp);
    mpf_mul_ui(t, t, 4);
    mpf_div(temp, temp, t);
    setPiApproximated(temp);


}

void GaussLegendreAlgorithm::squareRootApproximation(mpf_t &result, double initialGuess, int numIterations, mpf_t radicand) {
    mpf_t x, number2, temp;
    mpf_init(x);
    mpf_init(number2);
    mpf_init(temp);

    mpf_set_si(number2, 2);
    mpf_set_d(x, initialGuess);

    for (int i = 0; i < numIterations; ++i) {
        mpf_div(temp, radicand, x);
        mpf_add(x, x, temp);
        mpf_div(x, x, number2);
    }

    mpf_set(result, x);
}

