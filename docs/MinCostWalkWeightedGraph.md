# MinCostWalkWeightedGraph

## Problem Description
There is an undirected weighted graph with n vertices labeled from 0 to n - 1.

You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.

A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.

The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.

You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.

Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

## Approach
obesrve a property of &. suppose you have an arbitrary path = node[i]...node[j] where the current minPath = val;
val can be obtained by & all values in node[i]...node[j] as the & of two numbers is always bounded by the minimum value.
Therefore we can gurantee a global min bound by & all nodes in a path. 
Also notice that when we revisit a node with edge of weight w, since this weight is already in our minPath it does not impact our minPath for our min walk.
Therefore, we can always travel as much as we want throughout the graph, but ideally the minPath visits all edges at least once.

Solution:
Since, the minPath is minimized by & all connected components we can track the minPath value by finding all nodes in our connected component.
Even if the minPath is obtained before a new node is added since & is bounded by the min value we never need to worry about ever losing our current minimum value
so we find the minPath in a connected component which is a path that visits all edges at least once (eulerian path) 
When using query we check if they are in the same connected component if so return the minPath for that component.

We can use eulers path to visit every edge at least once and have a set that keeps track of all nodes we have visited or we can use unionfind to find all node connected in a compoents while keeping track of the minPath for a connected components root.

## Time Complexity
- Time Complexity: O(inverse of ackermann funcion)
- Space Complexity: O(n)

## Notes
[ANY_ADDITIONAL_NOTES]
