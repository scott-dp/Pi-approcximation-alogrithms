#include "include/MonteCarloApproximation.h"
#include "include/MachinsFormulaPiApproximation.h"
#include "include/GaussLegendreAlgorithm.h"
#include <chrono>
#include <iostream>

using namespace std;
void testMonteCarloApproximation(int amountBitsPrecision, int iterations);
void testMachinsFormulaApproximation(int amountBitsPrecision, int iterations);
void testGaussLegendreApproximation(int amountBitsPrecision, int iterations);

int main() {
    //testMonteCarloApproximation(200, 1000000);
    testMachinsFormulaApproximation(10000, 1700);
    testGaussLegendreApproximation(10000, 11);
    return 0;
}

void testMonteCarloApproximation(int amountBitsPrecision, int iterations) {
    //Run monte carlo with 10 million iterations
    //2000 bits of precision would be about 600 decimals in base10
    MonteCarloApproximation monteCarloPiApproximator(amountBitsPrecision);
    auto start = chrono::high_resolution_clock::now();

    monteCarloPiApproximator.calculate(iterations, 4);
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = end - start;
    // Output the time in seconds
    cout << "Execution time monte carlo: " << duration.count() << " seconds.\n";
    cout << "Monte carlo amount of correct digits: " << monteCarloPiApproximator.findAmountCorrectDigitsOfPi() <<endl;
}

void testMachinsFormulaApproximation(int amountBitsPrecision, int iterations) {
    //With 100 000 bits of precision and 10 000 iterations i got 20k correct digits of pi with this fomrula
    MachinsFormulaPiApproximation machinsFormulaPiApproximator(amountBitsPrecision);
    auto start = chrono::high_resolution_clock::now();
    machinsFormulaPiApproximator.calculate(iterations);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Execution time machins formula: " << duration.count() << " seconds.\n";
    cout << "Machins formula amount of correct digits: " << machinsFormulaPiApproximator.findAmountCorrectDigitsOfPi() << endl;
}

void testGaussLegendreApproximation(int amountBitsPrecision, int iterations) {
    GaussLegendreAlgorithm gaussLegendreApproximator(amountBitsPrecision);
    auto start = chrono::high_resolution_clock::now();
    gaussLegendreApproximator.calculate(iterations);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Execution time Gauss Legendre method: " << duration.count() << " seconds.\n";
    cout << "Gauss Legendre method amount of correct digits: " << gaussLegendreApproximator.findAmountCorrectDigitsOfPi() << endl;
}