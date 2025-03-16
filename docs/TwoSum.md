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
