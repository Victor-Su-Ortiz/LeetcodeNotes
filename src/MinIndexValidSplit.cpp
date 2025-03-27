#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: MinIndexValidSplit
// Description: [PROBLEM_DESCRIPTION]
using namespace std;
class MinIndexValidSplitSolution : public Solution {
public:
    // Your solution implementation here
    int minimumIndex(vector<int>& nums) {
        // find the majority element
        int majority = nums[0], count = 0;
        for (const auto& num: nums) {
            if (num == majority) {
                count++;
            }
            else {
                count--;
            }
            if (count == 0) {
                majority = num;
                count = 1;
            }
        }
        int xCount = 0;
        for (const auto& num: nums) {
            if (num == majority) {
                xCount++;
            }
        }
        count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto num = nums[i];
            if (num == majority){
                count++; 
                xCount--;
            }
            if (count > (i + 1) / 2 && xCount > (n - i - 1) / 2) {
                return i;
            }
        }

        return -1;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for MinIndexValidSplit..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<int> nums = {1, 2, 2, 2};
        int idx = minimumIndex(nums);
        cout << "Output: " << idx << endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new MinIndexValidSplitSolution();
}
#endif
