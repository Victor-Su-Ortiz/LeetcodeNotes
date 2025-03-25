# CheckGridCutInSections

## Problem Description
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

## Approach
collapse the rectangles into one dimension and check if there is any part where there is no overlap. If there is no overlap that can be considered a cup. We need to sort by either the x or y coordinate. then check if there is a gap in either dimension. 

Keep track of the number of gaps and see if they are greater than 2 by the end.

## Time Complexity
- Time Complexity: O(nlog(n)) from sorting
- Space Complexity: O(1) no additional space being used

## Notes
[ANY_ADDITIONAL_NOTES]
