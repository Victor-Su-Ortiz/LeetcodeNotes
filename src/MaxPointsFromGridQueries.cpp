#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: MaxPointsFromGridQueries
// Description: [PROBLEM_DESCRIPTION]
using namespace std;

class MaxPointsFromGridQueriesSolution : public Solution {
public:
    // Your solution implementation here
    vector<vector<int>> dirs {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != INT_MAX;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
       // each val is sum of previous val + any new grids you can visit
        int n = queries.size();
        vector<pair<int, int>> queriesIdx;
        for (int i = 0; i < n; i++) {
            queriesIdx.emplace_back(queries[i], i);
        }
        sort(queriesIdx.begin(), queriesIdx.end());
        vector<int> ans (n);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        int visited = 0;
        grid[0][0] = INT_MAX;
        for (int i = 0; i < n; i++){
             while (!pq.empty() && pq.top()[0] < queriesIdx[i].first) {
                auto i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                visited++;
                for (const auto& dir: dirs) {
                    int n_i = i + dir[0];
                    int n_j = j + dir[1];
                    if (isValid(n_i, n_j, grid)) {
                        pq.push({grid[n_i][n_j], n_i, n_j});
                        grid[n_i][n_j] = INT_MAX;
                    }
                }
            }
            ans[queriesIdx[i].second] = visited;
        }
       
        return ans;
    }   

    void printArr(vector<int>& arr) {
        cout << "Result: " << "{ ";
        for (const auto& val: arr) {
            cout << val << ", ";
        }
        cout << endl;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for MaxPointsFromGridQueries..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> grid = {{1,2,3},{2,5,7},{3,5,1}};

        vector<int> queries = {5, 6, 2};
        auto res = maxPoints(grid, queries);
        printArr(res);
        
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new MaxPointsFromGridQueriesSolution();
}
#endif
