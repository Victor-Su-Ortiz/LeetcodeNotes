#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: LargestColorValueGraph
// Description: [PROBLEM_DESCRIPTION]
using namespace std;

class LargestColorValueGraphSolution : public Solution {
public:
    // Your solution implementation here
    int largestPathValue(string colors, vector<vector<int>> edges) {
        int n = colors.length();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        vector<vector<int>> distances(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                distances[i][colors[i] - 'a'] = 1;
                n--;
            }
        }
        int ans = 1;

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (const auto& neighbor: graph[cur]) {
                for (int i = 0; i < 26; i++) {
                    distances[neighbor][i] = max(distances[neighbor][i], distances[cur][i] + (colors[neighbor] - 'a' == i));
                    ans = max(ans, distances[neighbor][i]);
                }
                if (--indegree[neighbor] == 0) {
                    n--;
                    q.push(neighbor);

                }
            }
        }
        return n != 0 ? -1 : ans;
    }

    int dfs(vector<vector<int>>& graph, vector<bool>& path, vector<bool>& visited, vector<vector<int>>& distances, int cur, string& colors) {
        if (path[cur] == true) return INT_MAX;
        if (visited[cur] == true) return distances[cur][colors[cur] - 'a'];
        visited[cur] = true;
        path[cur] = true;
        
        for (const auto& neighbor: graph[cur]) {
            if (dfs(graph, path, visited, distances, neighbor, colors) == INT_MAX) {
                return INT_MAX;
            }
            // get the paths from the neighbor nodes
            for (int i = 0; i < 26; i++) {
                distances[cur][i] = max(distances[cur][i], distances[neighbor][i]);
            }
        }

        path[cur] = false;
        distances[cur][colors[cur] - 'a']++;
        return distances[cur][colors[cur] - 'a'];
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for LargestColorValueGraph..." << std::endl;
        vector<vector<int>> edges = {{0,1},{0,2},{2,3},{3,4}};
        string colors = "abaca";
        
        int result = largestPathValue(colors, edges);
        std::cout << "Result: " << result << std::endl;
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new LargestColorValueGraphSolution();
}
#endif
