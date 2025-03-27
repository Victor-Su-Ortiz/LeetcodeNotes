#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: MinOperations
// Description: [PROBLEM_DESCRIPTION]
using namespace std;

class MinOperationsSolution : public Solution {
public:
    // Your solution implementation here
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> tmp;
        for (const auto& row: grid) {
            tmp.insert(tmp.end(), row.begin(), row.end());
        }

        sort(tmp.begin(), tmp.end());
        int median = tmp[tmp.size() / 2];
        int ans = 0;
        for (int i = 0; i < (int) tmp.size(); i++) {
            int diff = abs(median - tmp[i]);
            if (diff % x) return - 1;
            ans += diff / x;
        }
        return ans;
    }

    
    void run() override {
        // Test cases
        std::cout << "Running test cases for MinOperations..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> grid = {{2,4},{6,8}};
        int result = minOperations(grid, 2);
        std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new MinOperationsSolution();
}
#endif
