#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Function declarations
void createList(vector<int> &list, int listSize=10);
void printList(const vector<int> &list);
void merge(vector<int> &list, int low, int middle, int high);
void mergeSort(vector<int> &list, int low, int high);

int main() {
   
   // Create a random list of integers between 1-100
   vector<int> list;
   createList(list, 5);

   cout << "Original list: ";
   printList(list);

   mergeSort(list, 0, list.size() - 1);

   cout << "Sorted list: ";
   printList(list);

   return 0;
}

// Helper functions

void printList(const vector<int> &list) {
   for (int num : list) {
      cout << num << " ";
   }
   cout << endl;
}

void createList(vector<int> &list, int listSize) {
   srand(time(0));
   for (int i=0; i<listSize; i++) {
      list.push_back((rand() % 100) + 1);
   }
}

// Merge Sort function
void mergeSort(vector<int> &list, int low, int high) {
   int middle;

   // Base case
   if (low >= high) {
      return;
   }

   // Find the middle of the list
   middle = low + ((high - low) / 2);
	
   // Split the list
   mergeSort(list, low, middle);
   mergeSort(list, middle + 1, high);

   // Merge the lists of one back together
   merge(list, low, middle, high);
}

// Function to merge two sorted lists
void merge(vector<int> &list, int low, int middle, int high) {
   // Initialize temporary lists to hold the values of the left and right sub-lists
   vector<int> leftList(middle - low + 1);
   vector<int> rightList(high - middle);

   // Copy the elements to the temporary lists
   for (int i = 0; i < leftList.size(); i++) {
      leftList[i] = list[low + i];
   }
   for (int j = 0; j < rightList.size(); j++) {
      rightList[j] = list[middle + 1 + j];
   }

   // Merge the temporary lists back into the original list
   int i = 0, j = 0, k = low;
   while ((i < leftList.size()) && (j < rightList.size())) {
      if (leftList[i] <= rightList[j]) {
         list[k] = leftList[i];
         i++;
      } else {
         list[k] = rightList[j];
         j++;
      }
      k++;
   }

   // Copy any remaining elements from leftList, if there are any
   while (i < leftList.size()) {
      list[k] = leftList[i];
      i++;
      k++;
   }

   // Copy any remaining elements from rightList, if there are any
   while (j < rightList.size()) {
      list[k] = rightList[j];
      j++;
      k++;
   }
}
