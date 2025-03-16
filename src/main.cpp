#include <iostream>
#include <string>
#include <memory>
#include "solution.h"

// Function prototype for the factory function that will be defined in each solution file
Solution* createSolution();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [problem_name]" << std::endl;
        return 1;
    }

    std::string problem_name = argv[1];
    std::cout << "Running solution for problem: " << problem_name << std::endl;
    
    // Create the solution using the factory function
    std::unique_ptr<Solution> solution(createSolution());
    
    // Execute the solution
    solution->run();
    
    return 0;
}