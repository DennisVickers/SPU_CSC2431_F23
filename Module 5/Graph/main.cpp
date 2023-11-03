#include "Graph.h"
#include <iostream>

int main() {
   int verticies = 6;
   int startVertex = 0;
   Graph g(verticies); // Create a graph with 4 vertices

//   g.addEdge(0, 1);
//   g.addEdge(0, 2);
//   g.addEdge(1, 2);
//   g.addEdge(2, 0);
//   g.addEdge(2, 3);
//   g.addEdge(3, 3);

   g.addEdge(0,1);
   g.addEdge(0,3);
   g.addEdge(1,0);
   g.addEdge(1,4);
   g.addEdge(1,5);
   g.addEdge(2,5);
   g.addEdge(3,0);
   g.addEdge(4,1);
   g.addEdge(4,5);
   g.addEdge(5,1);
   g.addEdge(5,2);
   g.addEdge(5,4);

   cout << "Depth First Traversal starting from vertex: " << startVertex << endl;

   g.showAdjList();

   g.qDFS(startVertex);

   g.showVisited();

   return 0;
}
