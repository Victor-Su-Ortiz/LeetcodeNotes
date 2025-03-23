#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: NumberWaysToDestination
// Description: [PROBLEM_DESCRIPTION]
using namespace std;

class NumberWaysToDestinationSolution : public Solution {
    int MOD = 1e9 + 7;
public:
    // Your solution implementation here
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }  

        vector<pair<long long, int>> distances(n, {LLONG_MAX, 0});
        distances[0] = {0, 1};
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();
            if (dist > distances[cur].first) continue;
            for (const auto& [neighbor, weight]: graph[cur]) {
                auto [curDist, ways] = distances[cur];
                if (curDist + weight == distances[neighbor].first) {
                    distances[neighbor].second = (distances[neighbor].second + ways) % MOD;
                }
                else if (curDist + weight < distances[neighbor].first) {
                    distances[neighbor].second = ways;
                    distances[neighbor].first = curDist + weight;
                    pq.push({distances[neighbor].first, neighbor});
                }
            }
        }
        return distances.back().second;
    }

    void run() override {
        // Test cases
        std::cout << "Running test cases for NumberWaysToDestination..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
        auto res = countPaths(7, roads);   
        cout << "Output: " << res << endl;
        }
    };

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new NumberWaysToDestinationSolution();
}
#endif
