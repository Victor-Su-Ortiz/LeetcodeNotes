#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: MinTimeRepairCars2594
// You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

// You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

// Return the minimum time taken to repair all the cars.

// Note: All the mechanics can repair the cars simultaneously.

class MinTimeRepairCarsSolution2594 : public Solution {
public:
    // Your solution implementation here
    long long repairCars(std::vector<int>& ranks, int cars) {   
        long long l = 1;
        // max amount of time to complete all cars for one worker
        long long r = 1LL * cars * cars * ranks[0];
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isValid(mid, ranks, cars)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }

        }
        return l;

    }

    bool isValid(int time, std::vector<int>& ranks, int cars) {
        int totalCars = 0;
        for (const auto& rank: ranks) {
            totalCars += sqrt(1.0 * time/ rank);
        }
        return totalCars >= cars;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for MinTimeRepairCars2594..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new MinTimeRepairCarsSolution2594();
}
#endif
