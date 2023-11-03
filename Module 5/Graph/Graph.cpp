#include "Graph.h"

Graph::Graph(int V) {
   this->V = V;
   adjList = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
   adjList[v].push_back(w); // Add w to v’s list.
}

// Iterative function for Breadth First Search
void Graph::BFS(int startV) {
   queue<int> frontierQ;
   vector<int> discovered;
   int current;
   vector<int>::iterator itr;

   visitedV.clear();

   frontierQ.push(startV);
   discovered.push_back(startV);

   while (!frontierQ.empty()) {
      current = frontierQ.front();
      frontierQ.pop();
      visitedV.push_back(current);
      for (auto av : adjList[current]) {
         itr = find(discovered.begin(),discovered.end(), av);
         if (itr == discovered.end()) {
            frontierQ.push(av);
            discovered.push_back(av);
         }
      }
   }
}

// Function to print the adjacency list representation of the graph
void Graph::showAdjList() {
   cout << endl << "Adjacency List" << endl;
   for (int v = 0; v < V; ++v) {
      cout << "Vertex " << v << "->";
      for (auto x : adjList[v]) {
         cout << " " << x;
      }
      cout << endl;
   }
}

// Function to show the vectors visited in the order visited
void Graph::showVisited() {
   cout << endl << "Visited List: " << endl;
   for (auto elem : visitedV) {
      cout << elem << " ";
   }
   cout << endl;
}
