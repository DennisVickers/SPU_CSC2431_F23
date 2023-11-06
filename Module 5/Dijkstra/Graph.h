#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Graph {
private:
   int nV ;    // Number of vertices
   vector<vector<pair<int, int>>> adjList; // Adjacency list as vector of pairs
public:
   Graph(int V);
   void addEdge(int u, int v, int w);
   void dijkstra(int src);
};

#endif //DIJKSTRA_GRAPH_H
