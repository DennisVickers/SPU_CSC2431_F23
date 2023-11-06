#include "Graph.h"

Graph::Graph(int v) : nV(v), adjList(v) {};

void Graph::addEdge(int u, int v, int w) {
   adjList.at(u).push_back(make_pair(v, w));
}

void Graph::dijkstra(int src) {
   // Min-heap using priority queue
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

   // Distances array filled with infinite values
   vector<int> dist(nV, numeric_limits<int>::max());
   vector<int> predV(nV, -1);

   // Start with the source vertex
   minHeap.push(make_pair(0, src));
   dist.at(src) = 0;

   while (!minHeap.empty()) {
      int u = minHeap.top().second; // Vertex u with the shortest distance
      minHeap.pop();

      // Look at neighbours of u
      for (const auto &i : adjList.at(u)) {
         int v = i.first;
         int weight = i.second;

         // If there is a shorter path to v through u
         if (dist.at(v) > dist.at(u) + weight) {
            dist.at(v) = dist.at(u) + weight;
            predV.at(v) = u;
            minHeap.push(make_pair(dist.at(v), v));
         }
      }
   }

   for (int i = 0; i < nV; i++) {
      cout << "Vertex " << i;
      cout << ": Distance = " << dist.at(i);
      if (predV.at(i) >= -1) {
         cout << ", Path: " << i;
         int next = predV.at(i);
         while (next != -1) {
            cout << "<-" << next;
            next = predV.at(next);
         }
         cout << endl;
      }
   }
}

