#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: LexigraphicallySmallestStringAfterRemovingStar
// Description: [PROBLEM_DESCRIPTION]
using namespace std;
class LexigraphicallySmallestStringAfterRemovingStarSolution : public Solution {
public:
    // Your solution implementation here
    string clearStars(string s) {
        vector<stack<int>> st(26);
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] != '*') {
                st[s[i] - 'a'].push(i);
            }
            else {
                int i = 0;
                while (i < 26 && st[i].size() == 0){
                    i++;
                }
                int idxRemove = st[i].top();
                st[i].pop();
                s[idxRemove] = '*';
            }
        }
        string ans = "";
        for (const auto& c: s){
            if (c != '*') {
                ans += c;
            }
        }
        return ans;
    }
    void run() override {
        // Test cases
        std::cout << "Running test cases for LexigraphicallySmallestStringAfterRemovingStar..." << std::endl;
        auto result = clearStars("aaba*");
        // Example test case
        // auto result = yourSolutionMethod(params);
        std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new LexigraphicallySmallestStringAfterRemovingStarSolution();
}
#endif
