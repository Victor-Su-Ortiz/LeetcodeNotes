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
