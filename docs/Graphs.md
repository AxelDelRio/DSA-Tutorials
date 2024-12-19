# GRAPHS

Binary Trees are just graphs in general

* the connections to each node in a graph is called "Edges"
* the actual nodes within our graph are considered a "Vertices" or 1 Vertex

connected graphs are considered connected when all nodes are connected

**NOTE:** disconnected graphs are valid graphs

Nodes/Vertices that are connected to each other are considered "neighbors" or "adjacency"

## Types of Graphs

### Undirected Graph

- A Undirected graph signifies where the edges don't have any direction to them

Example: 
Imagine this is a graph of number that are scattered

2 -- 3 -- 4 -- 6

The "--" are the edges that don't have any direction
this also means that we can travel forwards and backwards towards the Node/Vertex

FOR EXAMPLE:

We can think of a Social Network as an undirected graph
Where the Nodes/Vertices are people and the edges are chats/messages


### Directed Graph

- A Directed Graph have the edges point to a specific direction or to a specific Node! (make sure all the edges have a direction)

**NOTE:** These edges are one way connection, meaning you can't go both forward and back to the vertex (Unless we have 2 directed edges that go forward and backwards to the vertex)

Example: 

We can think of each vertex as a city where the edges are one way streets and a double edge between vertices are two way streets!

Once we have a directed graph, we can have successors and predecessors
Ex:

Imagine we have a graph with numbers

5 -> 6 -> 9

The predecessor of 6 is 5

the successor of 6 is 9

NOTE: We also associate cycles in our graph. A cycle in our graph means we can go through vertices many times and a Acyclic graph signifies there is no cycle.

EX: 

Cycle:   A -- B     Acyclic:    A -- B
         |    |                      |
         |    |                      |
         D -- C                      C



Remember we can also have directed edges that point forwards and backwards to a vertex

Ex:

3 -> 5
  <-

we describe where to travel from one node to another as a Tuple (values in pairs)

(THIS IS NOT A GRAPH, IMAGINE THE NUMBERS ARE SCATTERED)
ex: 4->3->6->8->9->5

Tuple: p = [(4,3),(3,6),(6,8),(8,9),(9,5)] <- These values are in pairs!

### Weighted Graphs

- A weighted graph is where the edges have a value associated with them

Ex:



  "2"   "1"    "3"
5-----6-----4------2

the lines connecting the numbers have a "weight" associated with them


now when you travel to a certain vertex, you can associate the weight into the travel
ex: think of the weight as a cost to travel to a vertex

using the illustration above, when we try to travel from 5 to 2. the cost of that is 6 since we just add up the weight.

(2+1+3)

the Tuple would look like this:

//(1st numbers, second number, cost/weight of edge)

p = [(5,6,2), (6,4,1), (4,2,3)]



## How to Represent a GRAPH

**1. Edge list**

An Edge list is basically a graph and collects two things

A verticy list and edge list

the verticy list represents all the nodes in the graph
the edge list represents all directions to each node and the weight of the edges associated with them

**2. Adjacency List**

With an Adjacency List, we create an Array full of Linked List's where each head of the Linked List are the Vertices that we have in our graph

EX:
Say we have a graph:

A -- B -- D
|    |
|    |
C -- E

Here is what our adjacency list would look like:

A --> B --> C
B --> A --> D --> E
C --> A --> E
D --> B
E --> C --> B

NOTICE: each head of each list are the different vertices in our graph and each list contain the path/edge to another vertex

REMEMBER: the Time complexity for an adjacency list is O(V) where V is the number of vertices or you can think of it as O(n). we consider it to be linear time since we have to traverse through the linked list to find the Vertex's adjacency. The space complexity is O(V + E) where V is the number of vertices and E are the number of edges

SO the Adjacency List method is slow when looking up an edge but doesn't consume as much memory/resources. This makes the list useful when the graph has minimal edges but more vertices

IN DEPTH COMPLEXITY FOR OPERATION USING ADJACENCY LIST:

 - A find/exist function between two nodes is O(V) - traverse the list for a vertex
 - Adding an edge would be O(1) - push_back an edge to a list
 - Removing an edge would be O(V) - finding and removing the edge in the list
 - Iterating through all edges would be O(V + E)


**3. Adjacency Matrix**

With an adjacency matrix, we create a 2D array where the column and rows are the vertex's

EX:
Say we have a graph:

A -- B -- D
|    |
|    |
C -- E

Here is what our adjacency matrix would look like:

    A B C D E
    
A   0 1 1 0 0
B   1 0 0 1 1
C   1 0 0 0 1
D   0 1 0 0 0
E   0 1 1 0 0


NOTICE: Whenever we consider there to be a path/edge to another vertex, we mark how many edges there are. 

EX: In this case, we say that there is 1 edge between A and B

This is how we keep track of the graphs structure overall with a adjacency matrix

REMEMBER: The Time complexity for an adjacency matrix is O(1) since we only search between a row and column, BUT the space complexity is O(V^2) where V is the number of vertices that we have.

SO the Adjacency Matrix method is very fast when looking up an edge but consumes a lot of memory/resources. This makes the Matrix useful when the graph has a lot of Edges.

IN DEPTH COMPLEXITY FOR OPERATION USING ADJACENCY MATRIX:
 - A find/exist function between two nodes is O(1) - direct acces using indices
 - Adding an edge would be O(1) - update matrix at a specific position
 - Removing an edge would be O(1) - set the matrix entry to 0
 - Iterating through all edges would be O(V^2) - iterate through all entries in the matrix

 ## Traversing through a GRAPH


 