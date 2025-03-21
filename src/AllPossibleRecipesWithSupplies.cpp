#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "solution.h"

// Problem: AllPossibleRecipesWithSupplies
// Description: [PROBLEM_DESCRIPTION]

class AllPossibleRecipesWithSuppliesSolution : public Solution {
public:
    // Your solution implementation here
    std::vector<std::string> findAllRecipes(std::vector<std::string>& recipes, std::vector<std::vector<std::string>>& ingredients, std::vector<std::string>& supplies) {
        std::unordered_map<std::string, std::vector<std::string>> graph;
        std::unordered_set<std::string> isRecipe;
        std::unordered_map<std::string, int> indegree;

        for (const auto& recipe: recipes) {
            isRecipe.insert(recipe);
        }
        for (int i = 0; i < (int) ingredients.size(); i++) {
            for (const auto& food: ingredients[i]) {
                graph[food].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        std::queue<std::string> q;
        for (const auto& supply: supplies) {
            q.push(supply);
        }
        std::vector<std::string> ans;

        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (isRecipe.find(cur) != isRecipe.end()) {
                ans.push_back(cur);
            }
            for (const auto& neighbor: graph[cur]) {
                if (indegree.find(neighbor) != indegree.end() && --indegree[neighbor] == 0) {
                    indegree.erase(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return ans;
    }
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for AllPossibleRecipesWithSupplies..." << std::endl;
        std::vector<std::string> recipes = {"bread","sandwich","burger"};
        std::vector<std::vector<std::string>> ingredients = {{"yeast","flour"}, {"bread","meat"}, {"sandwich","meat","bread"}};
        std::vector<std::string> supplies = {"yeast","flour","meat"};
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
        auto result = findAllRecipes(recipes, ingredients, supplies);
        std::cout << "Output: ";
        for (const auto& recipe: result) {
            std::cout << recipe << " ";
        }
        std::cout << std::endl;

    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new AllPossibleRecipesWithSuppliesSolution();
}
#endif
