# FindClosestMarkedNode

## Problem Description
You are given a positive integer n which is the number of nodes of a 0-indexed directed weighted graph and a 0-indexed 2D array edges where edges[i] = [ui, vi, wi] indicates that there is an edge from node ui to node vi with weight wi.

You are also given a node s and a node array marked; your task is to find the minimum distance from s to any of the nodes in marked.

Return an integer denoting the minimum distance from s to any node in marked or -1 if there are no paths from s to any of the marked nodes.

## Approach
This is either djikstra or bellman ford you can decide which to use
djkstra is O((V+E)log(V))
bellman is O(V*E)

when bellman space O(V)
when djkstra O(V + E)

## Time Complexity
- Time Complexity: [TIME_COMPLEXITY]
- Space Complexity: [SPACE_COMPLEXITY]

## Notes
[ANY_ADDITIONAL_NOTES]
