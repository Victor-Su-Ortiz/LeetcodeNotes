#!/bin/bash

# Create directory structure
mkdir -p LeetcodeNotes/src
mkdir -p LeetcodeNotes/include
mkdir -p LeetcodeNotes/build
mkdir -p LeetcodeNotes/docs

# Create the main driver file
cat > LeetcodeNotes/src/main.cpp << 'EOF'
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
EOF

# Create a base solution header
cat > LeetcodeNotes/include/solution.h << 'EOF'
#ifndef SOLUTION_H
#define SOLUTION_H

class Solution {
public:
    virtual void run() = 0;
    virtual ~Solution() {}
};

#endif // SOLUTION_H
EOF

# Create a template for new problems
cat > LeetcodeNotes/template.cpp << 'EOF'
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "solution.h"

// Problem: [PROBLEM_NAME]
// Description: [PROBLEM_DESCRIPTION]

class [PROBLEM_NAME]Solution : public Solution {
public:
    // Your solution implementation here
    
    void run() override {
        // Test cases
        std::cout << "Running test cases for [PROBLEM_NAME]..." << std::endl;
        
        // Example test case
        // auto result = yourSolutionMethod(params);
        // std::cout << "Result: " << result << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new [PROBLEM_NAME]Solution();
}
#endif
EOF

# Create a template for problem documentation
cat > LeetcodeNotes/template.md << 'EOF'
# [PROBLEM_NAME]

## Problem Description
[PROBLEM_DESCRIPTION]

## Approach
[DESCRIBE_YOUR_APPROACH]

## Time Complexity
- Time Complexity: [TIME_COMPLEXITY]
- Space Complexity: [SPACE_COMPLEXITY]

## Notes
[ANY_ADDITIONAL_NOTES]
EOF

# Create Makefile
cat > LeetcodeNotes/Makefile << 'EOF'
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I./include
SRC_DIR = src
BUILD_DIR = build
PROBLEM_NAME ?= TwoSum  # Default problem name

# Find the problem source file
PROBLEM_SRC = $(shell find $(SRC_DIR) -name "$(PROBLEM_NAME).cpp" -o -name "$(PROBLEM_NAME)_*.cpp" | head -1)

all: clean $(BUILD_DIR)/$(PROBLEM_NAME)

$(BUILD_DIR)/$(PROBLEM_NAME): $(PROBLEM_SRC) $(SRC_DIR)/main.cpp
    @mkdir -p $(BUILD_DIR)
    $(CXX) $(CXXFLAGS) -DCURRENT_SOLUTION $(SRC_DIR)/main.cpp $(PROBLEM_SRC) -o $@

run: $(BUILD_DIR)/$(PROBLEM_NAME)
    ./$(BUILD_DIR)/$(PROBLEM_NAME) $(PROBLEM_NAME)

new:
    @if [ -z "$(PROBLEM_NAME)" ]; then \
        echo "Please provide a problem name: make new PROBLEM_NAME=YourProblemName"; \
        exit 1; \
    fi
    @if [ -f "$(SRC_DIR)/$(PROBLEM_NAME).cpp" ]; then \
        echo "Problem already exists!"; \
        exit 1; \
    fi
    @mkdir -p $(SRC_DIR)
    @sed "s/\[PROBLEM_NAME\]/$(PROBLEM_NAME)/g" template.cpp > $(SRC_DIR)/$(PROBLEM_NAME).cpp
    @sed "s/\[PROBLEM_NAME\]/$(PROBLEM_NAME)/g" template.md > docs/$(PROBLEM_NAME).md
    @echo "Created new problem: $(PROBLEM_NAME)"
    @echo "Source file: $(SRC_DIR)/$(PROBLEM_NAME).cpp"
    @echo "Documentation: docs/$(PROBLEM_NAME).md"

list:
    @echo "Available problems:"
    @find $(SRC_DIR) -name "*.cpp" | grep -v "main.cpp" | sed 's/.*\/\(.*\)\.cpp/\1/'

clean:
    rm -rf $(BUILD_DIR)/*

.PHONY: all run new list clean
EOF

# Create a utility script to make new problems more easily
cat > LeetcodeNotes/new_problem.sh << 'EOF'
#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: $0 <problem_name> [problem_description]"
    exit 1
fi

PROBLEM_NAME=$1
PROBLEM_DESCRIPTION=${2:-"Add your problem description here"}

make new PROBLEM_NAME="$PROBLEM_NAME"

# Optionally update the description
if [ "$PROBLEM_DESCRIPTION" != "Add your problem description here" ]; then
    sed -i "s/\[PROBLEM_DESCRIPTION\]/$PROBLEM_DESCRIPTION/g" docs/$PROBLEM_NAME.md
    sed -i "s/\[PROBLEM_DESCRIPTION\]/$PROBLEM_DESCRIPTION/g" src/$PROBLEM_NAME.cpp
fi

echo "You can now edit src/$PROBLEM_NAME.cpp to implement your solution"
echo "Document your approach in docs/$PROBLEM_NAME.md"
echo "To build and run: make run PROBLEM_NAME=$PROBLEM_NAME"
EOF

chmod +x LeetcodeNotes/new_problem.sh

# Create a sample problem solution
cat > LeetcodeNotes/src/TwoSum.cpp << 'EOF'
#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"

// Problem: TwoSum
// Description: Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.

class TwoSumSolution : public Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
    
    void run() override {
        std::cout << "Running TwoSum solution..." << std::endl;
        
        // Test cases
        std::vector<int> nums1 = {2, 7, 11, 15};
        int target1 = 9;
        auto result1 = twoSum(nums1, target1);
        
        std::cout << "Input: nums = [2,7,11,15], target = 9" << std::endl;
        std::cout << "Output: [" << result1[0] << "," << result1[1] << "]" << std::endl;
        
        std::vector<int> nums2 = {3, 2, 4};
        int target2 = 6;
        auto result2 = twoSum(nums2, target2);
        
        std::cout << "Input: nums = [3,2,4], target = 6" << std::endl;
        std::cout << "Output: [" << result2[0] << "," << result2[1] << "]" << std::endl;
    }
};

// If this file is being compiled as the main solution
#ifdef CURRENT_SOLUTION
Solution* createSolution() {
    return new TwoSumSolution();
}
#endif
EOF

# Create a sample problem documentation
cat > LeetcodeNotes/docs/TwoSum.md << 'EOF'
# TwoSum

## Problem Description
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## Approach
1. Use a hash map to store each number and its index as we iterate through the array.
2. For each number, check if its complement (target - current number) exists in the hash map.
3. If the complement exists, return the current index and the complement's index.
4. Otherwise, add the current number and its index to the hash map and continue.

## Time Complexity
- Time Complexity: O(n) where n is the length of the array. We traverse the array once.
- Space Complexity: O(n) for the hash map that stores at most n elements.

## Notes
This is an optimal solution as it achieves O(n) time complexity with a single pass through the array.
EOF

# Create a README.md file
cat > LeetcodeNotes/README.md << 'EOF'
# LeetCode Solutions Project

A C++ project structure for organizing and running LeetCode problem solutions.

## Project Structure

```
LeetcodeNotes/
├── include/             # Header files
├── src/                 # Source files for problems
├── build/               # Compiled binaries
├── docs/                # Documentation for problems
├── Makefile             # Build system
├── template.cpp         # Template for new problems
├── template.md          # Template for documentation
└── new_problem.sh       # Script to create new problems
```

## Usage

### Create a new problem

```bash
./new_problem.sh ProblemName "Short description of the problem"
```

This will:
1. Create a new source file in `src/ProblemName.cpp`
2. Create a documentation file in `docs/ProblemName.md`

### Implement your solution

Edit the generated source file to implement your solution for the problem.

### Document your approach

Edit the documentation file to describe your approach, time complexity, and any other notes.

### Build and run

```bash
make run PROBLEM_NAME=ProblemName
```

### List available problems

```bash
make list
```

## Example

The project comes with a sample "TwoSum" problem implementation.

To run it:

```bash
make run PROBLEM_NAME=TwoSum
```
EOF

echo "LeetCode solutions project structure created in the 'LeetcodeNotes' directory!"
echo "To get started:"
echo "  1. cd LeetcodeNotes"
echo "  2. ./new_problem.sh YourProblemName \"Problem description\""
echo "  3. Edit src/YourProblemName.cpp to implement your solution"
echo "  4. Document your approach in docs/YourProblemName.md"
echo "  5. Run: make run PROBLEM_NAME=YourProblemName"
