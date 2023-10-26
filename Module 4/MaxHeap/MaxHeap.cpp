#include "MaxHeap.h"

void MaxHeap::insert(int value) {
   heap.push_back(value);        // Add the new value to the end of the bottom of the heap
   moveUp(heap.size() - 1);   // Move the new value up the heap starting at the bottom
}

int MaxHeap::deleteMax() {
   if (heap.empty()) {
      throw out_of_range("Heap is empty");
   }

   int result = heap[0];   // Keep the root value

   heap[0] = heap.back();  // replace the root value with the last value
   heap.pop_back();        // Remove the last element (just moved to root)

   moveDown(0);         // Move the root value down the heap

   return result;
}

int MaxHeap::peekMax() const {
   if (heap.empty()) {
      throw out_of_range("Heap is empty");
   }

   return heap[0];
}

void MaxHeap::moveUp(int i) {
   while (i > 0 && heap[parent(i)] < heap[i]) {
      swap(heap[parent(i)], heap[i]);
      i = parent(i);
   }
}

void MaxHeap::moveDown(int i) {
   int maxIndex = i;
   int left = leftChild(i);
   int right = rightChild(i);

   if (left < heap.size()) {
      if (heap[left] > heap[maxIndex]) {
         maxIndex = left;
      }
   }

   if (right < heap.size()) {
      if (heap[right] > heap[maxIndex]) {
         maxIndex = right;
      }
   }

   if (i != maxIndex) {
      swap(heap[i], heap[maxIndex]);
      moveDown(maxIndex);
   }
}
