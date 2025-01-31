#include "include/MonteCarloApproximation.h"
#include "include/MachinsFormulaPiApproximation.h"
#include <chrono>
#include <iostream>

using namespace std;

int main() {
    /**
    //Run monte carlo with 10 million iterations
    //2000 bits of precision would be about 600 decimals in base10
    MonteCarloApproximation monteCarloPiApproximator(2000);
    auto start = chrono::high_resolution_clock::now();

    monteCarloPiApproximator.calculate(10000000, 4);
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration
    chrono::duration<double> duration = end - start;

    // Output the time in seconds
    cout << "Execution time: " << duration.count() << " seconds.\n";
     */
    MachinsFormulaPiApproximation machinsFormulaPiApproximator(2000);
    machinsFormulaPiApproximator.calculate(10);
    int digitsSame = machinsFormulaPiApproximator.findAmountCorrectDigitsOfPi();
    cout << digitsSame << endl;
    return 0;
}
