#include <iostream>
#include "include/MonteCarloApproximation.h"
using namespace std;
int main() {
    MonteCarloApproximation monteCarloPiApproximator(2000, 1000, 0);
    monteCarloPiApproximator.calculate();
    return 0;
}
