#ifndef NUMBERSET_NUMBERSET_H
#define NUMBERSET_NUMBERSET_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class NumberSet {
private:
   vector<int> numbers;        // Dynamic array to store unique numbers
   vector<int>::iterator itr;  // Iterator to use with the vector

public:
   NumberSet();  // Constructor
   ~NumberSet(); // Destructor

   void add(int num);      // Adds a number to the set
   void remove(int num);   // Removes a number from the set
   bool exists(int num);   // Checks if a number exists in the set
   void print() const;     // Prints the set elements
   vector<int> getUnion(NumberSet *set2);
   vector<int> getIntersection(NumberSet *set2);
   vector<int> getDifference(NumberSet *set2);
};


#endif //NUMBERSET_NUMBERSET_H
