#include "include/MonteCarloApproximation.h"

using namespace std;

int main() {
    //Run monte carlo with 10 million iterations
    //2000 bits of precision would be about 600 decimals in base10
    MonteCarloApproximation monteCarloPiApproximator(2000, 10000000, 4);
    monteCarloPiApproximator.calculate();
    return 0;
}
