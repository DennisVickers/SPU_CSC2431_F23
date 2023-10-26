#ifndef MAXHEAP_MAXHEAP_H
#define MAXHEAP_MAXHEAP_H

#include "MaxHeap.h"
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeap {
private:
   vector<int> heap;

   // Helper functions
   int parent(int i) { return (i - 1) / 2; };    // Get parent index
   int leftChild(int i) { return 2 * i + 1; };   // Get left child index
   int rightChild(int i) { return 2 * i + 2; };  // Get right child index
   void moveUp(int i);                           // Percolate an index up the heap
   void moveDown(int i);                         // Move an index down the heap
public:
   void insert(int value);    // Add an element on the heap
   int deleteMax();           // Remove and return the maximum element
   int peekMax() const;       // Return the maximum element without removing it
};

#endif //MAXHEAP_MAXHEAP_H
