# CountDaysWithoutMeeting

## Problem Description
You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).

Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.

## Approach
sort meetings by start time. This is just to ensure that you can determine what meeting times are overlapping 
as the prev meeting at i-1 will have an end time at meeting[0] and this sorting gurantees that if we find another meeeting that overlaps with this meeting it will come later and iwll not be missed. Otherwise we will risk losing out on some of the potential overlaps. otherwise we have an interval come before i taht does not overlap, but will cause our algortihm to not work as a result.

Using this we can keep track of our current overlap end time. when we find an interval that no longer overlaps we can find the number of days between then. We also need to count the days before the meetings and after all meetings so just start at end tiem of 0 and subtract from days at teh end if days is greater than the final end time.

## Time Complexity
- Time Complexity: O(nlog(n)) from sorting
- Space Complexity: o(1)

## Notes
[ANY_ADDITIONAL_NOTES]
