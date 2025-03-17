#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: DivideArrEqParts
// You are given an integer array nums consisting of 2 * n integers.

// You need to divide nums into n pairs such that:

// Each element belongs to exactly one pair.
// The elements present in a pair are equal.
// Return true if nums can be divided into n pairs, otherwise return false.

class DivideArrEqPartsSolution : public Solution {
public:
    // Your solution implementation here
    bool divideArray(std::vector<int>& nums) {
        std::vector<int> counts(500);
        for (const auto& num: nums) {
            counts[num]++;
        }
        for (const auto& count: counts) {
            if (count % 2) return false;
        }
        return true;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for DivideArrEqParts..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new DivideArrEqPartsSolution();
}
#endif
