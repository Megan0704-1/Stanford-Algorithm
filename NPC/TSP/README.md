# Problem Definition
Travelling Salesman Problem (TSP):
    Given a set of verticies and edge costs, the problem is to find the shortest possible cycle that visits every node exactly once. -> Finding the min cost of Hamiltonain Cycle

# Input
- number of vertices in a graph
- location (x, y) of each vertices

# Output
- the min cost of the cycle that visits all node in the given graph

# Relationship to NPC
There is no polynomial-time know solution for this problem so far. -> TSP is a NP hard problem

# Solutions
- Naive: O(n!)
- DP

# DP algorithm
- Chose random vertex as starting point (1 in this demonstration)
- For every other vertex j other than 1, we find min cost path with 1 as starting point, j as ending point, and all verticies appear once in the traversal.
- Let C[j] denotes the cost traversing from 1 to j, therefore the cost of a cycle = C[j] + distance(j, 1)
- Define A[S, j] as the min cost visiting every vertex in S exactly once and ends at j. The starting point, 1 must appear in every S (desire cycle)

# Technique 
-- bitmask: maintaining the invariant