# CountNumberCompleteComponents

## Problem Description
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

## Approach
Let us define what it means to be complete. A component is complete if there is an edge for every pair of nodes. This means there are n(n-1)/2 edges since that is the number of permutations of pairs in the component.

We can unionfind to find all connected components then check if each connected component has n(n-1)/2 edges in it. since there are no duplicate and no self edges we can be confident that when n(n-1)/2 numEdges in a connected component then it is complete. if there is nay more such as though self loops or duplicate edges is this still a complete connected component? only invariant is that there exists edge between all pairs , so we can just add a condition that does not consider these types of edges and only unique edges between pairs.

## Time Complexity
- Time Complexity: O(n) for making unionfind O(m*ackermann function(n)) for cmbining edges
- Space Complexity: O(n) for all the unionfind fields

## Notes
[ANY_ADDITIONAL_NOTES]
