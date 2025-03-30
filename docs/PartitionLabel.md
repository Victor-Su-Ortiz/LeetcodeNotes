# PartitionLabel

## Problem Description
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

## Approach
Find maximum interval length (same as finding all overlapping intervals), the length of the interval i.e. where all characters exists only in this window is the value appended to the array.

We need to keep track of the last idx of a char to know when the char ends. can think of each start and end of each char as the start and end in a time interval

## Time Complexity
- Time Complexity: O(n)
- Space Complexity: O(n)

## Notes
[ANY_ADDITIONAL_NOTES]
