#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: MinCostWalkWeightedGraph
// Description: [PROBLEM_DESCRIPTION]

class MinCostWalkWeightedGraphSolution : public Solution {
public:
    class UnionFind {
        std::vector<int> set;
        std::vector<int> sizes;
        public:
        UnionFind(int n): set(n), sizes(n, 1) {
            for (int i = 0; i < n; i++) {
                set[i] = i;
            }
        }

        int find(int A) {
            auto cur = A;
            while (set[cur] != cur) {
                cur = set[cur];
            }
            while (A != cur) {
                auto tmp = set[A];
                set[A] = cur;
                A = tmp;
            }
            return cur;
        }

        std::pair<int, int> combine(int A, int B) {
            int rootA = find(A);
            int rootB = find(B);
            if (rootA == rootB) {
                return {rootA, rootB};
            }
            if (sizes[rootA] > sizes[rootB]) {
                set[rootB] = rootA;
                sizes[rootA] += sizes[rootB];
                return {rootA, rootB};
            }
            else {
                set[rootA] = rootB;
                sizes[rootB] += sizes[rootA];
                return {rootB, rootA};
            }
        }

    };
    // Your solution implementation here
    std::vector<int> minimumCost(int n, std::vector<std::vector<int>> edges, std::vector<std::vector<int>> query ){
        auto un = new UnionFind(n);
        std::vector<int> minPaths(n, INT_MAX);
        for (const auto& edge: edges) {
            auto [rootA, rootB] = un->combine(edge[0], edge[1]);
            minPaths[rootA] = minPaths[rootA] & minPaths[rootB] & edge[2];
        }
        std::vector<int> result;
        for (const auto& q: query) {
            auto rootA = un->find(q[0]);
            auto rootB = un->find(q[1]);
            if (rootA != rootB) {
                result.push_back(-1);
            }
            else {
                result.push_back(minPaths[rootA]);
            }
        }
        return result;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for MinCostWalkWeightedGraph..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        int n = 5;
        std::vector<std::vector<int>> edges = {{0, 1, 7}, {1, 3, 7}, {1, 2, 1}};
        std::vector<std::vector<int>> query = {{0, 3}, {3, 4}};
        auto result = minimumCost(n, edges, query);
        std::cout << "Output: ";
        for (const auto& res: result) {
            std::cout << res << " ";
        }
        std::cout << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new MinCostWalkWeightedGraphSolution();
}
#endif
