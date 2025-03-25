#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: CheckGridCutInSections
// Description: [PROBLEM_DESCRIPTION]
using namespace std;   

class CheckGridCutInSectionsSolution : public Solution {
public:
    // Your solution implementation here
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end());
        int x = 0, y = 0;
        int curEnd = 1;
        for (const auto& rectangle: rectangles) {
            if (rectangle[0] >= curEnd) {
                x++;
            }
            curEnd = max(curEnd, rectangle[2]);
        }
        sort(rectangles.begin(), rectangles.end(), [](const auto& r1, const auto& r2){
            return r1[1] < r2[1];
        });
        curEnd = 1;
        for (const auto& rectangle: rectangles){
            if (rectangle[1] >- curEnd) {
                y++;
            }
            curEnd = max(curEnd, rectangle[3]);
        }
        return y > 2 || x > 2;
    }
    void run() override {
        // Test cases
        std::cout << "Running test cases for CheckGridCutInSections..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> rec = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
        auto res = checkValidCuts(5, rec);
        cout << "Result: " << res << endl;

    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new CheckGridCutInSectionsSolution();
}
#endif
