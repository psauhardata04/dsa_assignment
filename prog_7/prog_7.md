# Dijkstra's Shortest Path

## Program Purpose
Finds shortest distance from starting vertex to all other vertices in weighted graph.

## Graph Setup
Adjacency matrix where graph[i][j] stores edge weight between i and j. Zero means no edge.

## Algorithm Components

**findMin()** - Searches for unprocessed vertex with minimum distance

**dijkstra()** - Main algorithm
- Initializes all distances to infinity except source (0)
- Repeatedly picks minimum distance vertex
- Updates distances to neighbors
- Marks vertex as processed

## How It Works
1. Start with source vertex at distance 0
2. Pick closest unvisited vertex
3. Check all its neighbors
4. If shorter path found through current vertex, update distance
5. Repeat until all vertices processed

## Variables Used
- `distance[]` - stores shortest distance to each vertex
- `processed[]` - tracks which vertices are done
- `INF` - represents infinity for unreachable vertices

## Main Function
Calls dijkstra with starting vertex 0 and prints distance table.

## Program Output
```
Node    Shortest Distance
0       0
1       8
2       9
3       11
4       5
```