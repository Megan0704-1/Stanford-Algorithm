## Dijkstra's Algorithm
**Definition:**
  Dijkstra's algorithm is a typical algoirhtm computing the shortest path from a given node in a graph.

**Brain Storm**
  1. The algorithm starts at a given node `s` in a graph.
  2. Implment 2 data structures S and U.
  3. S for recording the nodes that has already explored and their corresponding lengths.( The shortest path so far )
  4. U for recording the nodes that has not explored yet.
  5. Initially, S data structure contains node `s`, U contains all the other nodes and their distances to node `s`. (If the nodes are not connectes to nodes in S, we specifically make them having length $\infty$. )

**Example**
![alt text](graphSearch-algo/graph.jpg)
