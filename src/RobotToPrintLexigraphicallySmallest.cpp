#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: RobotToPrintLexigraphicallySmallest
// Description: [PROBLEM_DESCRIPTION]
using namespace std;

class RobotToPrintLexigraphicallySmallestSolution : public Solution {
public:
    // Your solution implementation here
    string robotWithString(string s) {
        vector<int> counts(26);
        for (const auto& c: s) {
            counts[c - 'a']++;
        }
        
        stack<char> st;
        int smallestIdx = 0;
        string ans = "";
        for (const auto& c: s) {
            st.push(c);
            counts[c - 'a']--;
            while (smallestIdx < 26 && counts[smallestIdx] == 0) {
                smallestIdx++;
            }
            while (!st.empty() && (st.top() - 'a') <= smallestIdx) {
                ans += st.top();
                st.pop();
            }
        }
        return ans;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for RobotToPrintLexigraphicallySmallest..." << std::endl;
        auto result = robotWithString("bdda");
        // Example test case
        // auto result = yourSolutionMethod(params);
        std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new RobotToPrintLexigraphicallySmallestSolution();
}
#endif
