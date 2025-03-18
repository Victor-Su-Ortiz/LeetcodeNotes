# longestNiceArr

## Problem Description
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

## Approach
at every index i we maintain a prefixOr of all values in our subarray
when we hit a new value j it is only nice if the and with the prefixOr is also zero
we use sliding window where our subarray is always a nice array
arr[i...j] is a nice subarray if prefixOr[i...j - 1] & nums[j] = 0
when it is not we must remove all values in our prefixOr
given the invariant every bit in our prefixOr is unique otherwise it wont be equal to 0
we can therefore use Xor to remove
while(invalid) prefixOr ^= nums[i++]
finally given our bounds ans = max(ans, j - i + 1)


## Time Complexity
- Time Complexity: O(n)
- Space Complexity: O(1)

## Notes
[ANY_ADDITIONAL_NOTES]
