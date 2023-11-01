#include "NumberSet.h"
#include <iostream>

// Constructor
NumberSet::NumberSet() {}

// Destructor (not needed)
NumberSet::~NumberSet() {}

// Adds a number to the set
void NumberSet::add(int num) {
   if (!exists(num)) {
      numbers.push_back(num);
   }
}

// Removes a number from the set
void NumberSet::remove(int num) {
   itr = find(numbers.begin(), numbers.end(), num);
   if (itr != numbers.end()) {
      numbers.erase(itr);
   }
}

// Checks if a number exists in the set
bool NumberSet::exists(int num) {
   bool found;
   itr = find(numbers.begin(), numbers.end(), num);
   found = (itr != numbers.end());
   return found;
}

// Prints the set elements
void NumberSet::print() const {
   cout << "Set elements: ";
   for (int elem : numbers) {
      cout << elem << " ";
   }
   cout << endl;
}

vector<int> NumberSet::getUnion(NumberSet *set2) {
   vector<int> subSet;

   // Add all elements from the first set
   for (int elem : numbers) {
      subSet.push_back(elem);
   }

   // Add all elements from the second set that don't already exist
   for (int elem : set2->numbers) {
      if (!exists(elem)) {
         subSet.push_back(elem);
      }
   }

   return subSet;
}

vector<int> NumberSet::getIntersection(NumberSet *set2) {
   vector<int> subSet;

   for (int elem : numbers) {
      if (set2->exists(elem)) {
         subSet.push_back(elem);
      }
   }

   return subSet;
}


vector<int> NumberSet::getDifference(NumberSet *set2) {
   vector<int> subSet;

   // Add all elements from the first set that aren't in the second
   for (int elem : numbers) {
      if (!set2->exists(elem)) {
         subSet.push_back(elem);
      }
   }

   // Add all elements from the second set that aren't in the first
   for (int elem : set2->numbers) {
      if (!exists(elem)) {
         subSet.push_back(elem);
      }
   }

   return subSet;
}


