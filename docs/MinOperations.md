# MinOperations

## Problem Description
You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

## Approach
First we need to determine what the minimum value to transform everything to. We will use median, as half of the smaller values are less than it and half the greater. If you sccale this value then the number of operations will change since the number of values less than the vlaue and greater than the value will either increase or decrease.

For larger values you will need to scale more values up and less values down but each side will now have x and y values.

proof that it is the median value.
suppose it is not the min vlaue then there exists some value x that is closer.

## Time Complexity
- Time Complexity: O(m*nlog(m*n))
- Space Complexity: O(m + n)

## Notes
[ANY_ADDITIONAL_NOTES]
