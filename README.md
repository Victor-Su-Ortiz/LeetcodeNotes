# LeetCode Solutions Project

A C++ project structure for organizing and running LeetCode problem solutions.

Here is my current leetcode profile: https://leetcode.com/u/victorsumpling/

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
