#include <iostream>
#include <string>
#include "solution.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [problem_name]" << std::endl;
        return 1;
    }

    std::string problem_name = argv[1];
    std::cout << "Running solution for problem: " << problem_name << std::endl;
    
    // Execute the solution
    Solution solution;
    solution.run();
    
    return 0;
}
