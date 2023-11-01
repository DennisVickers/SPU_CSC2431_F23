#include "NumberSet.h"
#include <iostream>

int main() {
   NumberSet setOne;
   NumberSet setTwo;
   vector<int> subSet;

   // Add numbers to set 1
   setOne.add(5);
   setOne.add(10);
   setOne.add(15);
   setOne.add(20);
   // Print set elements
   cout << "Set One:" << endl;
   setOne.print();

   // Add numbers to set two
   setTwo.add(15);
   setTwo.add(20);
   setTwo.add(25);
   setTwo.add(30);
   // Print set elements
   cout << "Set Two:" << endl;
   setTwo.print();

   // Get the union
   subSet.clear();
   subSet = setOne.getUnion(&setTwo);
   cout << "Union Set:" << endl;
   for (int elem : subSet) {
      cout << elem << " ";
   }
   cout << endl;

   // Get the intersection
   subSet.clear();
   subSet = setOne.getIntersection(&setTwo);
   cout << "Intersection Set:" << endl;
   for (int elem : subSet) {
      cout << elem << " ";
   }
   cout << endl;


   // Get the difference
   subSet.clear();
   subSet = setOne.getDifference(&setTwo);
   cout << "Difference Set:" << endl;
   for (int elem : subSet) {
      cout << elem << " ";
   }
   cout << endl;

   return 0;
}
