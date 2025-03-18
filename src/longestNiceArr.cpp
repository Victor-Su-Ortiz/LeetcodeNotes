#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include "solution.h"

// Problem: longestNiceArr
// Description: [PROBLEM_DESCRIPTION]

class longestNiceArrSolution : public Solution {
public:
    // Your solution implementation here
    int longestNiceSubarray(std::vector<int>& nums) {
        int i = 0;
        int prefixOr = nums[0];
        int ans = 1;
        for (int j = 1; j < (int) nums.size(); j++) {
            while(i < j && (prefixOr & nums[j])) {
                prefixOr ^= nums[i++];
            }
            prefixOr |= nums[j];
            ans = std::max(ans, j - i + 1);
        }
        return ans;
    }   
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for longestNiceArr..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        std::vector<int> params = {1, 3, 8, 48, 10};
        auto result = longestNiceSubarray(params);
        std::cout << "Output: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new longestNiceArrSolution();
}
#endif
