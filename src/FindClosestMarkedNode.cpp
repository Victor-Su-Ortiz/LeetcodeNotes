#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: FindClosestMarkedNode
// Description: [PROBLEM_DESCRIPTION]
using namespace std;
class FindClosestMarkedNodeSolution : public Solution {
public:
    // Your solution implementation here
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<int> distances(n, INT_MAX);
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge: edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        distances[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        while(!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (dist > distances[cur]) continue;
            for (const auto& [neighbor, weight]: graph[cur]) {
                if (dist + weight < distances[neighbor]) {
                    distances[neighbor] = dist + weight;
                    pq.push({distances[neighbor], neighbor});
                }
            }
        }

        int ans = INT_MAX;
        for (const auto& mark: marked) {
            ans = min(ans, distances[mark]);    
        }
        return ans == INT_MAX ? -1 : ans;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for FindClosestMarkedNode..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> edges = {{0,1,1},{1,2,3},{2,3,2},{0,3,4}};
        vector<int> marked = {2, 3};
        auto res = minimumDistance(4, edges, 0, marked);
        cout << "Output: " << res << endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new FindClosestMarkedNodeSolution();
}
#endif
