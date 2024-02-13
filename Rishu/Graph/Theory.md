
1. **Basic Terminologies and Representations:**
   - **Vertex (Node):** A fundamental unit of a graph, often representing an entity.
   - **Edge (Link):** A connection between two vertices in a graph.
   - **Directed Graph (Digraph):** A graph in which edges have a direction.
   - **Undirected Graph:** A graph in which edges do not have a direction.
   - **Weighted Graph:** A graph in which edges have a weight or cost associated with them.
   - **Adjacency Matrix:** A 2D array where the entry `matrix[i][j]` represents an edge between vertices `i` and `j`.
   - **Adjacency List:** A collection of lists where each list represents the vertices adjacent to a particular vertex.

2. **Graph Search and Traversal Algorithms:**
   - **Depth-First Search (DFS):** A graph traversal algorithm that explores as far as possible along each branch before backtracking.
   - **Breadth-First Search (BFS):** A graph traversal algorithm that explores all the vertices in the graph at the present depth before moving to the vertices at the next depth level.

3. **Complexity Analysis:**
   - **Time Complexity:** The amount of time taken by an algorithm to run as a function of the size of the input graph.
   - **Space Complexity:** The amount of memory space required by an algorithm to run as a function of the size of the input graph.
   - **DFS Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges in the graph.
   - **DFS Space Complexity:** O(V), where V is the number of vertices in the graph (for the stack).
   - **BFS Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges in the graph.
   - **BFS Space Complexity:** O(V), where V is the number of vertices in the graph (for the queue).

Graph provides a framework for understanding and modeling relationships between objects. Basic terminologies such as vertices, edges, and graph representations like adjacency matrices and lists are fundamental to graph theory. Graph search and traversal algorithms like DFS and BFS help navigate and explore graphs efficiently. Complexity analysis helps understand the performance characteristics of these algorithms in terms of time and space requirements.