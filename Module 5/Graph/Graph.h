#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
private:
   int V; // Number of vertices
   vector<int> *adjList; // Pointer to an array containing adjacency lists
   vector<int> visitedV;  // List of vectors visited during a search
public:
   // Constructor
   Graph(int V);
   void addEdge(int v, int w);
   void BFS(int v);
   void showAdjList();
   void showVisited();
};

#endif //GRAPH_GRAPH_H
