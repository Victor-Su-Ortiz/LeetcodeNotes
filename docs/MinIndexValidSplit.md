# MinIndexValidSplit

## Problem Description
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.



## Approach
Observe how the element must be majority in both halfs. Since the count is > than 2* (len A/2 ) then the element is the majority of the whole array.

using this we can keep track of the trailing and leading counts of our majority. If both the counts are greater than the majority than we have found the minimum index when iteration from left to right

## Time Complexity
- Time Complexity: O(n)
- Space Complexity: O(1)

## Notes
[ANY_ADDITIONAL_NOTES]
