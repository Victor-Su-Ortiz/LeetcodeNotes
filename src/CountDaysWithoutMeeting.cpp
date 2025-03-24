#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: CountDaysWithoutMeeting
// Description: [PROBLEM_DESCRIPTION]

using namespace std;

class CountDaysWithoutMeetingSolution : public Solution {
public:
    // Your solution implementation here
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        int curEnd = 0;
        sort(meetings.begin(), meetings.end());
        for (const auto& meeting: meetings) {
            if (meeting[0] > curEnd) {
                ans += meeting[0] - curEnd - 1;
                curEnd = meeting[1];
            }
            else {
                curEnd = max(curEnd, meeting[1]);
            }
        }
        if (days > curEnd) {
            ans += days - curEnd;
        }
        return ans;
        
    }

    void run() override {
        // Test cases
        std::cout << "Running test cases for CountDaysWithoutMeeting..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> meetings = {{5,7},{1,3},{9,10}};
        auto res = countDays(10, meetings);
        cout << "Output: " << res << endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new CountDaysWithoutMeetingSolution();
}
#endif
