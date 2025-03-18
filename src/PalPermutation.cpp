#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: PalPermutation
// Description: [PROBLEM_DESCRIPTION]

class PalPermutationSolution : public Solution {
public:
    // Your solution implementation here
    bool canPermutePalindrome(std::string s) {
        std::vector<int> counts(26);
        for (const auto& c: s) {
            counts[c - 'a']++;
        }
        bool odd = false;
        for (const auto& count: counts) {
            if (count %2) {
                if (odd) return false;
                odd = true;
            }
        }
        return true;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for PalPermutation..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        std::string params = "racecar";
        auto result = canPermutePalindrome(params);
        std::cout << "Output: " << std::boolalpha << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new PalPermutationSolution();
}
#endif
