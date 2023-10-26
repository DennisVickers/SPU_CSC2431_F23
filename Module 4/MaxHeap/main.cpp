#include "MaxHeap.h"
#include <iostream>
using namespace std;

int main() {
   MaxHeap maxHeap;

   // Add some elements to the heap
   maxHeap.insert(42);
   maxHeap.insert(11);
   maxHeap.insert(35);
   maxHeap.insert(3);
   maxHeap.insert(64);
   maxHeap.insert(22);

   cout << "Max element: " << maxHeap.peekMax() << endl;  // Output should be 64
   cout << "Delete Max: " << maxHeap.deleteMax() << endl;  // Output should be 64
   cout << "Max element after Delete: " << maxHeap.peekMax() << endl;  // Output should be 42

   return 0;
}
