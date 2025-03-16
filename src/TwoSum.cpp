#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"

// Problem: TwoSum
// Description: Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

class TwoSumSolution : public Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
    
    void run() override {
        std::cout << "Running TwoSum solution..." << std::endl;
        
        // Test cases
        std::vector<int> nums1 = {2, 7, 11, 15};
        int target1 = 9;
        auto result1 = twoSum(nums1, target1);
        
        std::cout << "Input: nums = [2,7,11,15], target = 9" << std::endl;
        std::cout << "Output: [" << result1[0] << "," << result1[1] << "]" << std::endl;
        
        std::vector<int> nums2 = {3, 2, 4};
        int target2 = 6;
        auto result2 = twoSum(nums2, target2);
        
        std::cout << "Input: nums = [3,2,4], target = 6" << std::endl;
        std::cout << "Output: [" << result2[0] << "," << result2[1] << "]" << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new TwoSumSolution();
}
#endif
