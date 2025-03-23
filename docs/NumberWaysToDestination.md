# NumberWaysToDestination

## Problem Description
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

## Approach
using djkstra we can find the minimum path to a source from the origin. However we need to also keep track of the number of ways we get to that source. So we modify djkstra a bit. Whenever we update a distance of the next node (neighbor) with a new distance we update the number of ways to get to it with the number of ways to get to the current node.

When we find a new path with the same weight arriving at neighbor we need to add the number of ways to get to that previous path to the current neighbor. we can include a condition to remove all redudant and outdated visits when popping from the pq.

## Time Complexity
- Time Complexity: O((V+E)log(V))
- Space Complexity: O(V+E)

## Notes
[ANY_ADDITIONAL_NOTES]
