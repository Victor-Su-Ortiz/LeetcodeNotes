#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: PROBLEM_NAME=LexigraphicallySmallestRepresentation
// Description: [PROBLEM_DESCRIPTION]
using namespace std;
class LexigraphicallySmallestRepresentationSolution : public Solution {
public:
    class UnionFind {
        vector<int> rank;
        vector<int> sizes;
        vector<int> lexi;
        public:
        UnionFind(): rank(26), sizes(26, 1), lexi(26) {
            for (int i = 0; i < 26; i++) {
                rank[i] = i;
                lexi[i] = i;
            }
        }

        int find(int A) {
            auto cur = A;
            while (rank[cur] != cur) {
                cur = rank[cur];
            }
            while (rank[A] != cur) { 
                auto tmp = rank[A];
                rank[A] = cur;
                A = tmp;
            }
            return cur;
        }

        void combine(int A, int B) {
            int rootA = find(A);
            int rootB = find(B);
            if (rootA == rootB) return;
            int smallestLexi = lexi[rootA] < lexi[rootB] ? lexi[rootA] : lexi[rootB];
            if (sizes[rootA] < sizes[rootB]) {
                rank[rootA] = rootB;
                sizes[rootB] += sizes[rootA];
                lexi[rootB] = smallestLexi;
            }
            else {
                rank[rootB] = rootA;
                sizes[rootA] += sizes[rootB];
                lexi[rootA] = smallestLexi;
            }
        }

        char findSmallest(char c) {
            auto rootA = find(c-'a');
            return lexi[rootA] + 'a';
        }
        
    };

    // Your solution implementation here
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        auto un = new UnionFind();
        size_t n = s1.length();
        for (int i = 0; i < (int)n; i++) {
            un->combine(s1[i] - 'a', s2[i] - 'a');
        }
        for (char& c: baseStr){
            c = un->findSmallest(c);
        }
        return baseStr;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for PROBLEM_NAME=LexigraphicallySmallestRepresentation..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new PROBLEM_NAME=LexigraphicallySmallestRepresentationSolution();
}
#endif
