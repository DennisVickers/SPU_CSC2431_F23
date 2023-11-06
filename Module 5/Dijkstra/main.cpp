#include "Graph.h"

int main() {
   Graph g(5); // Example graph with 5 vertices

   // Build the adjacency list
   g.addEdge(0, 1, 10);
   g.addEdge(0, 3, 5);
   g.addEdge(1, 2, 1);
   g.addEdge(2, 4, 4);
   g.addEdge(3, 1, 3);
   g.addEdge(3, 2, 9);
   g.addEdge(3, 4, 2);
   g.addEdge(4, 0, 7);
   g.addEdge(4, 2, 6);

   cout << "Dijkstra's shortest path from vertex 0:" << endl;
   g.dijkstra(0);

   return 0;
}
