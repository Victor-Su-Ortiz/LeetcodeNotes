#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

using namespace std;
// Problem: CountNumberCompleteComponents
// Description: [PROBLEM_DESCRIPTION]
class UnionFind {
    public:
    vector<int> set;
    vector<int> sizes;
    vector<int> numEdges;
    UnionFind(int n): set(n), sizes(n, 1), numEdges(n, 0) {
        for (int i = 0; i < n; i++) {
            set[i] = i;
        }
    }

    int find(int A) {
        auto cur = A;
        while (cur != set[cur]) {
            cur = set[cur];
        }
        while (A != cur) {
            auto tmp = set[A];
            set[A] = cur;
            A = tmp;
        }
        return A;
    }

    void combine(int A, int B) {
        int rootA = find(A);
        int rootB = find(B);
        if (rootA == rootB) {
            numEdges[rootA]++;
            return;
        }
        if (sizes[rootA] > sizes[rootB]) {
            set[rootB] = rootA;
            sizes[rootA] += sizes[rootB];
            numEdges[rootA] += numEdges[rootB] + 1;
        }
        else {
            set[rootA] = rootB;
            sizes[rootB] += sizes[rootA];
            numEdges[rootB] += numEdges[rootA] + 1;
        }
    }

    bool isComplete(int root) {
        double n = sizes[root];
        return numEdges[root] == n * (n - 1) / 2;
    }
};

class CountNumberCompleteComponentsSolution : public Solution {
public:
    // Your solution implementation here
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        auto un = new UnionFind(n);
        for (const auto& edge: edges) {
            un->combine(edge[0], edge[1]);
        }
        vector<bool> found(50);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int root = un->find(i);
            if (!found[root] && un->isComplete(root)) {
                ans++;
            }
            found[root] = true;
        }
        return ans;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for CountNumberCompleteComponents..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4}};
        auto res = countCompleteComponents(6, edges);
        cout << "Output: " << res << endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new CountNumberCompleteComponentsSolution();
}
#endif
