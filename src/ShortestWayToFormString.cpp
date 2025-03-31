#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: ShortestWayToFormString
// Description: [PROBLEM_DESCRIPTION]
using namespace std;
class ShortestWayToFormStringSolution : public Solution {
public:
    // Your solution implementation here
    int shortestWay(string source, string target) {
        vector<bool> seen(26, false);
        for (const auto& c: source) {
            seen[c - 'a'] = true;
        }
        int i = 0;
        int count = 0;
        int n = source.length();
        for (const auto& c: target) {
            if (i == 0) count++;
            if (!seen[c - 'a']) return false;
            while (c != target[i]) {
                i = (i + 1) % n;
                if (i == 0) count++;
            }
            i = (i + 1) % n;
        }
        return count;
    }
    void run() override {
        // Test cases
        std::cout << "Running test cases for ShortestWayToFormString..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        string source = "abc", target = "abcbc";
        auto res = shortestWay(source, target);
        cout << "Result " << res << endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new ShortestWayToFormStringSolution();
}
#endif
