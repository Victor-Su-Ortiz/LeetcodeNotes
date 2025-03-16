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
