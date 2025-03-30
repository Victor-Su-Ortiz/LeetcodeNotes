#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: PartitionLabel
// Description: [PROBLEM_DESCRIPTION]
using namespace std;

class PartitionLabelSolution : public Solution {
public:
    // Your solution implementation here
    vector<int> partitionLabels(string s) {
        vector<int> lastIdx(26, -1);
        for (int i = s.length() - 1; i >= 0; i--) {
            auto cur = s[i] - 'a';
            if (lastIdx[cur] == -1) {
                lastIdx[cur] = i;
            }
        }
        int end = 0;
        int start = 0;
        vector<int> ans;
        for (int i = 0; i < s.length(); i++) {
            auto cur = s[i] - 'a';
            end = max(end, lastIdx[cur]);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
    
    void printArr(vector<int>& arr){
        cout << "{ ";
        for (const auto& num: arr) {
            cout << num << ", ";
        }
        cout << endl;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for PartitionLabel..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        string s = "ababcbacadefegdehijhklij";
        auto res = partitionLabels(s);
        printArr(res);
        
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new PartitionLabelSolution();
}
#endif
