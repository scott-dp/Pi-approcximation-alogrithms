#include "include/MonteCarloApproximation.h"
#include <chrono>
#include <iostream>

using namespace std;

int main() {
    //Run monte carlo with 10 million iterations
    //2000 bits of precision would be about 600 decimals in base10
    MonteCarloApproximation monteCarloPiApproximator(2000, 10000000, 4);
    auto start = chrono::high_resolution_clock::now();

    monteCarloPiApproximator.calculate();
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = end - start;

    // Output the time in seconds
    cout << "Execution time: " << duration.count() << " seconds.\n";
    return 0;
}
