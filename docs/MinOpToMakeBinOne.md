# MinOpToMakeBinOne

## Problem Description
You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

## Approach
solution: when we hit a 0 at index i greedily swap to 1 and i + 1 and i + 2
We will show that this produces an optimal solution i.e. if the one is possible. Assume there is a optimal solutin O and our greedy algorithm produces a solution A.
Let f(i) be the value at i if it is possible to be 1 then it is one if it is not possible then it is 0
wts that A is at least as good i.e. it is a 1 when it can be flipped to a one and 0 when it cannot
for i = 0 it is intuitive
for i > 0 we cannot flip at i must go back to i - 2 to prove
assume i - 3 is true
that means i - 3 is one and our solution up to then is 1 as it can always be flipped
case 1:
flip i - 3 if it is zero
in this case i - 2 and i - 1 are flipped
i - 2 zero originally:
no flip
case 2: 
no flip
in this case i - 2 and i - 1 keep same values
i - 2 zero originally
flip
when i - 1 cannot be 1 then it cannot be switched as we would be undoing the prev optimal





## Time Complexity
- Time Complexity: O(n)
- Space Complexity: O(1)

## Notes
[ANY_ADDITIONAL_NOTES]
