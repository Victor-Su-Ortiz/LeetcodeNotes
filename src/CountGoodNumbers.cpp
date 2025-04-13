#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: CountGoodNumbers
// Description: [PROBLEM_DESCRIPTION]
using namespace std;
class CountGoodNumbersSolution : public Solution {
public:
    // Your solution implementation here
    int MOD = 1e9 + 7;
    long long power(long long expo, long long base) {
        long long res = 1;
        while (expo > 0) {
            if (expo % 2) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        return power(n/2, 4) * power((n + 1) / 2, 5) % MOD;

    }
    void run() override {
        // Test cases
        std::cout << "Running test cases for CountGoodNumbers..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new CountGoodNumbersSolution();
}
#endif
