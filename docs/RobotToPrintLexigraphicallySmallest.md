# RobotToPrintLexigraphicallySmallest

## Problem Description
You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.

## Approach
When adding a char to the written string, need to make sure it is the smallest (prefix) and that there is nothing smaller coming up. If there is something smaller then we can make a smaller character.
As long as the char on the stack is smaller than anything coming up, then we can add it to the string

## Time Complexity
- Time Complexity: [TIME_COMPLEXITY]
- Space Complexity: [SPACE_COMPLEXITY]

## Notes
[ANY_ADDITIONAL_NOTES]
