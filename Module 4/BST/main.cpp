#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main() {
   BinarySearchTree bst;
   bst.insert(5);
   bst.insert(2);
   bst.insert(8);
   bst.insert(1);
   bst.insert(3);

   cout << "In-order traversal: ";
   bst.showInOrder();

   cout << "Search 3: " << boolalpha << bst.search(3) << endl;
   cout << "Search 9: " << boolalpha << bst.search(9) << endl;

   bst.remove(2);
   cout << "In-order traversal after removing 2: ";
   bst.showInOrder();

   return 0;
}