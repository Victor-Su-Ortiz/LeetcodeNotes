#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: MinOpToMakeBinOne
// Description: [PROBLEM_DESCRIPTION]

class MinOpToMakeBinOneSolution : public Solution {
public:
    // Your solution implementation here
    int minOperations(std::vector<int>& nums) {
        int count = 0;
        size_t n = nums.size();
        for (size_t i = 0; i < n - 2; i++) {
            if (!nums[i]) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                count++;
            }
        }
        return (!nums[n - 1] || !nums[n - 2]) ? -1 : count;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for MinOpToMakeBinOne..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        std::vector<int> params = {1, 0, 0, 1, 0, 1};
        auto result = minOperations(params);
        std::cout << "Output: " << result << std::endl;
        params = {0, 0, 0, 0, 0, 0};
        result = minOperations(params);
        std::cout << "Output: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new MinOpToMakeBinOneSolution();
}
#endif
