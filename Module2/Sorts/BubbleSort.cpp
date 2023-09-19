#include <iostream>
#include <vector>
using namespace std;

// Bubble Sort Algorithm
void bubbleSort(vector<int> &list) {
   
   bool swapped;
   int lastOuter;
   int lastInner;

   // Outer loop
   lastOuter = (list.size() - 1);
   lastInner = lastOuter;
   for (int i = 0; i < lastOuter; i++) {
      swapped = false;
      // Inner Loop
      for (int j = 0; j < lastInner; j++) {
         if (list.at(j) > list.at(j + 1)) {
            // Swap elements
            int temp = list.at(j);
            list.at(j) = list.at(j + 1);
            list.at(j + 1) = temp;
            swapped = true;
         }
      }
      // Reduce the search search space
      lastInner--;
      
      // If no two adjacent elements were swapped in inner loop, the listay is sorted
      if (!swapped) {
         break;
      }
   }
}

// Function to print the listay
void printList(const vector<int> &list) {
    for (int num : list) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the bubble sort
int main() {
    vector<int> list = {42, 37, 12, 3, 9};

    cout << "Original list: ";
    printList(list);

    bubbleSort(list);

    cout << "Sorted list: ";
    printList(list);

    return 0;
}
